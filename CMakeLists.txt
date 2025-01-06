cmake_minimum_required(VERSION 3.5.0)
project(openglProject VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(GLFW lib/glfw/include/GLFW/glfw3.h)
set(GLAD lib/glad/src/glad.c lib/glad/include/glad/glad.h)
set(sources src/main.cpp
            src/RenderEngine/RenderEngine.cpp
            src/RenderEngine/GLBuffer.cpp
            src/RenderEngine/Shader.cpp
            src/RenderEngine/VertexArray.cpp
            src/RenderEngine/stb_image.cpp
            src/RenderEngine/texture2D.cpp
            src/RenderEngine/OBJLoader.cpp
            src/RenderEngine/Mesh.cpp
            src/RenderEngine/Camera.cpp
            src/RenderEngine/MoveController.cpp)

add_subdirectory(lib/glfw)

include_directories(lib/glad/include)
include_directories(lib/stb_image)
include_directories(lib/glfw/include)
include_directories(lib/glfw/deps/glad)
include_directories(lib/glm-master/)


add_executable(openglProject ${sources} ${GLAD} ${GLFW})


target_link_libraries(openglProject glfw GL X11 pthread)