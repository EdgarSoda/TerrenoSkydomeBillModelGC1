////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.cpp
// AQUI SE SUBEN LOS MODELOS
////////////////////////////////////////////////////////////////////////////////
#include "graphicsclass.h"


GraphicsClass::GraphicsClass()
{
	m_OpenGL = 0;
	m_Camera = 0;
	m_LightShader = 0;
	m_LightShaderSky = 0;
	m_BillShader = 0;
	m_Light = 0;
	angx = angy = angz = 0;
}


GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}


GraphicsClass::~GraphicsClass()
{
}


bool GraphicsClass::Initialize(OpenGLClass* OpenGL, HWND hwnd)
{
	bool result;


	// Store a pointer to the OpenGL class object.
	m_OpenGL = OpenGL;

	// Create the camera object.
	m_Camera = new CameraClass;
	if(!m_Camera)
	{
		return false;
	}

	// Set the initial position of the camera.
	m_Camera->SetPosition(0.0f, 0.0f, 110.0f);


	//Hacemos un arreglo:
	const wchar_t* texturas[] = { {L"Zacatito.jpg"},{L"ZacatitoNorm2.jpg"},
	{L"texterr2.jpg"},{L"texterr2Norm.jpg"},{L"lodotext.jpg"},{L"lodotextNorm.jpg"},
	{L"mezcla.jpg"} };
	int num_texts[] = {10,11,12,13,14,15,16};

	terreno = new Terreno(hwnd, m_OpenGL, L"terrenonuevo7.jpg", texturas,
		(float)400, (float)400, num_texts);

	//Creamos el shader del skydome
	// Create the light shader object.
	m_LightShader = new LightShaderClass((char*)"light.vs", (char*)"light.ps");
	if(!m_LightShader)
	{
		return false;
	}

	// Initialize the light shader object.
	result = m_LightShader->Initialize(m_OpenGL, hwnd);
	if(!result)
	{
		MessageBox(hwnd, (LPCSTR)"Could not initialize the light shader object.", (LPCSTR)"Error", MB_OK);
		return false;
	}

	// Create the light object.
	m_Light = new LightClass;
	if(!m_Light)
	{
		return false;
	}

	// Initialize the light object.
	m_Light->SetDiffuseColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_Light->SetDirection(-5.0f, 0.5f, -1.0f);

	sky = new SkyDome(hwnd, m_OpenGL, 32, 32, 256, L"earth5.jpg");
	// Create the light shader object.
	m_LightShaderSky = new LightShaderClass((char*)"Sky.vs", (char*)"Sky.ps");
	if (!m_LightShaderSky)
	{
		return false;
	}

	// Initialize the light shader object.
	result = m_LightShaderSky->Initialize(m_OpenGL, hwnd);
	if (!result)
	{
		MessageBox(hwnd, (LPCSTR)"Could not initialize the light shader object.", (LPCSTR)"Error", MB_OK);
		return false;
	}

	bill = new Billboard(hwnd, m_OpenGL, L"arbol.png", 10.0f, 25.0f, 110.0f);
	// Create the light shader object.
	m_BillShader = new LightShaderClass((char*)"Bill.vs", (char*)"Bill.ps");
	if (!m_BillShader)
	{
		return false;
	}

	// Initialize the light shader object.
	result = m_BillShader->Initialize(m_OpenGL, hwnd);
	if (!result)
	{
		MessageBox(hwnd, (LPCSTR)"Could not initialize the light shader object.", (LPCSTR)"Error", MB_OK);
		return false;
	}


	//CARGANDO LOS MODELOS:

	//CASA PRINCIPAL:
	modelazo = new Modelos(hwnd, m_OpenGL, "casaprincipal_1.obj", L"casaprincipal_1_textura.png", L"casaprincipal_Normal.png",L"ARBOLES_CORTADOS_ESPECULAR.png",0.5, 0.0, 0.0,4);

	m_ModeloShader = new LightShaderClass((char*)"Modelo.vs", (char*)"Modelo.ps");
	if (!m_ModeloShader)
	{
		return false;
	}

	//GRANERO:
	modelazo_granero = new Modelos(hwnd, m_OpenGL, "GRANERO.obj", L"granero_textura.png", L"CASA_PRINCIPAL_NORMALES.png", L"ARBOLES_CORTADOS_ESPECULAR.png", 0.5, 0.0, 0.0, 5);

	m_ModeloShader = new LightShaderClass((char*)"Modelo.vs", (char*)"Modelo.ps");
	if (!m_ModeloShader)
	{
		return false;
	}

	//COBERTIZO:

	modelazo_cobertizo = new Modelos(hwnd, m_OpenGL, "COBERTIZO.obj", L"COBERTIZO_textura1.png", L"CASA_PRINCIPAL_NORMALES.png", L"ARBOLES_CORTADOS_ESPECULAR.png", 0.5, 0.0, 0.0, 6);

	m_ModeloShader = new LightShaderClass((char*)"Modelo.vs", (char*)"Modelo.ps");
	if (!m_ModeloShader)
	{
		return false;
	}

	//CAMIONETA:

	modelazo_camioneta = new Modelos(hwnd, m_OpenGL, "CAMIONETA.obj", L"PINO.png", L"CASA_PRINCIPAL_NORMALES.png", L"ARBOLES_CORTADOS_ESPECULAR.png", 0.5, 0.0, 0.0, 7);

	m_ModeloShader = new LightShaderClass((char*)"Modelo.vs", (char*)"Modelo.ps");
	if (!m_ModeloShader)
	{
		return false;
	}

	//CAJAS:

	modelazo_cajas = new Modelos(hwnd, m_OpenGL, "CAJAS.obj", L"cajastextura.jpg", L"CASA_PRINCIPAL_NORMALES.png", L"ARBOLES_CORTADOS_ESPECULAR.png", 0.5, 0.0, 0.0, 60);

	m_ModeloShader = new LightShaderClass((char*)"Modelo.vs", (char*)"Modelo.ps");
	if (!m_ModeloShader)
	{
		return false;
	}

	//ESTABLO:

	modelazo_establo = new Modelos(hwnd, m_OpenGL, "establo.obj", L"PINO.png", L"CASA_PRINCIPAL_NORMALES.png", L"ARBOLES_CORTADOS_ESPECULAR.png", 0.5, 0.0, 0.0, 61);

	m_ModeloShader = new LightShaderClass((char*)"Modelo.vs", (char*)"Modelo.ps");
	if (!m_ModeloShader)
	{
		return false;
	}

	//ARBOLES CORTADOS:

	modelazo_arboles_cortados = new Modelos(hwnd, m_OpenGL, "ARBOLES_CORTADOS.obj", L"arbol_cortado.jpg", L"CASA_PRINCIPAL_NORMALES.png", L"ARBOLES_CORTADOS_ESPECULAR.png", 0.5, 0.0, 0.0, 62);

	m_ModeloShader = new LightShaderClass((char*)"Modelo.vs", (char*)"Modelo.ps");
	if (!m_ModeloShader)
	{
		return false;
	}

	//CASA PRINCIPAL 2:
	modelazo_casa_principal_2 = new Modelos(hwnd, m_OpenGL, "casaprincipal_2.obj", L"casaprincipal_2_textura.png", L"casaprincipal_Normal.png", L"ARBOLES_CORTADOS_ESPECULAR.png", 0.5, 0.0, 0.0, 63);

	m_ModeloShader = new LightShaderClass((char*)"Modelo.vs", (char*)"Modelo.ps");
	if (!m_ModeloShader)
	{
		return false;
	}











	// Initialize the light shader object.
	result = m_ModeloShader->Initialize(m_OpenGL, hwnd);
	if (!result)
	{
		MessageBox(hwnd, (LPCSTR)"Could not initialize the light shader object.", (LPCSTR)"Error", MB_OK);
		return false;
	}


	
	





	return true;
}


