#include "Mesh.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

namespace RenderEngine
{
    mesh::mesh()
    : vbo(GL_ARRAY_BUFFER), ebo(GL_ELEMENT_ARRAY_BUFFER), vao(vbo, ebo), verticesCount(0), eulerRotation(0,0,0), scale(1,1,1), position(0,0,0)
    {
        vao.vertexAddAttrib(3, 3*sizeof(float), GL_FLOAT, false, 8*sizeof(float)); // Position
        vao.vertexAddAttrib(3, 3*sizeof(float), GL_FLOAT, false, 8*sizeof(float)); // Normal
        vao.vertexAddAttrib(2, 2*sizeof(float), GL_FLOAT, false, 8*sizeof(float)); // UV
    }

    mesh::~mesh()
    {
        
    }

    void mesh::render(camera& camObj, Shader& shaderObj, GLFWwindow* window)
    {
        int width, height;
        glfwGetWindowSize(window, &width, &height);

        eulerRotation.y = sin(glfwGetTime())*260;

        glm::mat4 projection;
        projection = glm::perspective(glm::radians(camObj.fov), (float)width / (float)height, 0.1f, 100.0f);

        glm::mat4 model = glm::mat4(1.0f);
        model = glm::scale(model, scale);
        //XYZ EULER
        model = glm::rotate(model, glm::radians((float)eulerRotation.x), glm::vec3(1,0,0)); //rotate X
        model = glm::rotate(model, glm::radians((float)eulerRotation.y), glm::vec3(0,1,0)); //rotate Y
        model = glm::rotate(model, glm::radians((float)eulerRotation.z), glm::vec3(0,0,1)); //rotate Z
        //
        model = glm::translate(model, position);
        //model = glm::rotate(model, glm::radians((float)std::sin(glfwGetTime())*200), glm::vec3(2.0f, 0.0f, 1.0f)); 

        glm::mat4 view;
        camObj.getViewMatrix(view);

        shaderObj.set4fMat("vertex_model_matrix", false, glm::value_ptr(model));
        shaderObj.set4fMat("vertex_view_matrix", false, glm::value_ptr(view));
        shaderObj.set4fMat("vertex_projection_matrix", false, glm::value_ptr(projection));

        vao.bind();
        shaderObj.bind();

        for (int i=0;i<textureArray.size();i++)
        {
            textureArray[i].first->bind(i);
            shaderObj.set1Int(textureArray[i].second, i);

        }
        
        glDrawElements(GL_TRIANGLES, verticesCount, GL_UNSIGNED_INT, 0);
    }

    void mesh::addTexture(std::string path, std::string uniformName)
    {
        if (textureArray.size()<16)
        {
            texture2D* text = new texture2D(path);
            textureArray.push_back(std::pair<texture2D*, std::string>(text, uniformName));
        }
    }

    uint32_t mesh::getVerticesCount()
    {
        return verticesCount;
    }

    bool mesh::updateDataBuffer(std::vector<float> vecVBO, std::vector<uint32_t> vecEBO)
    {
        if (vecVBO.size()%8!=0)
        {
            std::cout<<"Invalid mesh data, VBO INVALID\n";
            return false;
        }
        if (vecEBO.size()%3!=0)
        {
            std::cout<<"Invalid mesh data, EBO INVALID\n";
            return false;
        }
        verticesCount = vecEBO.size();
        vbo.BufferData(vecVBO.size()*sizeof(float), (void*)&vecVBO[0], GL_STATIC_DRAW);
        ebo.BufferData(vecEBO.size()*sizeof(float), (void*)&vecEBO[0], GL_STATIC_DRAW);
        return true;
    }
}