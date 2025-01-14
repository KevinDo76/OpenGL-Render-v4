#pragma once
#include <string>
#include <stdint.h>
namespace RenderEngine
{
    class texture2D
    {
    public:
        texture2D(const texture2D&) = delete;
        texture2D& operator=(const texture2D&) = delete;

        texture2D(std::string texturePath);
        ~texture2D();

        void bind(uint32_t textureUnitIndex);
        void unbind();
    private:
        uint32_t textureID;
    };
}