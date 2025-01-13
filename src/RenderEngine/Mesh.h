#pragma once
#include <GLFW/glfw3.h>
#include "GLBuffer.h"
#include "VertexArray.h"
#include <stdint.h>
#include <vector>
#include "Shader.h"
#include "Camera.h"
#include "texture2D.h"

namespace RenderEngine
{
    class mesh
    {
    public:
        mesh(const mesh&) = delete;
        mesh& operator=(const mesh&) = delete;

        mesh();
        ~mesh();

        glm::vec3 scale;
        glm::vec3 position;
        //Axis swap compared to blender
        //      This program
        //Z+ -> Y+  
        //Y+ -> Z-
        //X+ -> X+


        glm::vec3 eulerRotation;

        void render(camera& camObj, Shader& shaderObj, GLFWwindow* window);
        void addTexture(std::string path, std::string uniformName);
        uint32_t getVerticesCount();
        bool updateDataBuffer(std::vector<float> vbo, std::vector<uint32_t> ebo);
        VAO vao;
    private:
        
        std::vector<std::pair<texture2D*, std::string>>textureArray;
        GLBuffer vbo;
        GLBuffer ebo;
        uint32_t verticesCount;
    };
}