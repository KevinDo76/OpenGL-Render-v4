#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "Shader.h"
#include "RenderEngine.h"
#include <iostream>

namespace RenderEngine
{
    Shader::Shader(std::string vertexPath, std::string fragmentPath)
    {
        //Read in shader sources
        std::string vertexSource;
        std::string fragmentSource;
        RenderEngine::readFile(vertexPath, vertexSource);
        RenderEngine::readFile(fragmentPath, fragmentSource);

        const char* vertexSourceCString = vertexSource.c_str();
        const char* fragmentSourceCString = fragmentSource.c_str();

        //create and compile vertex shader
        uint32_t vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexSourceCString, NULL);
        glCompileShader(vertexShader);

        //create and compile fragment shader
        uint32_t fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentSourceCString, NULL);
        glCompileShader(fragmentShader);

        //check error for vertex shader
        int  success;
        char infoLog[512];

        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "Failure to compile vertex shader: " << infoLog << std::endl;
        } 
        else 
        {
            std::cout << "Compiled vertex shader: " << vertexPath << "\n";
        }

        //check error for fragment shader
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cout << "Failure to compile fragment shader: " << infoLog << std::endl;
        }
        else 
        {
            std::cout << "Compiled fragment shader: " << fragmentPath << "\n";
        }

        //Attach and link vertex and fragment shaders
        programID = glCreateProgram();
        glAttachShader(programID, vertexShader);
        glAttachShader(programID, fragmentShader);
        glLinkProgram(programID);

        //check error for program linking
        glGetProgramiv(programID, GL_LINK_STATUS, &success);    
        if(!success) {
            glGetProgramInfoLog(programID, 512, NULL, infoLog);
            std::cout << "Failure to attach and link vertex and fragment shader: " << infoLog << std::endl;
        } 
        else 
        {
            std::cout << "Attach and linked shaders, ID: "<<programID<<"\n";
        }


        //Cleanup
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);  


    }

    Shader::~Shader()
    {
        glDeleteProgram(programID);
    }

    void Shader::bind()
    {
        glUseProgram(programID);
    }

    void Shader::unbind()
    {
        glUseProgram(0);
    }
    void Shader::setBool(const std::string &name, bool value) 
    {
        bind();
        glUniform1i(glGetUniformLocation(programID, name.c_str()), (int)value); 
    }
    void Shader::set1Int(const std::string &name, int value) 
    {
        bind();
        glUniform1i(glGetUniformLocation(programID, name.c_str()), value);
    }
    void Shader::set1Float(const std::string &name, float value) 
    {
        bind();
        glUniform1f(glGetUniformLocation(programID, name.c_str()), value);
    }
    void Shader::set4Float(const std::string &name, float v1, float v2, float v3, float v4)
    {
        bind();
        glUniform4f(glGetUniformLocation(programID, name.c_str()), v1, v2, v3, v4);
    }

    void Shader::set4fMat(const std::string &name, bool tranpose, float* values)
    {
        bind();
        glUniformMatrix4fv(glGetUniformLocation(programID, name.c_str()), 1, tranpose, values);
    }
}