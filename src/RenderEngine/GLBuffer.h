#pragma once
#include <stdint.h>
#include <GLFW/glfw3.h>
namespace RenderEngine 
{
    class GLBuffer
    {
    public:
        GLBuffer(const GLBuffer&) = delete;
        GLBuffer(GLenum bufferType);
        ~GLBuffer();

        GLBuffer& operator=(const GLBuffer&) = delete;

        void BufferData(size_t size, void* vertices, GLenum DataType);
        void bind();
        void unbind();

    private:
        uint32_t bufferID;
        GLenum bufferType;
    };
}