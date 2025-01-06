#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
namespace RenderEngine
{
    camera::camera()
    : position(0,0,0), lookVec(1,0,0), up(0,1,0), fov(90)
    {

    }

    void camera::getViewMatrix(glm::mat4 &viewMat)
    {
        glm::vec3 lookDir = glm::normalize(lookVec);
        glm::vec3 target = lookDir + position;
        
        viewMat = glm::lookAt(position, target, up);
    }
}