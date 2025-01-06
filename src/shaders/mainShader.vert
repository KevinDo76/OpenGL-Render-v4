#version 460 core
layout (location = 0) in vec3 vertex_position;
layout (location = 1) in vec3 vertex_normal;
layout (location = 2) in vec2 vertex_UV;

out vec2 frag_UV;

uniform mat4 vertex_model_matrix;
uniform mat4 vertex_view_matrix;
uniform mat4 vertex_projection_matrix;

void main()
{
    gl_Position = vertex_projection_matrix * vertex_view_matrix * vertex_model_matrix * vec4(vertex_position, 1.0);
    frag_UV=vertex_UV;
    //pixColor = (vec4(aPos, 1.0)).xyz;
}