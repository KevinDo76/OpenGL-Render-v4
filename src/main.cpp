#include <GLFW/glfw3.h>
#include "RenderEngine/RenderEngine.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
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

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);

    //char* GL_renderer = (char*)glGetString(GL_RENDERER);
    ImGui_ImplOpenGL3_Init();



    RenderEngine::MoveController movementController;
    RenderEngine::camera cameraObj;
    RenderEngine::mesh teapotMesh;
    RenderEngine::mesh box;
    RenderEngine::mesh axis;

    axis.addTexture("../src/textures/axis.png", "texture0");
    axis.scale = glm::vec3(1,1,1);

    box.addTexture("../src/textures/image.png", "texture0");
    teapotMesh.addTexture("../src/textures/image.png", "texture0");
    
    box.position = glm::vec3(0,10,0);

    RenderEngine::loadOBJ("../src/textures/3Axis.obj", axis);
    RenderEngine::loadOBJ("../src/textures/teapot.obj", teapotMesh);
    RenderEngine::loadOBJ("../src/textures/box.obj", box);

    RenderEngine::setViewPort(window);


    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


    RenderEngine::Shader shaderObj("../src/shaders/mainShader.vert","../src/shaders/mainShader.frag");
    shaderObj.unbind();
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); 

    auto last = std::chrono::high_resolution_clock::now();

    


    while(!glfwWindowShouldClose(window))
    {

        double deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - last).count()/1000.0;
        last = std::chrono::high_resolution_clock::now();
        

        box.position.x = 10;
        box.eulerRotation.x = (sin(glfwGetTime())+1) * 10;




        movementController.processFirstPerson(window, cameraObj, deltaTime);
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        axis.render(cameraObj, shaderObj, window);
        box.render(cameraObj, shaderObj, window);
        //teapotMesh.render(cameraObj, shaderObj, window);

       
        glfwSwapBuffers(window);
        glfwPollEvents();    
        

    }

    glfwTerminate();
    return 0;
}
