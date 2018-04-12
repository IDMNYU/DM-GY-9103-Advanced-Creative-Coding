#version 150

uniform sampler2DRect tex0;
uniform float u_time;

in vec2 texCoordVarying;
out vec4 outputColor;

void main()
{
	vec4 color = vec4(1.0,abs(sin(u_time)),1.0,1.0);
    vec4 rTxt = texture(tex0, texCoordVarying);
    vec4 mixed = mix(rTxt, color, 0.2);
    outputColor = mixed;
}