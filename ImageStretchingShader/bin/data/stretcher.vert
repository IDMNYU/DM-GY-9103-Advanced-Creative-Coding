#version 150
uniform mat4 modelViewProjectionMatrix;
uniform vec2 stretch;
in vec4 pos;
in vec2 texcoord;
out vec2 texCoordVarying;

void main(){
	texCoordVarying = vec2(texcoord.xy*stretch);
	gl_Position = modelViewProjectionMatrix * pos;
}