#pragma once

#include <string>
#include "GLBuffer.h"
#include "Shader.h"
#include "VertexArray.h"
#include "texture2D.h"
#include "OBJLoader.h"
#include "Mesh.h"
#include "Camera.h"
#include "MoveController.h"

namespace RenderEngine
{
    bool renderEngineInit();
    bool initGlad();
    bool createWindow(GLFWwindow** window, std::string windowTitle);
    bool setViewPort(GLFWwindow* window);

    bool readFile(std::string filePath, std::string& result);
}