void GraphicsClass::Shutdown()
{
	// Release the light object.
	if(m_Light)
	{
		delete m_Light;
		m_Light = 0;
	}

	// Release the light shader object.
	if(m_LightShader)
	{
		m_LightShader->Shutdown(m_OpenGL);
		delete m_LightShader;
		m_LightShader = 0;
	}

	// Release the light shader object.
	if (m_LightShaderSky)
	{
		m_LightShaderSky->Shutdown(m_OpenGL);
		delete m_LightShaderSky;
		m_LightShaderSky = 0;
	}

	// Release the camera object.
	if(m_Camera)
	{
		delete m_Camera;
		m_Camera = 0;
	}

	// Release the terreno object.
	if (terreno)
	{
		delete terreno;
		m_Camera = 0;
	}

	// Release the pointer to the OpenGL class object.
	m_OpenGL = 0;

	return;
}


bool GraphicsClass::Frame()
{
	bool result;
	static float rotation = 0.0f;


	// Update the rotation variable each frame.
	rotation += 0.0174532925f * 2.0f;
	if(rotation > 360.0f)
	{
		rotation -= 360.0f;
	}

	// Render the graphics scene.
	result = Render(rotation);
	if(!result)
	{
		return false;
	}

	return true;
}


bool GraphicsClass::Render(float rotation)
{
	float worldMatrix[16];
	float viewMatrix[16];
	float projectionMatrix[16];
	float lightDirection[3];
	float diffuseLightColor[4];
	float worldMatrixBill[16];


	// Clear the buffers to begin the scene.
	m_OpenGL->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

	// Generate the view matrix based on the camera's position.
	m_Camera->SetRotation(angx, angy, angz);
	m_Camera->SetYPos(terreno->Superficie(m_Camera->GetXPos(), m_Camera->GetZPos()) + 3);
	m_Camera->Render(vel);

	// Get the world, view, and projection matrices from the opengl and camera objects.
	m_OpenGL->GetWorldMatrix(worldMatrix);
	m_OpenGL->GetWorldMatrix(worldMatrixBill);
	m_Camera->GetViewMatrix(viewMatrix);
	m_OpenGL->GetProjectionMatrix(projectionMatrix);

	//////////////////////////////////////////////////////////
	//actualizar aqui el vector de luz y el color de la misma
	//////////////////////////////////////////////////////////

	// Get the light properties.
	m_Light->GetDirection(lightDirection);
	m_Light->GetDiffuseColor(diffuseLightColor);



	//CONTADOR:
	//HDD = HORA DEL DIA
	static float hdd = 0;
	hdd += 0.01;

	if (hdd > 21.0) { //21 horas son las 9:00 pm
		hdd = 0.0;
	}



	glDisable(GL_DEPTH_TEST);
	m_LightShaderSky->SetShader(m_OpenGL);
	m_LightShaderSky->PonMatriz4x4(m_OpenGL, (char*)"worldMatrix", worldMatrix);
	m_LightShaderSky->PonMatriz4x4(m_OpenGL, (char*)"viewMatrix", viewMatrix);
	m_LightShaderSky->PonMatriz4x4(m_OpenGL, (char*)"projectionMatrix", projectionMatrix);
	m_LightShaderSky->Pon1Entero(m_OpenGL, (char*)"cielo", 2);
	m_LightShaderSky->PonVec3(m_OpenGL, (char*)"lightDirection", lightDirection);
	m_LightShaderSky->PonVec4(m_OpenGL, (char*)"diffuseLightColor", diffuseLightColor);
	//m_LightShaderSky->Pon1Flotante(m_OpenGL, (char*)"diffuseLightColor", diffuseLightColor);



	//Creaci�n para el cambio de textura del cielo.
	//Falta gregar la funci�n Pon1Flotante

	//m_LightShaderSky->Pon1Flotante(m_OpenGL, (char*)"diffuseLightColor", diffuseLightColor);

	//Minuto 1:00:00
	//https://uanledu.sharepoint.com/sites/Section_02305010133802031420000101516004/Shared%20Documents/Forms/AllItems.aspx?id=%2Fsites%2FSection_02305010133802031420000101516004%2FShared%20Documents%2FGeneral%2FRecordings%2FReuni�n%20en%20_General_-20220311_162009-Grabaci�n%20de%20la%20reuni�n%2Emp4&parent=%2Fsites%2FSection_02305010133802031420000101516004%2FShared%20Documents%2FGeneral%2FRecordings




	sky->Render(m_OpenGL);
	glEnable(GL_DEPTH_TEST);

	



	// Rotate the world matrix by the rotation value so that the triangle will spin.
	//m_OpenGL->MatrixRotationY(worldMatrix, rotation);

	//Me qued� en el minuto 50

	//// Set the light shader as the current shader program and set the matrices that it will use for rendering.
	m_LightShader->SetShader(m_OpenGL);	
	m_LightShader->PonMatriz4x4(m_OpenGL, (char*)"worldMatrix", worldMatrix);
	m_LightShader->PonMatriz4x4(m_OpenGL, (char*)"viewMatrix", viewMatrix);
	m_LightShader->PonMatriz4x4(m_OpenGL, (char*)"projectionMatrix", projectionMatrix);
	m_LightShader->Pon1Entero(m_OpenGL, (char*)"shaderTexture", 10);
	m_LightShader->Pon1Entero(m_OpenGL, (char*)"shaderTexture1", 11);
	m_LightShader->Pon1Entero(m_OpenGL, (char*)"shaderTexture2", 12);
	m_LightShader->Pon1Entero(m_OpenGL, (char*)"shaderTexture3", 13);
	m_LightShader->Pon1Entero(m_OpenGL, (char*)"shaderTexture4", 14);
	m_LightShader->Pon1Entero(m_OpenGL, (char*)"shaderTexture5", 15);
	m_LightShader->Pon1Entero(m_OpenGL, (char*)"mexcla", 16);
	m_LightShader->PonVec3(m_OpenGL, (char*)"lightDirection", lightDirection);
	m_LightShader->PonVec4(m_OpenGL, (char*)"diffuseLightColor", diffuseLightColor);
	// Render the model using the light shader.
	terreno->Render(m_OpenGL);

	//// Set the light shader as the current shader program and set the matrices that it will use for rendering.
	//
	m_OpenGL->MatrixTranslation(worldMatrixBill, bill->x, terreno->Superficie(bill->x, bill->z) - 1, bill->z);	
	float rotay[16];
	m_OpenGL->MatrixRotationY(rotay, -bill->angBill(m_Camera->GetXPos(), m_Camera->GetZPos()));
	m_OpenGL->MatrixMultiply(worldMatrixBill, rotay, worldMatrixBill);
	m_BillShader->SetShader(m_OpenGL);
	m_BillShader->PonMatriz4x4(m_OpenGL, (char*)"worldMatrix", worldMatrixBill);
	m_BillShader->PonMatriz4x4(m_OpenGL, (char*)"viewMatrix", viewMatrix);
	m_BillShader->PonMatriz4x4(m_OpenGL, (char*)"projectionMatrix", projectionMatrix);
	m_BillShader->Pon1Entero(m_OpenGL, (char*)"billtext", 3);
	m_BillShader->PonVec3(m_OpenGL, (char*)"lightDirection", lightDirection);
	m_BillShader->PonVec4(m_OpenGL, (char*)"diffuseLightColor", diffuseLightColor);
	// Render the model using the light shader.
	bill->Render(m_OpenGL);
	




	//CASA PRINCIPAL:
	
	// Set the light shader as the current shader program and set the matrices that it will use for rendering.
	m_ModeloShader->SetShader(m_OpenGL);
	float modmatrix[16];
	m_OpenGL->GetWorldMatrix(modmatrix);
	m_OpenGL->MatrixTranslation(modmatrix, modelazo->x, terreno->Superficie(modelazo->x, modelazo->z), modelazo->z);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"worldMatrix", modmatrix);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"viewMatrix", viewMatrix);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"projectionMatrix", projectionMatrix);
	m_ModeloShader->Pon1Entero(m_OpenGL, (char*)"modtext", 4);
	m_ModeloShader->PonVec3(m_OpenGL, (char*)"lightDirection", lightDirection);
	m_ModeloShader->PonVec4(m_OpenGL, (char*)"diffuseLightColor", diffuseLightColor);
	// Render the model using the light shader.
	modelazo->Render(m_OpenGL);
	// Present the rendered scene to the screen.
	

	//GRANERO:
	m_ModeloShader->SetShader(m_OpenGL);
	float modmatrix2[16];
	m_OpenGL->GetWorldMatrix(modmatrix);
	m_OpenGL->MatrixTranslation(modmatrix, modelazo_granero->x, terreno->Superficie(modelazo_granero->x, modelazo_granero->z), modelazo_granero->z);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"worldMatrix", modmatrix);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"viewMatrix", viewMatrix);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"projectionMatrix", projectionMatrix);
	m_ModeloShader->Pon1Entero(m_OpenGL, (char*)"modtext", 5);
	m_ModeloShader->PonVec3(m_OpenGL, (char*)"lightDirection", lightDirection);
	m_ModeloShader->PonVec4(m_OpenGL, (char*)"diffuseLightColor", diffuseLightColor);
	// Render the model using the light shader.
	modelazo_granero->Render(m_OpenGL);
	// Present the rendered scene to the screen.


	//COBERTIZO:
	m_ModeloShader->SetShader(m_OpenGL);
	float modmatrix3[16];
	m_OpenGL->GetWorldMatrix(modmatrix);
	m_OpenGL->MatrixTranslation(modmatrix, modelazo_cobertizo->x, terreno->Superficie(modelazo_cobertizo->x, modelazo_cobertizo->z), modelazo_cobertizo->z);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"worldMatrix", modmatrix);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"viewMatrix", viewMatrix);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"projectionMatrix", projectionMatrix);
	m_ModeloShader->Pon1Entero(m_OpenGL, (char*)"modtext", 6);
	m_ModeloShader->PonVec3(m_OpenGL, (char*)"lightDirection", lightDirection);
	m_ModeloShader->PonVec4(m_OpenGL, (char*)"diffuseLightColor", diffuseLightColor);
	// Render the model using the light shader.
	modelazo_cobertizo->Render(m_OpenGL);
	// Present the rendered scene to the screen.


	//CAMIONETA
	m_ModeloShader->SetShader(m_OpenGL);
	float modmatrix4[16];
	m_OpenGL->GetWorldMatrix(modmatrix);
	m_OpenGL->MatrixTranslation(modmatrix, modelazo_camioneta->x, terreno->Superficie(modelazo_camioneta->x, modelazo_camioneta->z), modelazo_camioneta->z);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"worldMatrix", modmatrix);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"viewMatrix", viewMatrix);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"projectionMatrix", projectionMatrix);
	m_ModeloShader->Pon1Entero(m_OpenGL, (char*)"modtext", 7);
	m_ModeloShader->PonVec3(m_OpenGL, (char*)"lightDirection", lightDirection);
	m_ModeloShader->PonVec4(m_OpenGL, (char*)"diffuseLightColor", diffuseLightColor);
	// Render the model using the light shader.
	modelazo_camioneta->Render(m_OpenGL);
	// Present the rendered scene to the screen.


	//CAJAS:
	m_ModeloShader->SetShader(m_OpenGL);
	float modmatrix5[16];
	m_OpenGL->GetWorldMatrix(modmatrix);
	m_OpenGL->MatrixTranslation(modmatrix, modelazo_cajas->x, terreno->Superficie(modelazo_cajas->x, modelazo_cajas->z), modelazo_cajas->z);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"worldMatrix", modmatrix);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"viewMatrix", viewMatrix);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"projectionMatrix", projectionMatrix);
	m_ModeloShader->Pon1Entero(m_OpenGL, (char*)"modtext", 60);
	m_ModeloShader->PonVec3(m_OpenGL, (char*)"lightDirection", lightDirection);
	m_ModeloShader->PonVec4(m_OpenGL, (char*)"diffuseLightColor", diffuseLightColor);
	// Render the model using the light shader.
	modelazo_cajas->Render(m_OpenGL);
	// Present the rendered scene to the screen.


	
	//ESTABLO:
	m_ModeloShader->SetShader(m_OpenGL);
	float modmatrix6[16];
	m_OpenGL->GetWorldMatrix(modmatrix);
	m_OpenGL->MatrixTranslation(modmatrix, modelazo_establo->x, terreno->Superficie(modelazo_establo->x, modelazo_establo->z), modelazo_establo->z);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"worldMatrix", modmatrix);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"viewMatrix", viewMatrix);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"projectionMatrix", projectionMatrix);
	m_ModeloShader->Pon1Entero(m_OpenGL, (char*)"modtext", 61);
	m_ModeloShader->PonVec3(m_OpenGL, (char*)"lightDirection", lightDirection);
	m_ModeloShader->PonVec4(m_OpenGL, (char*)"diffuseLightColor", diffuseLightColor);
	// Render the model using the light shader.
	modelazo_establo->Render(m_OpenGL);
	// Present the rendered scene to the screen.

	
	//ARBOLES CORTADOS:
	m_ModeloShader->SetShader(m_OpenGL);
	float modmatrix7[16];
	m_OpenGL->GetWorldMatrix(modmatrix);
	m_OpenGL->MatrixTranslation(modmatrix, modelazo_arboles_cortados->x, terreno->Superficie(modelazo_arboles_cortados->x, modelazo_arboles_cortados->z), modelazo_arboles_cortados->z);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"worldMatrix", modmatrix);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"viewMatrix", viewMatrix);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"projectionMatrix", projectionMatrix);
	m_ModeloShader->Pon1Entero(m_OpenGL, (char*)"modtext", 62);
	m_ModeloShader->PonVec3(m_OpenGL, (char*)"lightDirection", lightDirection);
	m_ModeloShader->PonVec4(m_OpenGL, (char*)"diffuseLightColor", diffuseLightColor);
	// Render the model using the light shader.
	modelazo_arboles_cortados->Render(m_OpenGL);
	// Present the rendered scene to the screen.
		

	//CASA PRINCIPAL 2:
	m_ModeloShader->SetShader(m_OpenGL);
	float modmatrix8[16];
	m_OpenGL->GetWorldMatrix(modmatrix);
	m_OpenGL->MatrixTranslation(modmatrix, modelazo_casa_principal_2->x, terreno->Superficie(modelazo_casa_principal_2->x, modelazo_casa_principal_2->z), modelazo_arboles_cortados->z);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"worldMatrix", modmatrix);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"viewMatrix", viewMatrix);
	m_ModeloShader->PonMatriz4x4(m_OpenGL, (char*)"projectionMatrix", projectionMatrix);
	m_ModeloShader->Pon1Entero(m_OpenGL, (char*)"modtext", 63);
	m_ModeloShader->PonVec3(m_OpenGL, (char*)"lightDirection", lightDirection);
	m_ModeloShader->PonVec4(m_OpenGL, (char*)"diffuseLightColor", diffuseLightColor);
	// Render the model using the light shader.
	modelazo_casa_principal_2->Render(m_OpenGL);
	// Present the rendered scene to the screen.






	// Present the rendered scene to the screen.
	m_OpenGL->EndScene();

	return true;
}