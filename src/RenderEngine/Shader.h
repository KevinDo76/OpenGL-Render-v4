#pragma once
#include <string>
#include <stdint.h>
namespace RenderEngine{
    class Shader{
    public:
        /// @brief Load code and create a shader program
        /// @param vertexPath 
        /// @param fragmentPath 

        Shader(const Shader&) = delete;
        Shader(std::string vertexPath, std::string fragmentPath);
        ~Shader();
        Shader& operator= (const Shader&) = delete;

        void bind();
        void unbind();
        void setBool(const std::string &name, bool value);  
        void set1Int(const std::string &name, int value);   
        void set1Float(const std::string &name, float value);
        void set4Float(const std::string &name, float v1, float v2, float v3, float v4);
        void set4fMat(const std::string &name, bool tranpose, float* values);
    private:
        uint32_t programID;
    };
}