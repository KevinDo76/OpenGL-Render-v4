#pragma once
#include <stdint.h>
#include "GLBuffer.h"
namespace RenderEngine
{
    class VAO
    {
    public:
        VAO(const VAO&) = delete;
        VAO& operator= (const VAO&) = delete;

        VAO(GLBuffer& VBOToAttach, GLBuffer& EBOToAttach);
        ~VAO();

        
        void vertexAddAttrib(uint32_t attribSize, uint32_t attribSizeBytes ,GLenum dataType, bool normalized, uint32_t stride);
        void bind();
        void unbind();
    private:
        uint32_t vertArrayID;
        uint32_t attribIndex;
        uint64_t offsetCount;
        GLBuffer* bindedVBO;
        GLBuffer* bindedEBO;
    };
}