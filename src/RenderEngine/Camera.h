#pragma once
#include <glm/glm.hpp>
#include <glm/matrix.hpp>

namespace RenderEngine 
{
    class camera
    {
        public:
        camera();

        float fov;
        glm::vec3 lookVec;
        glm::vec3 position;
        glm::vec3 up;

        void getViewMatrix(glm::mat4& viewMat);

    };
}