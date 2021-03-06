#version 150

uniform sampler2D BlendTex;


in vec2 vTexCoord;
out vec4 oColor;

void main()
{
	oColor = texture2D(BlendTex, vTexCoord);
	// for occlusion query
	if (oColor.a == 0) discard;
}