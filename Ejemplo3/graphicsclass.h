////////////////////////////////////////////////////////////////////////////////
// Filename: graphicsclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _GRAPHICSCLASS_H_
#define _GRAPHICSCLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "openglclass.h"
#include "cameraclass.h"
#include "lightshaderclass.h"
#include "lightclass.h"
#include "Terreno.h"
#include "SkyDome.h"
#include "Billboard.h"
#include "Modelos.h"
#include "Water.h"


/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;


////////////////////////////////////////////////////////////////////////////////
// Class name: GraphicsClass
////////////////////////////////////////////////////////////////////////////////
class GraphicsClass
{
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass&);
	~GraphicsClass();

	bool Initialize(OpenGLClass*, HWND);
	void Shutdown();
	bool Frame();
	float angx, angy, angz, vel;

private:
	bool Render(float);

private:
	OpenGLClass* m_OpenGL;
	CameraClass* m_Camera;	
	Terreno* terreno;
	SkyDome* sky;
	Billboard* arbol_bill;
	Billboard* arbol_bill2;
	Billboard* miel_bill;



	Modelos* modelazo;
	Modelos* modelazo_granero;
	Modelos* modelazo_cobertizo;
	Modelos* modelazo_camioneta;
	Modelos* modelazo_cajas;
	Modelos* modelazo_establo;
	Modelos* modelazo_arboles_cortados;
	Modelos* modelazo_casa_principal_2;
	Modelos* modelazo_silla;
	Modelos* modelazo_roca;
	Modelos* modelazo_agua;
	Water* m_Water;


	LightShaderClass* m_LightShader;
	LightShaderClass* m_LightShaderSky;
	LightShaderClass* m_BillShader;
	LightShaderClass* m_ModeloShader;
	LightShaderClass* m_ModeloShader_2;
	LightShaderClass* m_WaterShader;
	LightShaderClass* m_VeggieShader;
	LightClass* m_Light;


};

#endif