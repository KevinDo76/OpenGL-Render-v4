#include "texture2D.h"
#include <glad/glad.h>
#include <stb_image.h>
#include <iostream>
namespace RenderEngine
{
    texture2D::texture2D(std::string path)
    {
        glGenTextures(1, &textureID);
        glBindTexture(GL_TEXTURE_2D, textureID);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int width, height, nrChannels;
        stbi_set_flip_vertically_on_load(true);
        unsigned char *data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
            std::cout<<"Loaded texture: \""<<path<<"\"\n";
        }
        else
        {
            std::cout << "Failed to load texture: \""<<path<<"\"\n";
        }
        stbi_image_free(data);
        unbind();
    }

    texture2D::~texture2D()
    {
        glDeleteTextures(1, &textureID);
    }

    void texture2D::bind(uint32_t textureUnitIndex)
    {
        glActiveTexture(GL_TEXTURE0+textureUnitIndex);
        glBindTexture(GL_TEXTURE_2D, textureID);
    }
    void texture2D::unbind()
    {
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}