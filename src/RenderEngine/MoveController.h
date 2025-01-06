#pragma once
#include "Camera.h"
#include <GLFW/glfw3.h>
namespace RenderEngine
{
    class MoveController
    {
        public:

        float lastX;
        float lastY;
        float yaw;
        float pitch;
        bool mouseCaptured;
        float sensitivity;

        MoveController();
        void processFirstPerson(GLFWwindow* window, camera& camObj, float deltaTime);
    };
    
}