/////////////////////////////////////////////////////////
//Vertex Shader
/////////////////////////////////////////////////////////


/////////////////////
// INPUT VARIABLES //
/////////////////////




//////////////////////
// OUTPUT VARIABLES //
//////////////////////
out vec2 texCoord;



///////////////////////
// UNIFORM VARIABLES //
///////////////////////
uniform mat4 worldMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;









void main(void)
{
	//Calculate the position of the vertex against the world, view, and projection matrices.
	gl_Position = worldMatrix * vec4(posicion, 1.0f);
	gl_Position = viewMatrix * gl_Position;
	gl_Position = projectionMatrix * gl_Position;

	// Store the texture coordinates for the pixel shader.
	texCoord = inputTexCoord;

}