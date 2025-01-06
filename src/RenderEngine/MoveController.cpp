#include "MoveController.h"
#include <iostream>
#include "Camera.h"
#include <GLFW/glfw3.h>

namespace RenderEngine
{
    void MoveController::processFirstPerson(GLFWwindow* window, camera& camObj, float deltaTime)
    {
        double xpos, ypos;
        int width, height;
        glfwGetWindowSize(window, &width, &height);
        glfwGetCursorPos(window, &xpos, &ypos);
        //glfwSetCursorPos(window, width / 2, height / 2);
        
        float offx = xpos - lastX;
        float offy = ypos - lastY;

        lastX = xpos;
        lastY = ypos;
        if (glfwGetWindowAttrib(window, GLFW_FOCUSED) && glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
            mouseCaptured = true;

        if (glfwGetWindowAttrib(window, GLFW_FOCUSED) && mouseCaptured)
        {
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            float rotX = (float)((float)xpos - (width / 2)) / width;
            float rotY = (float)((float)ypos - (height / 2)) / height;

            yaw+=offx*sensitivity;
            pitch-=offy*sensitivity;

            if (pitch > 89.9f)
                pitch = 89.9f;
            if (pitch < -89.9f)
                pitch = -89.9f;
            if (yaw>359.9f)
                yaw = 0;
            if (yaw<0)
                yaw = 359.9f;
            


            glm::vec3 front;
            front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
            front.y = sin(glm::radians(pitch));
            front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
            camObj.lookVec = glm::normalize(front);
        } 
        else 
        {
            mouseCaptured = false;
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        }


        if (glfwGetKey(window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS)
        {
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);  
            mouseCaptured = false;
        }

        const float cameraSpeed = 1; // adjust accordingly
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            camObj.position += glm::normalize(camObj.lookVec) * cameraSpeed * deltaTime;
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
            camObj.position -= glm::normalize(camObj.lookVec) * cameraSpeed * deltaTime;
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            camObj.position -= glm::normalize(glm::cross(glm::normalize(camObj.lookVec), camObj.up)) * cameraSpeed * deltaTime;
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            camObj.position += glm::normalize(glm::cross(glm::normalize(camObj.lookVec), camObj.up)) * cameraSpeed * deltaTime;
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
            camObj.position += glm::normalize(camObj.up)*cameraSpeed*deltaTime;
        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
            camObj.position -= glm::normalize(camObj.up)*cameraSpeed*deltaTime;
    }
    MoveController::MoveController()
    :   lastX(0), lastY(0), yaw(0), pitch(0), mouseCaptured(true), sensitivity(0.25)
    {

    }
}