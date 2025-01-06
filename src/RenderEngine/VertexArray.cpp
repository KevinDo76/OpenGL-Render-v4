#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "VertexArray.h"
#include "GLBuffer.h"
namespace RenderEngine
{
    VAO::VAO(GLBuffer &VBOToAttach, GLBuffer &EBOToAttach)
    : offsetCount(0), attribIndex(0), bindedVBO(&VBOToAttach), bindedEBO(&EBOToAttach)
    {
        glGenVertexArrays(1, &vertArrayID);
    }

    VAO::~VAO()
    {
        glDeleteVertexArrays(1, &vertArrayID);
    }

    void VAO::vertexAddAttrib(uint32_t attribSize, uint32_t attribSizeBytes, GLenum dataType, bool normalized, uint32_t stride)
    {
        bind();
        bindedVBO->bind();
        bindedEBO->bind();
        glVertexAttribPointer(attribIndex, attribSize, dataType, normalized, stride, (void*)offsetCount);
        glEnableVertexAttribArray(attribIndex); 
        attribIndex++;
        offsetCount+=attribSizeBytes;
        unbind();

    }

    void VAO::bind()
    {
        glBindVertexArray(vertArrayID);
    }

    void VAO::unbind()
    {
        glBindVertexArray(0);
    }
}
