/////////////////////////////////////////////////////////
//Pixel Shader
/////////////////////////////////////////////////////////


/////////////////////
// INPUT VARIABLES //
/////////////////////

uniform sampler2D aguatext;





void main(void)
{
	vec4 textureColor;
	vec3 bump;
	vec3 NewNormal;
	vec3 normalaza;
	vec3 lightDir;
	float lightIntensity

	//Obtener la textur difusa o de color
	textureColor = texture(aguatext,texCoord);


	//Multiplica la textura color final.
	if(textureColor.a < 0.5)
	discard;

// outputColor = outoutColor * textureColor + 0.1;
	outputColor = textureColor;

}