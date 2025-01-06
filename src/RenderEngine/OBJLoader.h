#pragma once
#include <string>
#include "GLBuffer.h"
#include "Mesh.h"
namespace RenderEngine
{
    bool loadOBJ(std::string path, mesh& meshObj);
}