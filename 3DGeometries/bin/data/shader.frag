#version 150

uniform sampler2DRect tex0;
uniform sampler2DRect tex1;

uniform float u_time;

in vec2 texCoordVarying;
out vec4 outputColor;

void main()
{
    vec4 rTxt = texture(tex0, texCoordVarying);
    vec4 lTxt = texture(tex1, texCoordVarying);
    vec4 mixed = mix(lTxt, rTxt, abs(sin(u_time)));
    outputColor = mixed;
}