#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "GLBuffer.h"


namespace RenderEngine
{

    GLBuffer::GLBuffer(GLenum _bufferType)
    : bufferType(_bufferType)
    {
        glGenBuffers(1, &bufferID);  
    }

    GLBuffer::~GLBuffer()
    {
        glDeleteBuffers(1, &bufferID);
    }

    void GLBuffer::BufferData(size_t size, void* vertices, GLenum DataType)
    {
        bind();
        glBufferData(bufferType, size, vertices, DataType);
    }

    void GLBuffer::bind()
    {
        glBindBuffer(bufferType, bufferID);
    }

    void GLBuffer::unbind()
    {
        glBindBuffer(bufferType, 0);
    }
}