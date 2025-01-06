#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "GLBuffer.h"
#include <iostream>
#include <fstream>

static void GLFWErrorCallback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void framebufferResizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    std::cout<<"Viewport resized: "<<width<<" "<<height<<"\n";
}  


//https://gist.github.com/liam-middlebrook/c52b069e4be2d87a6d2f
void APIENTRY GLDebugMessageCallback(GLenum source, GLenum type, GLuint id,
                            GLenum severity, GLsizei length,
                            const GLchar *msg, const void *data)
{
    char* _source;
    char* _type;
    char* _severity;

    switch (source) {
        case GL_DEBUG_SOURCE_API:
        _source = "API";
        break;

        case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
        _source = "WINDOW SYSTEM";
        break;

        case GL_DEBUG_SOURCE_SHADER_COMPILER:
        _source = "SHADER COMPILER";
        break;

        case GL_DEBUG_SOURCE_THIRD_PARTY:
        _source = "THIRD PARTY";
        break;

        case GL_DEBUG_SOURCE_APPLICATION:
        _source = "APPLICATION";
        break;

        case GL_DEBUG_SOURCE_OTHER:
        _source = "UNKNOWN";
        break;

        default:
        _source = "UNKNOWN";
        break;
    }

    switch (type) {
        case GL_DEBUG_TYPE_ERROR:
        _type = "ERROR";
        break;

        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        _type = "DEPRECATED BEHAVIOR";
        break;

        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
        _type = "UDEFINED BEHAVIOR";
        break;

        case GL_DEBUG_TYPE_PORTABILITY:
        _type = "PORTABILITY";
        break;

        case GL_DEBUG_TYPE_PERFORMANCE:
        _type = "PERFORMANCE";
        break;

        case GL_DEBUG_TYPE_OTHER:
        _type = "OTHER";
        break;

        case GL_DEBUG_TYPE_MARKER:
        _type = "MARKER";
        break;

        default:
        _type = "UNKNOWN";
        break;
    }

    switch (severity) {
        case GL_DEBUG_SEVERITY_HIGH:
        _severity = "HIGH";
        break;

        case GL_DEBUG_SEVERITY_MEDIUM:
        _severity = "MEDIUM";
        break;

        case GL_DEBUG_SEVERITY_LOW:
        _severity = "LOW";
        break;

        case GL_DEBUG_SEVERITY_NOTIFICATION:
        _severity = "NOTIFICATION";
        break;

        default:
        _severity = "UNKNOWN";
        break;
    }

    if (_severity!="NOTIFICATION")
    {
        printf("%d: %s of %s severity, raised from %s: %s\n",
            id, _type, _severity, _source, msg);
    }
    return ;
}

namespace RenderEngine
{
    bool renderEngineInit()
    {

        glfwSetErrorCallback(GLFWErrorCallback);

        if (!glfwInit())
        {
            std::cout<<"Failed to initilize GLFW\n";
            return false;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        return true;
    }

    bool initGlad()
    {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD\n";
            return false;
        }  
        glEnable(GL_DEPTH_TEST);  
        glEnable              ( GL_DEBUG_OUTPUT );
        glDebugMessageCallback( GLDebugMessageCallback, 0 );

        return true;
    }

    bool createWindow(GLFWwindow **window, std::string windowTitle)
    {
        GLFWwindow* windowInstance = glfwCreateWindow(640, 480, windowTitle.c_str(), NULL, NULL);

        if (!window)
        {
            std::cout<<"Failed to initilize glfw window\n";
            return false;
        }

        glfwMakeContextCurrent(windowInstance);
        *window = windowInstance;

        return true;
    }


    bool setViewPort(GLFWwindow *window)
    {
        glfwSetFramebufferSizeCallback(window, framebufferResizeCallback); 
        glViewport(0, 0, 640, 480);
        return true;
    }


    bool readFile(std::string filePath, std::string &result)
    {
        std::ifstream file(filePath);
        std::string line;
        result = "";

        if (!file.is_open())
        {
            std::cout<<"Failed to read file \""<<filePath<<"\"\n";
            return false;
        }
        
        while (std::getline(file, line))
        {
            result += line + "\n";
        }
        return true;
    }
}