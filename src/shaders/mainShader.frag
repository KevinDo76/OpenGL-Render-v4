
#version 460 core
out vec4 FragColor;
  
in vec2 frag_UV;
in vec3 frag_normal;
in vec3 frag_position;

uniform sampler2D texture0;

void main()
{  
    vec3 lightColor = vec3(1,1,1);
    vec3 lightPosition = vec3(0,20,0);
    vec3 lightDir = normalize(lightPosition - frag_position);  

    float ambientStrength = 0.1;
    float diff = max(dot(frag_normal, lightDir), 0.0);

    vec4 diffuse = vec4(diff * lightColor,1);
    vec4 ambient = vec4(lightColor * ambientStrength,1);

    FragColor = (ambient + diffuse) * texture(texture0, frag_UV);
}

