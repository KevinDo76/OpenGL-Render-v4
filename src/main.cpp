#include <GLFW/glfw3.h>
#include "RenderEngine/RenderEngine.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
int main()
{
    GLFWwindow* window;  

    if (!RenderEngine::renderEngineInit())
    {
        glfwTerminate();
        return 0;
    }
    
    if (!RenderEngine::createWindow(&window, "OPENGL TEST"))
    {
        glfwTerminate();
        return 0;
    }

    if (!RenderEngine::initGlad())
    {
        glfwTerminate();
        return 0;
    }
    RenderEngine::MoveController movementController;
    RenderEngine::camera cameraObj;
    RenderEngine::mesh teapotMesh;
    RenderEngine::mesh box;
    box.addTexture("../src/textures/image.png", "texture0");
    teapotMesh.addTexture("../src/textures/image.png", "texture0");
    
    RenderEngine::loadOBJ("../src/textures/teapot.obj", teapotMesh);
    RenderEngine::loadOBJ("../src/textures/box.obj", box);

    RenderEngine::setViewPort(window);


    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


    RenderEngine::Shader shaderObj("../src/shaders/mainShader.vert","../src/shaders/mainShader.frag");
    shaderObj.unbind();
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); 

    while(!glfwWindowShouldClose(window))
    {
     
        const float radius = 10.0f;


        movementController.processFirstPerson(window, cameraObj, 0.16);
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        //box.render(cameraObj, shaderObj, window);
        teapotMesh.render(cameraObj, shaderObj, window);
    

        glfwSwapBuffers(window);
        glfwPollEvents();    
    }

    glfwTerminate();
    return 0;
}
