//Salazar Cárdenas Carlos Eduardo
//#include <gl/gl.h>     // The GL Header File
//#include <windows.h>	//Solo para Windows
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>		// Descomentar para Linux
//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>		// Solo para Windows

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
CCamera objCamera;
float a = 0;
float b = 0;
float c = 0;
GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 
//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int font = (int)GLUT_BITMAP_HELVETICA_18;

//Otras opciones son:
/*GLUT_BITMAP_8_BY_13
GLUT_BITMAP_9_BY_15
GLUT_BITMAP_TIMES_ROMAN_10
GLUT_BITMAP_TIMES_ROMAN_24
GLUT_BITMAP_HELVETICA_10
GLUT_BITMAP_HELVETICA_12
GLUT_BITMAP_HELVETICA_18*/


int time;
int timebase = 0;
char s[30];
//ANIMACIONES
int FRAME = 0;
bool play_avion = false;
bool play_pez = false;
bool play_bote = false;
bool play_globo = false;
	//AVION
float movavionx = 0.0;
float movaviony = 0.0;
float movavionz = 0.0;
float angRotavion = -90;

	//GLOBO
float mov_globo_X = 0.0;
float mov_globo_Y = 0.0;
float mov_globo_Z = 0.0;
int bandera_globo = 0;

	//BOTE
float mov_barco_x = 0.0;
float mov_barco_z = 0.0;
float angRotbote = 90.0;
int bandera_barco = 0;





//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 27.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = { 18 };

CTexture text1;
CTexture text2;


CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig6;


//FIGURAS PROYECTO
CFiguras prisma1;
CFiguras cilindro1;
CFiguras biblioteca;
CFiguras rectoria; //Edificio de rectoria
CFiguras derecho;

CTexture globo;

//TEXTURAS EDIFICIOS
	//Posgrado Arquitectura
	CTexture concretoPosgradoArquitectura;
	CTexture ventanaposgrado1;
	CTexture ventanaposgrado2;
	CTexture marble;
	CTexture paredroja;
	CTexture marblewhite;
	CTexture muralPos;
	CTexture ventanaspos;
	CTexture ventanas2;
	CTexture puertapos;


	//Texturas biblioteca central
	CTexture biblioteca_cupula;
	CTexture mural_frontal;
	CTexture biblioteca_ventanas;
	CTexture biblioteca_desagues;
	CTexture biblioteca_vitrales;
	CTexture biblioteca_fuente;
	CTexture biblioteca_roca;
	CTexture biblioteca_roca2;
	CTexture edificio_central;
	CTexture base_central;
	CTexture roca_central;

	//Texturas rectoria
	CTexture rectoria_mural;
	CTexture rectoria_vitrales;
	CTexture rectoria_escudo;
	CTexture rectoria_erroneo;
	CTexture rectoria_mural_anexo;
	CTexture rectoria_azulejos;
	CTexture rectoria_ventanas;
	CTexture rectoria_mural_derecha;
	CTexture edificio_rectoria;
	CTexture base_rectoria;
	CTexture lateral_rectoria;
	CTexture trasera_rectoria;
	CTexture cupula_rectoria;
	CTexture rectoria_detalle;

	//Texturas derecho
	CTexture derecho_barandales;
	CTexture derecho_vitrales;

//TEXTURAS PROYECTO
CTexture pastocuadros;
CTexture suelocuadros;
CTexture pisoescalera1;
CTexture piedra;
CTexture pasto;
CTexture suelopiedra;
CTexture tree1;
CTexture tree2;
CTexture tree3;
CTexture tree4;
CTexture suelorojo;
CTexture concretopilar;
CTexture fondo1biblio;
CTexture suelopastohoja;
CTexture paredaladodgose;
CTexture techo;
CTexture agua;
CTexture estadio1;
CTexture estadio2;
CTexture pisoarqui;
CTexture tartan;
CTexture sueloarqui;
CTexture pisoescaleras;
CTexture suelodepiedra;
CTexture concreto;
CTexture leonardita;
CTexture paredamarilla;

//MODELOS PROYECTO
CModel arbol;
CModel turbosonic;
CModel pez;
CModel bote;
CModel bote2;

//MODELOS EDIFICIOS 3DS MAX
CModel TorreDeHumanidades;
CModel AnexoDerecho;
CModel DGOSE;
CModel Desnivel;
CModel Olmeca;
CModel Ingenieria;
CModel Arquitectura;
CModel ZonadeComercio;
CModel Taller;

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);
	//Para construir la figura comentar esto
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);

	//glEnable ( GL_COLOR_MATERIAL );
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
	//glPolygonMode(GL_BACK, GL_LINE);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
	glEnable(GL_BLEND);			// Turn Blending On
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);					// Set The Blending Function For Translucency
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE);			// Set The Blending Function For Translucency
	//glColor4f(1.0f, 1.0f, 1.0f, 0.5); 

	globo.LoadTGA("Texturas/globo.tga");
	globo.BuildGLTexture();
	globo.ReleaseImage();

	//Posgrado de Arquitectura
	concretoPosgradoArquitectura.LoadTGA("Edificios/PosgradoDeArquitectura/Texturas/concreto.tga");
	concretoPosgradoArquitectura.BuildGLTexture();
	concretoPosgradoArquitectura.ReleaseImage();
	ventanaposgrado1.LoadTGA("Edificios/PosgradoDeArquitectura/Texturas/ventanaposgrado1.tga");
	ventanaposgrado1.BuildGLTexture();
	ventanaposgrado1.ReleaseImage();
	ventanaposgrado2.LoadTGA("Edificios/PosgradoDeArquitectura/Texturas/ventanaposgrado2.tga");
	ventanaposgrado2.BuildGLTexture();
	ventanaposgrado2.ReleaseImage();
	marble.LoadTGA("Edificios/PosgradoDeArquitectura/Texturas/marble.tga");
	marble.BuildGLTexture();
	marble.ReleaseImage();
	paredroja.LoadTGA("Edificios/PosgradoDeArquitectura/Texturas/paredroja.tga");
	paredroja.BuildGLTexture();
	paredroja.ReleaseImage();
	marblewhite.LoadTGA("Edificios/PosgradoDeArquitectura/Texturas/marblewhite.tga");
	marblewhite.BuildGLTexture();
	marblewhite.ReleaseImage();
	muralPos.LoadTGA("Edificios/PosgradoDeArquitectura/Texturas/muralPos.tga");
	muralPos.BuildGLTexture();
	muralPos.ReleaseImage();
	ventanaspos.LoadTGA("Edificios/PosgradoDeArquitectura/Texturas/ventanaspos.tga");
	ventanaspos.BuildGLTexture();
	ventanaspos.ReleaseImage();
	ventanas2.LoadTGA("Edificios/PosgradoDeArquitectura/Texturas/ventanas2.tga");
	ventanas2.BuildGLTexture();
	ventanas2.ReleaseImage();
	puertapos.LoadTGA("Edificios/PosgradoDeArquitectura/Texturas/puertapos.tga");
	puertapos.BuildGLTexture();
	puertapos.ReleaseImage();

	
	text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	pastocuadros.LoadTGA("Texturas/pastocuadros.tga");
	pastocuadros.BuildGLTexture();
	pastocuadros.ReleaseImage();

	suelocuadros.LoadTGA("Texturas/suelocuadros.tga");
	suelocuadros.BuildGLTexture();
	suelocuadros.ReleaseImage();

	pisoescalera1.LoadTGA("Texturas/pisoescalera1.tga");
	pisoescalera1.BuildGLTexture();
	pisoescalera1.ReleaseImage();

	piedra.LoadTGA("Texturas/piedra.tga");
	piedra.BuildGLTexture();
	piedra.ReleaseImage();

	pasto.LoadTGA("Texturas/pasto.tga");
	pasto.BuildGLTexture();
	pasto.ReleaseImage();

	suelopiedra.LoadTGA("Texturas/suelopiedra.tga");
	suelopiedra.BuildGLTexture();
	suelopiedra.ReleaseImage();

	suelorojo.LoadTGA("Texturas/suelorojo.tga");
	suelorojo.BuildGLTexture();
	suelorojo.ReleaseImage();

	concretopilar.LoadTGA("Texturas/conc.tga");
	concretopilar.BuildGLTexture();
	concretopilar.ReleaseImage();

	fondo1biblio.LoadTGA("Texturas/fondo1biblio.tga");
	fondo1biblio.BuildGLTexture();
	fondo1biblio.ReleaseImage();

	suelopastohoja.LoadTGA("Texturas/suelopastohoja.tga");
	suelopastohoja.BuildGLTexture();
	suelopastohoja.ReleaseImage();


	paredaladodgose.LoadTGA("Texturas/paredaladodgose.tga");
	paredaladodgose.BuildGLTexture();
	paredaladodgose.ReleaseImage();

	estadio1.LoadTGA("Texturas/estadio1.tga");
	estadio1.BuildGLTexture();
	estadio1.ReleaseImage();

	estadio2.LoadTGA("Texturas/estadio2.tga");
	estadio2.BuildGLTexture();
	estadio2.ReleaseImage();


	tartan.LoadTGA("Texturas/tartan.tga");
	tartan.BuildGLTexture();
	tartan.ReleaseImage();

	concreto.LoadTGA("Texturas/concreto.tga");
	concreto.BuildGLTexture();
	concreto.ReleaseImage();

	suelodepiedra.LoadTGA("Texturas/suelodepiedra.tga");
	suelodepiedra.BuildGLTexture();
	suelodepiedra.ReleaseImage();

	sueloarqui.LoadTGA("Texturas/sueloarqui.tga");
	sueloarqui.BuildGLTexture();
	sueloarqui.ReleaseImage();

	pisoescaleras.LoadTGA("Texturas/pisoescaleras.tga");
	pisoescaleras.BuildGLTexture();
	pisoescaleras.ReleaseImage();

	sueloarqui.LoadTGA("Texturas/sueloarqui.tga");
	sueloarqui.BuildGLTexture();
	sueloarqui.ReleaseImage();

	leonardita.LoadTGA("Texturas/leonardita.tga");
	leonardita.BuildGLTexture();
	leonardita.ReleaseImage();

	paredamarilla.LoadTGA("Texturas/pam.tga");
	paredamarilla.BuildGLTexture();
	paredamarilla.ReleaseImage();



	//CARGA MODELOS 3DS MAX
	TorreDeHumanidades._3dsLoad("Edificios/TorreDeHumanidades/TorreDeHumanidades.3DS");
	TorreDeHumanidades.LoadTextureImages();
	TorreDeHumanidades.GLIniTextures();
	TorreDeHumanidades.ReleaseTextureImages();

	AnexoDerecho._3dsLoad("Edificios/AnexoDerecho/AnexoDerecho.3DS");
	AnexoDerecho.LoadTextureImages();
	AnexoDerecho.GLIniTextures();
	AnexoDerecho.ReleaseTextureImages();

	DGOSE._3dsLoad("Edificios/DGOSE/DGOSE.3DS");
	DGOSE.LoadTextureImages();
	DGOSE.GLIniTextures();
	DGOSE.ReleaseTextureImages();

	Desnivel._3dsLoad("Edificios/Desnivel/Desnivel.3DS");
	Desnivel.LoadTextureImages();
	Desnivel.GLIniTextures();
	Desnivel.ReleaseTextureImages();

	Olmeca._3dsLoad("Edificios/Olmeca/Olmeca.3DS");
	Olmeca.LoadTextureImages();
	Olmeca.GLIniTextures();
	Olmeca.ReleaseTextureImages();

	Ingenieria._3dsLoad("Edificios/Ingenieria/Ingenieria.3DS");
	Ingenieria.LoadTextureImages();
	Ingenieria.GLIniTextures();
	Ingenieria.ReleaseTextureImages();

	Arquitectura._3dsLoad("Edificios/Arquitectura/Arquitectura.3DS");
	Arquitectura.LoadTextureImages();
	Arquitectura.GLIniTextures();
	Arquitectura.ReleaseTextureImages();

	ZonadeComercio._3dsLoad("Edificios/ZonadeComercio/ZonadeComercio.3DS");
	ZonadeComercio.LoadTextureImages();
	ZonadeComercio.GLIniTextures();
	ZonadeComercio.ReleaseTextureImages();

	Taller._3dsLoad("Edificios/Taller/Taller.3DS");
	Taller.LoadTextureImages();
	Taller.GLIniTextures();
	Taller.ReleaseTextureImages();


	//Texturas derecho

	derecho_barandales.LoadTGA("Edificios/Derecho/derecho_barandales.tga");
	derecho_barandales.BuildGLTexture();
	derecho_barandales.ReleaseImage();

	derecho_vitrales.LoadTGA("Edificios/Derecho/derecho_vitrales.tga");
	derecho_vitrales.BuildGLTexture();
	derecho_vitrales.ReleaseImage();

	//Texturas para la biblioteca central:
	biblioteca_cupula.LoadTGA("Edificios/BibliotecaCentral/biblioteca_cupula.tga");
	biblioteca_cupula.BuildGLTexture();
	biblioteca_cupula.ReleaseImage();

	mural_frontal.LoadTGA("Edificios/BibliotecaCentral/mural_frontal.tga");
	mural_frontal.BuildGLTexture();
	mural_frontal.ReleaseImage();

	biblioteca_desagues.LoadTGA("Edificios/BibliotecaCentral/biblioteca_base.tga");
	biblioteca_desagues.BuildGLTexture();
	biblioteca_desagues.ReleaseImage();

	biblioteca_ventanas.LoadTGA("Edificios/BibliotecaCentral/biblioteca_ventanas.tga");
	biblioteca_ventanas.BuildGLTexture();
	biblioteca_ventanas.ReleaseImage();

	biblioteca_vitrales.LoadTGA("Edificios/BibliotecaCentral/biblioteca_vitrales.tga");
	biblioteca_vitrales.BuildGLTexture();
	biblioteca_vitrales.ReleaseImage();

	biblioteca_fuente.LoadBMP("Edificios/BibliotecaCentral/biblioteca_fuente.bmp");
	biblioteca_fuente.BuildGLTexture();
	biblioteca_fuente.ReleaseImage();

	biblioteca_roca.LoadTGA("Edificios/BibliotecaCentral/biblioteca_roca_2.tga");
	biblioteca_roca.BuildGLTexture();
	biblioteca_roca.ReleaseImage();

	biblioteca_roca2.LoadTGA("Edificios/BibliotecaCentral/biblioteca_roca.tga");
	biblioteca_roca2.BuildGLTexture();
	biblioteca_roca2.ReleaseImage();

	techo.LoadBMP("Edificios/BibliotecaCentral/techo.bmp");
	techo.BuildGLTexture();
	techo.ReleaseImage();

	agua.LoadTGA("Edificios/BibliotecaCentral/agua.tga");
	agua.BuildGLTexture();
	agua.ReleaseImage();

	edificio_central.LoadTGA("Edificios/BibliotecaCentral/central_fachada_2.tga");
	edificio_central.BuildGLTexture();
	edificio_central.ReleaseImage();

	base_central.LoadTGA("Edificios/BibliotecaCentral/central_5.tga");
	base_central.BuildGLTexture();
	base_central.ReleaseImage();

	roca_central.LoadTGA("Edificios/BibliotecaCentral/central_3.tga");
	roca_central.BuildGLTexture();
	roca_central.ReleaseImage();

	//Texturas rectoria
	rectoria_mural.LoadTGA("Edificios/Rectoria/rectoria_mural.tga");
	rectoria_mural.BuildGLTexture();
	rectoria_mural.ReleaseImage();

	rectoria_vitrales.LoadTGA("Edificios/Rectoria/rectoria_vitrales.tga");
	rectoria_vitrales.BuildGLTexture();
	rectoria_vitrales.ReleaseImage();

	rectoria_escudo.LoadTGA("Edificios/Rectoria/rectoria_escudo.tga");
	rectoria_escudo.BuildGLTexture();
	rectoria_escudo.ReleaseImage();

	rectoria_erroneo.LoadTGA("Edificios/Rectoria/rectoria_erroneo.tga");
	rectoria_erroneo.BuildGLTexture();
	rectoria_erroneo.ReleaseImage();

	rectoria_mural_anexo.LoadTGA("Edificios/Rectoria/rectoria_mural_anexo.tga");
	rectoria_mural_anexo.BuildGLTexture();
	rectoria_mural_anexo.ReleaseImage();

	rectoria_azulejos.LoadTGA("Edificios/Rectoria/rectoria_azulejos.tga");
	rectoria_azulejos.BuildGLTexture();
	rectoria_azulejos.ReleaseImage();

	rectoria_ventanas.LoadTGA("Edificios/Rectoria/rectoria_ventanas.tga");
	rectoria_ventanas.BuildGLTexture();
	rectoria_ventanas.ReleaseImage();

	rectoria_mural_derecha.LoadTGA("Edificios/Rectoria/rectoria_mural_derecha.tga");
	rectoria_mural_derecha.BuildGLTexture();
	rectoria_mural_derecha.ReleaseImage();


	edificio_rectoria.LoadTGA("Edificios/Rectoria/rectoria_0.tga");
	edificio_rectoria.BuildGLTexture();
	edificio_rectoria.ReleaseImage();

	base_rectoria.LoadTGA("Edificios/Rectoria/rectoria_4.tga");
	base_rectoria.BuildGLTexture();
	base_rectoria.ReleaseImage();

	lateral_rectoria.LoadTGA("Edificios/Rectoria/rectoria_1.tga");
	lateral_rectoria.BuildGLTexture();
	lateral_rectoria.ReleaseImage();

	trasera_rectoria.LoadTGA("Edificios/Rectoria/rectoria_3.tga");
	trasera_rectoria.BuildGLTexture();
	trasera_rectoria.ReleaseImage();

	cupula_rectoria.LoadTGA("Edificios/Rectoria/rectoria_cupula.tga");
	cupula_rectoria.BuildGLTexture();
	cupula_rectoria.ReleaseImage();

	rectoria_detalle.LoadTGA("Edificios/Rectoria/rectoria_detalle.tga");
	rectoria_detalle.BuildGLTexture();
	rectoria_detalle.ReleaseImage();



	tree1.LoadTGA("Texturas/tree1.tga");
	tree1.BuildGLTexture();
	tree1.ReleaseImage();
	tree2.LoadTGA("Texturas/tree2.tga");
	tree2.BuildGLTexture();
	tree2.ReleaseImage();
	tree3.LoadTGA("Texturas/tree3.tga");
	tree3.BuildGLTexture();
	tree3.ReleaseImage();
	tree4.LoadTGA("Texturas/tree4.tga");
	tree4.BuildGLTexture();
	tree4.ReleaseImage();


	arbol._3dsLoad("Modelos/arbol.3ds");

	turbosonic._3dsLoad("Modelos/turbosonic.3ds");

	bote._3dsLoad("Modelos/bote.3ds");

	objCamera.Position_Camera(600, 15.5f, 3, 600, 15.5f, 0, 0, 1, 0);
	

}

void pintaTexto(float x, float y, float z, void *font, char *string)
{

	char *c;     //Almacena los caracteres a escribir
	glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
	//glWindowPos2i(150,100);
	for (c = string; *c != '\0'; c++) //Condicion de fin de cadena
	{
		glutBitmapCharacter(font, *c); //imprime
	}
}

void arbol1()
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glBindTexture(GL_TEXTURE_2D, tree1.GLindex);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();

	glPopMatrix();

	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	glEnable(GL_LIGHTING);

	glPopMatrix();
}

void arbol2()
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glBindTexture(GL_TEXTURE_2D, tree2.GLindex);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();

	glPopMatrix();

	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	glEnable(GL_LIGHTING);

	glPopMatrix();
}

void arbol3()
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glBindTexture(GL_TEXTURE_2D, tree3.GLindex);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();

	glPopMatrix();

	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	glEnable(GL_LIGHTING);

	glPopMatrix();
}

void arbol4()
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glBindTexture(GL_TEXTURE_2D, tree4.GLindex);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();

	glPopMatrix();

	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	glEnable(GL_LIGHTING);

	glPopMatrix();
}

void GrupoDeArboles(){
	glPushMatrix();
	glScalef(2, 2, 2);
	glTranslatef(-41, -5, -45);
	arbol1();
	glTranslatef(0, 0.5, 8);
	arbol3();
	glTranslatef(0, 0, 8);
	arbol1();
	glTranslatef(0, 0, 8);
	arbol4();
	glTranslatef(-8, 1, 0);
	arbol2();
	glTranslatef(0, 0.5, -8);
	arbol1();
	glTranslatef(0, 0, -8);
	arbol4();
	glTranslatef(0, -2, -8);
	arbol2();
	glTranslatef(-8, 0, 0);
	arbol4();
	glTranslatef(0, 1, 8);
	arbol1();
	glTranslatef(0, 0.5, 8);
	arbol2();
	glTranslatef(0, -1, 8);
	arbol3();
	glTranslatef(-8, 0, 0);
	arbol1();
	glTranslatef(0, 0, -8);
	arbol4();
	glTranslatef(0, 0, -8);
	arbol2();
	glTranslatef(0, -1, -8);
	arbol2();
	glPopMatrix();

}


//EDIFICIOS

//RECTORIA

void Rectoria(){
//Figuras Edificio de rectoria



glPushMatrix(); //Vitrales inferiores frontales rectoria
glTranslatef(-82.0, -27.5, 80.0);
glRotatef(0, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(55.0, 60.0, 0.1);
glDisable(GL_LIGHTING);
rectoria.prisma2(rectoria_vitrales.GLindex, 0);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Vitrales inferiores derecha rectoria
glTranslatef(-110.0, -27.5, 53.0);
glRotatef(0, 1, 0, 0);
glRotatef(360, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(55.0, 60.0, 0.1);
glDisable(GL_LIGHTING);
rectoria.prisma2(rectoria_vitrales.GLindex, 0);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Vitrales inferiores izquierda rectoria
glTranslatef(-110.0, -27.5, 107.1);
glRotatef(180, 1, 0, 0);
glRotatef(0, 0, 1, 0);
glRotatef(0, 0, 0, 1);
glScalef(55.0, 60.0, 0.1);
glDisable(GL_LIGHTING);
rectoria.prisma2(rectoria_vitrales.GLindex, 0);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Vitrales superiores frontales rectoria
glTranslatef(-82.0, 50.0, 80.0);
glRotatef(0, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(55.0, 70.0, 0.1);
glDisable(GL_LIGHTING);
rectoria.prisma2(rectoria_vitrales.GLindex, 0);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Vitrales superior derecha rectoria
glTranslatef(-110.0, 50.0, 53.0);
glRotatef(0, 1, 0, 0);
glRotatef(0, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(55.0, 70.0, 0.1);
glDisable(GL_LIGHTING);
rectoria.prisma2(rectoria_vitrales.GLindex, 0);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Vitrales inferiores izquierda rectoria
glTranslatef(-110.0, 50.0, 107.1);
glRotatef(180, 1, 0, 0);
glRotatef(0, 0, 1, 0);
glRotatef(0, 0, 0, 1);
glScalef(55.0, 70.0, 0.1);
glDisable(GL_LIGHTING);
rectoria.prisma2(rectoria_vitrales.GLindex, 0);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Vitrales traseros rectoria
glTranslatef(-137.3, 14.0, 80.0);
glRotatef(0, 1, 0, 0);
glRotatef(90, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(53.0, 143.0, 0.1);
glDisable(GL_LIGHTING);
rectoria.prisma2(rectoria_vitrales.GLindex, 0);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Techo rectoria
glTranslatef(-110.0, 85.0, 80.0);
glRotatef(180, 1, 0, 0);
glRotatef(90, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(59.0, 2.0, 59.0);
glDisable(GL_LIGHTING);
rectoria.prisma2(techo.GLindex, techo.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Base rectoria
glTranslatef(-110.0, -43.0, 80.0);
glRotatef(180, 1, 0, 0);
glRotatef(90, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(59.0, 2.0, 59.0);
glDisable(GL_LIGHTING);
rectoria.prisma2(techo.GLindex, techo.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Cubo mural rectoria
glTranslatef(-85.0, 8.0, 80.0);
glRotatef(0, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(37.0, 28.0, 20.0);
glDisable(GL_LIGHTING);
rectoria.prisma2(rectoria_mural.GLindex, rectoria_mural.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna frontal 1
glTranslatef(-82.0, 2.3, 105.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 12.7, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna frontal 2
glTranslatef(-82.0, 2.3, 101.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 12.7, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna frontal 3
glTranslatef(-82.0, 2.3, 58.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 12.7, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna frontal 4
glTranslatef(-82.0, 2.3, 54.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 12.7, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna izquierda 1
glTranslatef(-85.0, 2.3, 53.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 12.7, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna izquierda 2
glTranslatef(-93.0, 2.3, 53.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 12.7, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna izquierda 3
glTranslatef(-101.0, 2.3, 53.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 12.7, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna izquierda 4
glTranslatef(-109.0, 2.3, 53.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 12.7, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna izquierda 5
glTranslatef(-117.0, 2.3, 53.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 12.7, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna derecha 1
glTranslatef(-85.0, 2.3, 107.1);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 12.7, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna derecha 2
glTranslatef(-93.0, 2.3, 107.1);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 12.7, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna derecha 3
glTranslatef(-101.0, 2.3, 107.1);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 12.7, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna derecha 4
glTranslatef(-109.0, 2.3, 107.1);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 12.7, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna derecha 5
glTranslatef(-117.0, 2.3, 107.1);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 12.7, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna derecha 6
glTranslatef(-125.0, 2.3, 107.1);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 12.7, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna derecha 7
glTranslatef(-133.0, 2.3, 107.1);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 12.7, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Base falsa derecha
glTranslatef(-128.5, 15.0, 57.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(15.0, 146.0, 10.0);
glDisable(GL_LIGHTING);
rectoria.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Base falsa trasera
glTranslatef(-139.0, 14.0, 78.0);
glRotatef(180, 1, 0, 0);
glRotatef(360, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(15.0, 148.0, 15.0);
glDisable(GL_LIGHTING);
rectoria.prisma2(rectoria_escudo.GLindex, techo.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Tapar escudo erroneo
glTranslatef(-136.2, -14.0, 85.6);
glRotatef(180, 1, 0, 0);
glRotatef(180, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(20.0, 35.0, 0.0);
glDisable(GL_LIGHTING);
rectoria.prisma2(rectoria_erroneo.GLindex, 0);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Edificio anexo techo
glTranslatef(-117.0, -15.0, 143.5);
glRotatef(0, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(70.0, 3.0, 70.0);
glDisable(GL_LIGHTING);
rectoria.prisma2(techo.GLindex, techo.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Rectoriaa mural anexo 
glTranslatef(-117.0, -31.5, 177.5);
glRotatef(0, 1, 0, 0);
glRotatef(180, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(70.0, 30.0, 3.0);
glDisable(GL_LIGHTING);
rectoria.prisma2(rectoria_mural_anexo.GLindex, techo.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Edificio anexo base falsa
glTranslatef(-116.8, -45.0, 143.5);
glRotatef(0, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(70.2, 3.0, 70.0);
glDisable(GL_LIGHTING);
rectoria.prisma2(techo.GLindex, techo.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

//////////////////////

glPushMatrix(); //Columna mural anexo 0
glTranslatef(-150.0, -57.0, 178.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna mural anexo 1
glTranslatef(-145.0, -57.0, 178.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna mural anexo 2
glTranslatef(-140.0, -57.0, 178.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna mural anexo 3
glTranslatef(-135.0, -57.0, 178.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna mural anexo 4
glTranslatef(-130.0, -57.0, 178.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna mural anexo 5
glTranslatef(-125.0, -57.0, 178.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna mural anexo 6
glTranslatef(-120.0, -57.0, 178.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna mural anexo 7
glTranslatef(-115.0, -57.0, 178.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna mural anexo 8
glTranslatef(-110.0, -57.0, 178.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna mural anexo 9
glTranslatef(-105.0, -57.0, 178.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna mural anexo 10
glTranslatef(-100.0, -57.0, 178.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna mural anexo 11
glTranslatef(-95.0, -57.0, 178.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna mural anexo 12
glTranslatef(-90.0, -57.0, 178.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna mural anexo 13
glTranslatef(-85.0, -57.0, 178.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

//////////////////////////////////

glPushMatrix(); //Columna frontal anexo 1
glTranslatef(-83.0, -55.0, 175.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 9.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna frontal anexo 2
glTranslatef(-83.0, -55.0, 170.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 9.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna frontal anexo 3
glTranslatef(-83.0, -55.0, 165.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 9.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna frontal anexo 4
glTranslatef(-83.0, -55.0, 160.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 9.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna frontal anexo 5
glTranslatef(-83.0, -55.0, 155.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 9.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna frontal anexo 6
glTranslatef(-83.0, -55.0, 150.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 9.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna frontal anexo 7
glTranslatef(-83.0, -55.0, 145.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 9.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna frontal anexo 8
glTranslatef(-83.0, -55.0, 140.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 9.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna frontal anexo 9
glTranslatef(-83.0, -55.0, 135.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 9.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna frontal anexo 10
glTranslatef(-83.0, -55.0, 130.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 9.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna frontal anexo 11
glTranslatef(-83.0, -55.0, 125.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 9.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna frontal anexo 12
glTranslatef(-83.0, -55.0, 120.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 9.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna frontal anexo 13
glTranslatef(-83.0, -55.0, 115.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 9.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna frontal anexo 14
glTranslatef(-83.0, -55.0, 110.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 9.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

///////////////

glPushMatrix(); //Columna trasera anexo 1
glTranslatef(-151.5, -57.0, 175.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna trasera anexo 2
glTranslatef(-151.5, -57.0, 170.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna trasera anexo 3
glTranslatef(-151.5, -57.0, 165.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna trasera anexo 4
glTranslatef(-151.5, -57.0, 160.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna trasera anexo 5
glTranslatef(-151.5, -57.0, 155.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna trasera anexo 6
glTranslatef(-151.5, -57.0, 150.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna trasera anexo 7
glTranslatef(-151.5, -57.0, 145.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna trasera anexo 8
glTranslatef(-151.5, -57.0, 140.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna trasera anexo 9
glTranslatef(-151.5, -57.0, 135.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna trasera anexo 10
glTranslatef(-151.5, -57.0, 130.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna trasera anexo 11
glTranslatef(-151.5, -57.0, 125.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna trasera anexo 12
glTranslatef(-151.5, -57.0, 120.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna trasera anexo 13
glTranslatef(-151.5, -57.0, 115.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna trasera anexo 14
glTranslatef(-151.5, -57.0, 115.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna trasera anexo 15
glTranslatef(-151.5, -57.0, 115.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna trasera anexo 16
glTranslatef(-151.5, -57.0, 110.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 11.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

//////////////////

glPushMatrix(); //Rectoriaa mural anexo 
glTranslatef(-117.0, -31.5, 109.5);
glRotatef(0, 1, 0, 0);
glRotatef(180, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(70.0, 30.0, 0.1);
glDisable(GL_LIGHTING);
rectoria.prisma2(techo.GLindex, 0);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Rectoriaa mural anexo 
glTranslatef(-117.0, -52.0, 109.5);
glRotatef(0, 1, 0, 0);
glRotatef(180, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(70.0, 11.0, 0.1);
glDisable(GL_LIGHTING);
rectoria.prisma2(techo.GLindex, 0);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Muro ojo de agua derecha
glTranslatef(-165.4, -59.0, 111.5);
glRotatef(0, 1, 0, 0);
glRotatef(180, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(28.0, 3.0, 3.0);
glDisable(GL_LIGHTING);
rectoria.prisma2(techo.GLindex, techo.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Muro ojo de agua iquierda
glTranslatef(-165.4, -59.0, 177.0);
glRotatef(0, 1, 0, 0);
glRotatef(180, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(28.0, 3.0, 3.0);
glDisable(GL_LIGHTING);
rectoria.prisma2(techo.GLindex, techo.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Muro ojo de agua frente
glTranslatef(-181.0, -59.0, 144.0);
glRotatef(0, 1, 0, 0);
glRotatef(90, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(68.0, 3.0, 3.0);
glDisable(GL_LIGHTING);
rectoria.prisma2(techo.GLindex, techo.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Agua ojo de agua
glTranslatef(-165.0, -59.0, 144.0);
glRotatef(0, 1, 0, 0);
glRotatef(90, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(64.0, 0.1, 28.5);
glDisable(GL_LIGHTING);
rectoria.prisma2(0, agua.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Amarillo trasero
glTranslatef(-151.0, -30.0, 143.0);
glRotatef(0, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(90, 0, 0, 1);
glScalef(30.0, 65.0, 0.1);
glDisable(GL_LIGHTING);
rectoria.prisma2(rectoria_azulejos.GLindex, 0);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Azul frontal
glTranslatef(-151.2, -38.0, 143.0);
glRotatef(270, 1, 0, 0);
glRotatef(90, 0, 1, 0);
glRotatef(90, 0, 0, 1);
glScalef(65.0, 6.0, 0.1);
glDisable(GL_LIGHTING);
rectoria.prisma2(rectoria_ventanas.GLindex, 0);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Amarillo frontal
glTranslatef(-83.0, -30.0, 143.0);
glRotatef(0, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(90, 0, 0, 1);
glScalef(30.0, 65.0, 0.1);
glDisable(GL_LIGHTING);
rectoria.prisma2(rectoria_azulejos.GLindex, 0);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Azul frontal
glTranslatef(-82.8, -38.0, 143.0);
glRotatef(90, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(90, 0, 0, 1);
glScalef(65.0, 6.0, 0.1);
glDisable(GL_LIGHTING);
rectoria.prisma2(rectoria_ventanas.GLindex, 0);
glEnable(GL_LIGHTING);
glPopMatrix();

////////////////////////////////

glPushMatrix(); //Edificio anexo escaleras 1
glTranslatef(-82.0, -55.3, 143.3);
glRotatef(0, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(67.0, 0.5, 3.0);
glDisable(GL_LIGHTING);
rectoria.prisma2(biblioteca_desagues.GLindex, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Edificio anexo escaleras 2
glTranslatef(-81.0, -56.0, 143.3);
glRotatef(0, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(67.0, 0.5, 3.0);
glDisable(GL_LIGHTING);
rectoria.prisma2(biblioteca_desagues.GLindex, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Edificio anexo escaleras 3
glTranslatef(-80.0, -56.8, 143.3);
glRotatef(0, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(67.0, 0.5, 3.0);
glDisable(GL_LIGHTING);
rectoria.prisma2(biblioteca_desagues.GLindex, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Edificio anexo escaleras 4
glTranslatef(-79.0, -57.6, 143.3);
glRotatef(0, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(67.0, 0.5, 3.0);
glDisable(GL_LIGHTING);
rectoria.prisma2(biblioteca_desagues.GLindex, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

//////////////////////////

glPushMatrix(); //Mural derecha rectoria
glTranslatef(-160.0, -34.0, 60.0);
glRotatef(0, 1, 0, 0);
glRotatef(360, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(45.0, 20.0, 20.0);
glDisable(GL_LIGHTING);
rectoria.prisma2(rectoria_mural_derecha.GLindex, techo.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

////////////////////////

glPushMatrix(); //Columna derecha rectoria 1
glTranslatef(-140.0, -57.5, 50.5);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna derecha rectoria 2
glTranslatef(-144.0, -57.5, 50.5);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna derecha rectoria 3
glTranslatef(-148.0, -57.5, 50.5);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna derecha rectoria 4
glTranslatef(-152.0, -57.5, 50.5);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna derecha rectoria 5
glTranslatef(-156.0, -57.5, 50.5);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna derecha rectoria 6
glTranslatef(-160.0, -57.5, 50.5);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna derecha rectoria 7
glTranslatef(-164.0, -57.5, 50.5);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna derecha rectoria 8
glTranslatef(-168.0, -57.5, 50.5);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna derecha rectoria 9
glTranslatef(-172.0, -57.5, 50.5);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna derecha rectoria 10
glTranslatef(-176.0, -57.5, 50.5);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna derecha rectoria 11
glTranslatef(-180.0, -57.5, 50.5);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

/////////////////////////////////

glPushMatrix(); //Columna izquierda rectoria 1
glTranslatef(-140.0, -57.5, 69.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna izquierda rectoria 2
glTranslatef(-144.0, -57.5, 69.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna izquierda rectoria 3
glTranslatef(-148.0, -57.5, 69.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna izquierda rectoria 4
glTranslatef(-152.0, -57.5, 69.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna izquierda rectoria 5
glTranslatef(-156.0, -57.5, 69.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna izquierda rectoria 6
glTranslatef(-160.0, -57.5, 69.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna izquierda rectoria 7
glTranslatef(-164.0, -57.5, 69.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna izquierda rectoria 8
glTranslatef(-168.0, -57.5, 69.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna izquierda rectoria 9
glTranslatef(-172.0, -57.5, 69.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna izquierda rectoria 10
glTranslatef(-176.0, -57.5, 69.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna izquierda rectoria 11
glTranslatef(-180.0, -57.5, 69.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

//////////////////

glPushMatrix(); //Columna trasera rectoria 1
glTranslatef(-182.0, -57.5, 66.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna trasera rectoria 2
glTranslatef(-182.0, -57.5, 62.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna trasera rectoria 3
glTranslatef(-182.0, -57.5, 58.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

glPushMatrix(); //Columna trasera rectoria 4
glTranslatef(-182.0, -57.5, 54.0);
glRotatef(180, 1, 0, 0);
glRotatef(270, 0, 1, 0);
glRotatef(180, 0, 0, 1);
glScalef(1.0, 1.0, 1.0);
glDisable(GL_LIGHTING);
rectoria.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
glEnable(GL_LIGHTING);
glPopMatrix();

}



//POSGRADO DE ARQUITECTURA
void PosgradoArquitectura(){
//PARTE TRASERA Y LETRERO
glPushMatrix();
glTranslatef(29, 64, -8);
prisma1.prisma(40, 56, 20, marble.GLindex);
glTranslatef(1, -35, 0);
prisma1.prisma(33, 58, 20, piedra.GLindex);
glTranslatef(-18, 25, 8);
prisma1.prisma(10, 15, 5, suelocuadros.GLindex);
glPopMatrix();
//AUDITORIO
glPushMatrix();
glTranslatef(-235, 25, -9);
prisma1.prisma(20, 30, 15, marble.GLindex);

glPopMatrix();

glPushMatrix();

//PLANO CON TEXTURA TRASERA
glTranslatef(-180, 13, -20);

glDisable(GL_LIGHTING);
glBindTexture(GL_TEXTURE_2D, paredroja.GLindex);
glBegin(GL_QUADS);
glTexCoord2f(0.0f, 0.0f);
glVertex3f(0, 0, 0);
glTexCoord2f(4.5f, 0.0f);
glVertex3f(190, 0, 0);
glTexCoord2f(4.5f, 4.5f);
glVertex3f(190, 25, 0);
glTexCoord2f(0.0f, 4.5f);
glVertex3f(0, 25, 0);
glEnd();
glEnable(GL_LIGHTING);


glTranslatef(0, 24, 0.1);

glDisable(GL_LIGHTING);
glBindTexture(GL_TEXTURE_2D, ventanas2.GLindex);
glBegin(GL_QUADS);
glTexCoord2f(0.0f, 0.0f);
glVertex3f(0, 0, 0);
glTexCoord2f(1.3f, 0.0f);
glVertex3f(200, 0, 0);
glTexCoord2f(1.3f, 1.3f);
glVertex3f(200, 10, 0);
glTexCoord2f(0.0f, 1.3f);
glVertex3f(0, 10, 0);
glEnd();
glEnable(GL_LIGHTING);

glTranslatef(-18, -24, 0.1);

glDisable(GL_LIGHTING);
glBindTexture(GL_TEXTURE_2D, puertapos.GLindex);
glBegin(GL_QUADS);
glTexCoord2f(0.0f, 0.0f);
glVertex3f(0, 0, 0);
glTexCoord2f(1.0f, 0.0f);
glVertex3f(20, 0, 0);
glTexCoord2f(1.0f, 1.0f);
glVertex3f(20, 33, 0);
glTexCoord2f(0.0f, 1.0f);
glVertex3f(0, 33, 0);
glEnd();
glEnable(GL_LIGHTING);


glPopMatrix();

for (int i = 1; i <= 7; i++){


	glPushMatrix();

	//Cilindros con Orilla de Concreto parte baja

	glTranslatef(0, 10, 0);
	prisma1.cilindro(1, 25, 30, concretoPosgradoArquitectura.GLindex);
	glTranslatef(-15, 0, 0);
	prisma1.cilindro(1, 30, 30, concretoPosgradoArquitectura.GLindex);
	glTranslatef(-15, 0, 0);
	prisma1.cilindro(1, 25, 30, concretoPosgradoArquitectura.GLindex);
	glTranslatef(2, 25, -8);
	prisma1.prisma(2, 7, 20, concretoPosgradoArquitectura.GLindex);
	glTranslatef(11.5, 5, 0);
	glPushMatrix();
	glRotatef(30, 0, 0, 1);
	prisma1.prisma(2, 20, 20, concretoPosgradoArquitectura.GLindex);
	glPopMatrix();
	glTranslatef(12, 5, 0);
	prisma1.prisma(2, 9, 20, concretoPosgradoArquitectura.GLindex);
	glTranslatef(4.5, -5, 0);
	prisma1.prisma(12, 2, 20, concretoPosgradoArquitectura.GLindex);

	//Cuerpo de las ventanas
	glTranslatef(-5, 26, 0);
	prisma1.prisma(40, 8, 20, ventanaposgrado1.GLindex);
	glTranslatef(5, -2.5, 0);
	prisma1.prisma(35, 2, 20, ventanaposgrado2.GLindex);

	glTranslatef(-10.5, 1.5, -0.1);
	for (int i = 1; i <= 6; i++){
		float alturaincremento = 40;
		glPushMatrix();
		glRotatef(3, 0, 0, 1);
		prisma1.prisma(alturaincremento, 5, 20, ventanaposgrado1.GLindex);
		alturaincremento = alturaincremento + 0.9;
		glPopMatrix();
		glTranslatef(-3.1, -2, 0);
	}

	glTranslatef(-0, 2, 0);
	prisma1.prisma(40, 3, 20, ventanaposgrado1.GLindex);

	//Cemento de arriba

	glTranslatef(-1, 20, 0);
	prisma1.prisma(2, 3, 20, concretoPosgradoArquitectura.GLindex);

	glTranslatef(11.5, 7, 0.1);
	glPushMatrix();
	glRotatef(34, 0, 0, 1);
	prisma1.prisma(2, 25, 20, concretoPosgradoArquitectura.GLindex);
	glPopMatrix();

	glTranslatef(14, 6.5, 0);
	prisma1.prisma(2, 10, 20, concretoPosgradoArquitectura.GLindex);

	glTranslatef(4, -5, 0);
	prisma1.prisma(9, 2, 20, concretoPosgradoArquitectura.GLindex);

	glTranslatef(-29.5, -6, 0.1);
	prisma1.prisma(6, 3, 20, concretoPosgradoArquitectura.GLindex);


	glPopMatrix();

	glTranslatef(-30, 0, 0);
}

//Parte Trasera Edificio

//MARBLE
glPushMatrix();
glTranslatef(-7, 55, -8);
prisma1.prisma(38, 15, 20, marble.GLindex);
glPopMatrix();

glPushMatrix();
glTranslatef(-29, 56, -8);
glPushMatrix();
glRotatef(-1.5, 0, 0, 1);
prisma1.prisma(38, 30, 20, marble.GLindex);
glPopMatrix();

glPopMatrix();

//CONCRETO
glPushMatrix();
glTranslatef(-8, 35, -8);
prisma1.prisma(2, 13, 20, concretoPosgradoArquitectura.GLindex);
glTranslatef(-20.5, 0.9, 0);
glPushMatrix();
glRotatef(-2, 0, 0, 1);
prisma1.prisma(2.1, 32, 20, concretoPosgradoArquitectura.GLindex);
glPopMatrix();
glPopMatrix();

glPushMatrix();
glTranslatef(-8, 75, -8);
prisma1.prisma(2, 13, 20, concretoPosgradoArquitectura.GLindex);

glTranslatef(-19.5, 0.9, 0);
glPushMatrix();
glRotatef(-2, 0, 0, 1);
prisma1.prisma(2.1, 32, 20, concretoPosgradoArquitectura.GLindex);
glPopMatrix();

//CONCRETO CON TEXTURAS DE MURAL Y VENTANAS

glTranslatef(-16, -11, -0.2);
prisma1.prisma(26, 1, 20, muralPos.GLindex);
glTranslatef(-0.5, -19, -0.1);
prisma1.prisma(19, 1, 20, ventanaspos.GLindex);

glPopMatrix();

//COLUMNAS ROJAS

glPushMatrix();
glTranslatef(-2, 22, -8);
prisma1.prisma(23.5, 2, 20, paredroja.GLindex);
glTranslatef(-7, 3, -5);
prisma1.prisma(23.5, 2, 20, paredroja.GLindex);
//Columna Blanca
glTranslatef(-7, -1.5, 14);
prisma1.prisma(23.5, 3, 2, marblewhite.GLindex);
glTranslatef(-13, 0, 0);
prisma1.prisma(23.5, 3, 2, marblewhite.GLindex);
glTranslatef(-13, 0, 0);
prisma1.prisma(23.5, 3, 2, marblewhite.GLindex);
glTranslatef(0, 0, -5);
prisma1.prisma(23.5, 3, 3, marblewhite.GLindex);
glTranslatef(0, 0, -6);
prisma1.prisma(23.5, 3, 3, marblewhite.GLindex);
glTranslatef(0, 0, -6);
prisma1.prisma(23.5, 3, 3, marblewhite.GLindex);
glPopMatrix();


}

//DERECHO
void Derecho(){
	//Elementos para la facultad de Filosofia/Derecho

	///////////////////////////////////////////////						

	glPushMatrix(); //Muro escaleras filosofia 1
	glTranslatef(11.5, -43.0, -86.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(25.0, 25.0, 0.7);
	glDisable(GL_LIGHTING);
	derecho.prisma2(piedra.GLindex, piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Muro escaleras filosofia 2
	glTranslatef(33.5, -45.5, -86.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(20.0, 20.0, 0.7);
	glDisable(GL_LIGHTING);
	derecho.prisma2(piedra.GLindex, piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Muro escaleras filosofia 3
	glTranslatef(52.0, -48.0, -86.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(18.0, 15.0, 0.7);
	glDisable(GL_LIGHTING);
	derecho.prisma2(piedra.GLindex, piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//Techo escaleras rectoria

	glPushMatrix(); //Muro escaleras filosofia 1
	glTranslatef(11.5, -21.0, -95.2);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(25.0, 2.0, 18.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Muro escaleras filosofia 2
	glTranslatef(33.5, -25.5, -95.2);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(18.0, 2.0, 18.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Techo escaleras filosofia 3
	glTranslatef(52.0, -30.0, -95.2);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(18.0, 2.0, 18.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Techo escaleras filosofia 4
	glTranslatef(85.5, -35.0, -95.2);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(55.0, 2.0, 18.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//Columnas escaleras Filosofia

	glPushMatrix(); //Columna 1 piso 1
	glTranslatef(52.0, -30.0, -95.2);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	//derecho.cilindro(0.4, 15.0, 3, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//Escaleras Filosofia

	glPushMatrix(); //Escaleras filosofia 1
	glTranslatef(11.5, -42.0, -95.2);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(25.0, 0.4, 18.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Escaleras filosofia 2
	glTranslatef(22.0, -43.0, -95.2);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(5.0, 0.4, 18.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Escaleras filosofia 3
	glTranslatef(24.0, -44.0, -95.2);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(5.0, 0.4, 18.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Escaleras filosofia 4
	glTranslatef(26.0, -45.0, -95.2);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(5.0, 0.4, 18.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Escaleras filosofia 5
	glTranslatef(28.0, -46.0, -95.2);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(5.0, 0.4, 18.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Escaleras filosofia 6
	glTranslatef(30.0, -47.0, -95.2);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(5.0, 0.4, 18.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Escaleras filosofia 7
	glTranslatef(32.0, -48.0, -95.2);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(5.0, 0.4, 18.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Escaleras filosofia 8
	glTranslatef(34.0, -49.0, -95.2);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(5.0, 0.4, 18.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Escaleras filosofia 9
	glTranslatef(36.0, -50.0, -95.2);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(5.0, 0.4, 18.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Escaleras filosofia 10
	glTranslatef(38.0, -51.0, -95.2);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(5.0, 0.4, 18.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Escaleras filosofia 11
	glTranslatef(40.0, -52.0, -95.2);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(5.0, 0.4, 18.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Escaleras filosofia 11
	glTranslatef(42.0, -53.0, -95.2);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(5.0, 0.4, 18.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Escaleras filosofia 12
	glTranslatef(44.0, -54.0, -95.2);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(5.0, 0.4, 18.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Escaleras filosofia ultimas
	glTranslatef(52.0, -55.5, -95.2);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(18.0, 0.4, 18.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//Columnas escaleras filos

	glPushMatrix(); //Columna filosofia -1
	glTranslatef(47.0, -56.0, -88.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.4, 27.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna filosofia 0
	glTranslatef(47.0, -56.0, -103.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.4, 27.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna filosofia 1
	glTranslatef(59.5, -56.0, -88.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.4, 27.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna filosofia 2
	glTranslatef(59.5, -56.0, -103.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.4, 27.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna filosofia 3
	glTranslatef(1.0, -41.0, -89.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.4, 20.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna filosofia 4
	glTranslatef(1.0, -41.0, -103.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.4, 20.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna filosofia 5
	glTranslatef(22.0, -41.0, -89.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.4, 20.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna filosofia 6
	glTranslatef(22.0, -41.0, -103.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.4, 20.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna filosofia 7
	glTranslatef(41.0, -51.5, -88.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.4, 25.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna filosofia 8
	glTranslatef(41.0, -51.5, -103.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.4, 25.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna filosofia 9
	glTranslatef(25.0, -45.5, -88.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.4, 20.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna filosofia 10
	glTranslatef(25.0, -45.5, -103.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.4, 20.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna filosofia 11
	glTranslatef(110.0, -55.5, -88.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.4, 20.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna filosofia 12
	glTranslatef(110.0, -55.5, -103.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.4, 20.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna filosofia 13
	glTranslatef(85.0, -55.5, -88.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.4, 20.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna filosofia 14
	glTranslatef(85.0, -55.5, -103.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.4, 20.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	////////////////////////

	glPushMatrix(); //Muro facultad de filosofia
	glTranslatef(29.0, -33.5, -105.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(62.0, 45.0, 0.1);
	glDisable(GL_LIGHTING);
	derecho.prisma2(piedra.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Techo facultad filosofía
	glTranslatef(29.0, -11.0, -105.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(62.0, 2.0, 2.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(techo.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//Techos facultad derecho

	glPushMatrix(); //Techo facultad derecho 1 arriba
	glTranslatef(265.0, -32.0, -131.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(410.0, 3.0, 50.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Techo facultad derecho 2 arriba
	glTranslatef(265.0, -11.5, -131.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(410.0, 3.0, 50.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Techo facultad derecho 3 arriba
	glTranslatef(265.0, 11.0, -131.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(410.0, 3.0, 50.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Techo facultad derecho 4 arriba
	glTranslatef(265.0, 31.5, -131.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(410.0, 3.0, 50.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Techo facultad derecho 0 izquierda
	glTranslatef(58.0, -13.5, -130.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(50.0, 92.0, 3.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(techo.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Techo facultad derecho 0 derecha
	glTranslatef(468.5, -13.5, -130.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(50.0, 92.0, 3.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(techo.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Techo facultad fondo
	glTranslatef(261.5, -13.5, -155.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(0, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(410.0, 92.0, 3.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(techo.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Techo facultad derecho 1
	glTranslatef(265.0, -32.0, -105.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(410.0, 3.0, 2.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Techo facultad derecho 2
	glTranslatef(265.0, -11.5, -105.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(410.0, 3.0, 2.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Techo facultad derecho 3
	glTranslatef(265.0, 11.0, -105.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(410.0, 3.0, 2.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Techo facultad derecho 4
	glTranslatef(265.0, 31.5, -105.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(410.0, 3.0, 2.0);
	glDisable(GL_LIGHTING);
	derecho.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//PRIMER PAR
	//Columnas filosofia
	glPushMatrix(); //Cilindro 1 filosofia
	glTranslatef(64.0, 30.0, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.7, 89.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Cilindro 2 filosofia
	glTranslatef(80.0, 30.0, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.7, 89.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Cilindro 3 filosofia
	glTranslatef(96.0, 30.0, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.7, 89.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Cilindro 4 filosofia
	glTranslatef(112.0, 30.0, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.7, 89.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Barandal filosofia 1
	glTranslatef(87.5, -26.0, -104.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(53.0, 5.0, 0.1);
	glDisable(GL_LIGHTING);
	derecho.prisma2(derecho_barandales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Barandal filosofia 2
	glTranslatef(87.5, -5.0, -104.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(53.0, 5.0, 0.1);
	glDisable(GL_LIGHTING);
	derecho.prisma2(derecho_barandales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Barandal filosofia 3
	glTranslatef(87.5, 17.0, -104.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(53.0, 5.0, 0.1);
	glDisable(GL_LIGHTING);
	derecho.prisma2(derecho_barandales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Vitral izquierda 1
	glTranslatef(160.5, 20.0, -105.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(91.0, 19.0, 0.1);
	glDisable(GL_LIGHTING);
	derecho.prisma2(derecho_vitrales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Vitral izquierda 2
	glTranslatef(160.5, -1.0, -105.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(91.0, 19.0, 0.1);
	glDisable(GL_LIGHTING);
	derecho.prisma2(derecho_vitrales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Vitral izquierda 3
	glTranslatef(160.5, -21.0, -105.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(91.0, 19.0, 0.1);
	glDisable(GL_LIGHTING);
	derecho.prisma2(derecho_vitrales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//SEGUNDO PAR
	//Vitrales derecho			

	glPushMatrix(); //Vitral derecha 1
	glTranslatef(301.0, 20.0, -105.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(82.0, 19.0, 0.1);
	glDisable(GL_LIGHTING);
	derecho.prisma2(derecho_vitrales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Vitral derecha 2
	glTranslatef(301.0, -1.0, -105.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(82.0, 19.0, 0.1);
	glDisable(GL_LIGHTING);
	derecho.prisma2(derecho_vitrales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Vitral derecha 3
	glTranslatef(301.0, -21.0, -105.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(82.0, 19.0, 0.1);
	glDisable(GL_LIGHTING);
	derecho.prisma2(derecho_vitrales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//Columnas derecho

	glPushMatrix();

	glTranslatef(145.0, 0.0, 0.0);

	glPushMatrix(); //Cilindro 1 derecho
	glTranslatef(64.0, 30.0, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.7, 89.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Cilindro 2 derecho
	glTranslatef(80.0, 30.0, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.7, 89.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Cilindro 3 derecho
	glTranslatef(96.0, 30.0, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.7, 89.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Cilindro 4 derecho
	glTranslatef(112.0, 30.0, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.7, 89.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Barandal derecho 1
	glTranslatef(87.5, -26.0, -104.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(53.0, 5.0, 0.1);
	glDisable(GL_LIGHTING);
	derecho.prisma2(derecho_barandales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Barandal derecho 2
	glTranslatef(87.5, -5.0, -104.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(53.0, 5.0, 0.1);
	glDisable(GL_LIGHTING);
	derecho.prisma2(derecho_barandales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Barandal derecho 3
	glTranslatef(87.5, 17.0, -104.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(53.0, 5.0, 0.1);
	glDisable(GL_LIGHTING);
	derecho.prisma2(derecho_barandales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//TERCER PAR

	glPushMatrix();

	glTranslatef(136.0, 0.0, 0.0);

	glPushMatrix(); //Cilindro 1 derecho
	glTranslatef(64.0, 30.0, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.7, 89.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Cilindro 2 derecho
	glTranslatef(80.0, 30.0, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.7, 89.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Cilindro 3 derecho
	glTranslatef(96.0, 30.0, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.7, 89.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Cilindro 4 derecho
	glTranslatef(112.0, 30.0, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(0.7, 89.0, 4, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Barandal derecho 1
	glTranslatef(87.5, -26.0, -104.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(53.0, 5.0, 0.1);
	glDisable(GL_LIGHTING);
	derecho.prisma2(derecho_barandales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Barandal derecho 2
	glTranslatef(87.5, -5.0, -104.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(53.0, 5.0, 0.1);
	glDisable(GL_LIGHTING);
	derecho.prisma2(derecho_barandales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Barandal derecho 3
	glTranslatef(87.5, 17.0, -104.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(53.0, 5.0, 0.1);
	glDisable(GL_LIGHTING);
	derecho.prisma2(derecho_barandales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Vitral derecha 1
	glTranslatef(152.0, 20.0, -105.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(74.0, 19.0, 0.1);
	glDisable(GL_LIGHTING);
	derecho.prisma2(derecho_vitrales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Vitral derecha 2
	glTranslatef(152.0, -1.0, -105.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(74.0, 19.0, 0.1);
	glDisable(GL_LIGHTING);
	derecho.prisma2(derecho_vitrales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Vitral derecha 3
	glTranslatef(152.0, -21.0, -105.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(74.0, 19.0, 0.1);
	glDisable(GL_LIGHTING);
	derecho.prisma2(derecho_vitrales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPopMatrix();

	//COLUMNAS INFERIORES

	//Primer bloque
	glPushMatrix(); //Columna 1
	glTranslatef(-22.0, -33.5, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(1.2, 25.0, 4, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna 2
	glTranslatef(-4.5, -33.5, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(1.2, 25.0, 4, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna 3
	glTranslatef(13.5, -33.5, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(1.2, 25.0, 4, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna 4
	glTranslatef(32.0, -33.5, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(1.2, 25.0, 4, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna 5
	glTranslatef(50.0, -33.5, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(1.2, 25.0, 4, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//Segundo bloque
	glPushMatrix();

	glTranslatef(143.0, 0.0, 0.0);

	glPushMatrix(); //Columna 1
	glTranslatef(-22.0, -33.5, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(1.2, 25.0, 4, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna 2
	glTranslatef(-4.5, -33.5, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(1.2, 25.0, 4, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna 3
	glTranslatef(13.5, -33.5, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(1.2, 25.0, 4, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna 4
	glTranslatef(32.0, -33.5, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(1.2, 25.0, 4, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna 5
	glTranslatef(50.0, -33.5, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(1.2, 25.0, 4, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	glPopMatrix();

	//Tercer bloque
	glPushMatrix();

	glTranslatef(275.0, 0.0, 0.0);
	glScalef(0.9, 1.0, 1.0);

	glPushMatrix(); //Columna 1
	glTranslatef(-22.0, -33.5, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(1.2, 25.0, 4, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna 2
	glTranslatef(-4.5, -33.5, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(1.2, 25.0, 4, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna 3
	glTranslatef(13.5, -33.5, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(1.2, 25.0, 4, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna 4
	glTranslatef(32.0, -33.5, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(1.2, 25.0, 4, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna 5
	glTranslatef(50.0, -33.5, -105.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	derecho.cilindro(1.2, 25.0, 4, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();

}


	//BIBLIOTECA CENTRAL
void BibliotecaCentral(){

	//Figuras biblioteca central:
	glPushMatrix(); //Cupula biblioteca FRONTAL
	glTranslatef(-38.6, 43.0, -57.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(0.1, 9.0, 16.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(biblioteca_cupula.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Cupula biblioteca TRASERA
	glTranslatef(-38.6, 43.0, -67.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(0.1, 9.0, 16.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(biblioteca_cupula.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Cupula biblioteca lateral DERECHA
	glTranslatef(-46.5, 43.0, -62.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(0, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(0.1, 9.0, 10.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(biblioteca_cupula.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Cupula biblioteca lateral IZQUIERDA
	glTranslatef(-30.55, 43.0, -62.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(0.1, 9.0, 10.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(biblioteca_cupula.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Techo Cupula biblioteca
	glTranslatef(-38.5, 47.5, -62.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(16.0, 0.1, 10.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(0, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Mural biblioteca central FRENTE
	glTranslatef(-39.0, 18.0, -54.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(0.1, 42.0, 45.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(mural_frontal.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Mural biblioteca central TRASERA
	glTranslatef(-39.0, 18.0, -70.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(0.1, 42.0, 45.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(mural_frontal.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Mural biblioteca lateral DERECHO
	glTranslatef(-61.5, 18.0, -62.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(15.8, 42.0, 0.1);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(mural_frontal.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Mural biblioteca lateral IZQUIERDO
	glTranslatef(-16.5, 18.0, -62.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(15.8, 42.0, 0.1);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(mural_frontal.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Techo mural biblioteca CENTRAL
	glTranslatef(-39.0, 39.0, -62.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(16.0, 0.1, 45.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(0, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Ventanas biblioteca FRENTE
	glTranslatef(-39.0, -7.0, -54.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(0.1, 8.5, 45.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(biblioteca_ventanas.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Ventanas biblioteca TRASERA
	glTranslatef(-39.0, -7.0, -70.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(0.1, 8.5, 45.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(biblioteca_ventanas.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Ventanas biblioteca DERECHA 
	glTranslatef(-61.5, -7.0, -62.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(0, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(0.1, 8.5, 17.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(biblioteca_ventanas.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Ventanas biblioteca ABAJO
	glTranslatef(-35.5, -17.0, -37.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(0.1, 6.0, 19.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(biblioteca_ventanas.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna entrada biblioteca 1
	glTranslatef(-44.0, -26.0, -37.5);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	biblioteca.cilindro(0.5, 6, 3, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna entrada biblioteca 2
	glTranslatef(-39.0, -26.0, -37.5);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	biblioteca.cilindro(0.5, 6, 3, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna entrada biblioteca 3
	glTranslatef(-34.0, -26.0, -37.5);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	biblioteca.cilindro(0.5, 6, 3, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna entrada biblioteca 4
	glTranslatef(-29.0, -26.0, -37.5);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	biblioteca.cilindro(0.5, 6, 3, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Escalera entrada biblioteca 1
	glTranslatef(-35.4, -26.0, -41.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(8.0, 0.4, 19.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(techo.GLindex, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Escalera entrada biblioteca 2
	glTranslatef(-36.45, -26.5, -37.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(2.0, 0.4, 16.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(techo.GLindex, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Escalera entrada biblioteca 3
	glTranslatef(-36.45, -27.1, -36.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(2.0, 0.4, 16.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(techo.GLindex, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Escalera entrada biblioteca 4
	glTranslatef(-36.45, -27.7, -35.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(2.0, 0.4, 16.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(techo.GLindex, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Pared entrada biblioteca DERECHA
	glTranslatef(-45.0, -20.0, -41.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(0, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(0.1, 12.0, 8.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(techo.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Pared entrada biblioteca DERECHA
	glTranslatef(-25.7, -20.0, -41.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(0, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(0.1, 12.0, 8.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(techo.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Rampa entrada biblioteca
	glTranslatef(-27.4, -26.7, -35.0);
	glRotatef(20, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(4.0, 0.3, 2.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(techo.GLindex, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Vitral lateral IZQUIERDO
	glTranslatef(-16.5, -7.0, -62.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(15.8, 8.5, 0.1);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(biblioteca_ventanas.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Base desague biblioteca central
	glTranslatef(-35.0, -12.5, -54.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(40.0, 3.0, 75.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Vitrales frontales
	glTranslatef(-57.5, -20.6, -37.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(25.0, 13.0, 0.1);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(biblioteca_vitrales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Vitrales laterales DERECHA
	glTranslatef(-70.0, -20.6, -54.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(34.0, 13.0, 0.1);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(biblioteca_vitrales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Vitrales laterales IZQUIERDA
	glTranslatef(-3.0, -20.6, -55.5);
	glRotatef(0, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(31.0, 13.0, 0.1);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(biblioteca_vitrales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Vitrales traseros DERECHOS
	glTranslatef(-14.4, -20.6, -40.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(0, 0, 1, 0);
	glRotatef(270, 0, 0, 1);
	glScalef(13.0, 22.4, 0.1);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(biblioteca_vitrales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Vitrales delanteros IZQUIERDO
	glTranslatef(-64.0, -20.6, -71.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(270, 0, 0, 1);
	glScalef(13.0, 12.0, 0.1);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(biblioteca_vitrales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna entrada biblioteca patio 1
	glTranslatef(-23.7, -26.5, -37.5);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	biblioteca.cilindro(0.4, 12.5, 3, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna entrada biblioteca patio 2
	glTranslatef(-19.7, -26.5, -37.5);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	biblioteca.cilindro(0.4, 12.5, 3, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna entrada biblioteca patio 3
	glTranslatef(-15.7, -26.5, -37.5);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	biblioteca.cilindro(0.4, 12.5, 3, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna entrada biblioteca patio 4
	glTranslatef(-11.7, -26.5, -37.5);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	biblioteca.cilindro(0.4, 12.5, 3, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna entrada biblioteca patio 5
	glTranslatef(-7.7, -26.5, -37.5);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	biblioteca.cilindro(0.4, 12.5, 3, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna entrada biblioteca patio 5
	glTranslatef(-3.7, -26.5, -37.5);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	biblioteca.cilindro(0.4, 12.5, 3, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	
	
	glPushMatrix(); //Roca DERECHA
	glTranslatef(-25.5, -22.0, -26.0);
	glRotatef(0,1,0,0);
	glRotatef(90,0,1,0);
	glRotatef(180,0,0,1);
	glScalef(21.0, 13.0, 0.1);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(biblioteca_roca.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	
	glPushMatrix(); //Roca IQUIERDA
	glTranslatef(-2.3, -22.0, -27.5);
	glRotatef(0,1,0,0);
	glRotatef(270,0,1,0);
	glRotatef(180,0,0,1);
	glScalef(24.0, 13.0, 0.1);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(biblioteca_roca.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Roca FRONTAL
	glTranslatef(-14.0, -22.0, -15.5);
	glRotatef(0,1,0,0);
	glRotatef(180,0,1,0);
	glRotatef(180,0,0,1);
	glScalef(23.0, 13.0, 0.1);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(biblioteca_roca2.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	
	glPushMatrix(); //Piso patio
	glTranslatef(-14.0, -28.0, -28.0);
	glRotatef(90,1,0,0);
	glRotatef(180,0,1,0);
	glRotatef(180,0,0,1);
	glScalef(23.0, 25.0, 0.1);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(biblioteca_desagues.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	
	

	glPushMatrix(); //Fuente biblioteca
	glTranslatef(-50.0, -20.6, -71.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(0, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(17.0, 13.0, 0.1);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(biblioteca_fuente.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Base fuente trasera FRENTE
	glTranslatef(-50.0, -27.0, -85.5);
	glRotatef(90, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(270, 0, 0, 1);
	glScalef(0.5, 3.0, 16.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(techo.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Base fuente trasera lateral DERECHA
	glTranslatef(-58.0, -27.0, -78.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(270, 0, 0, 1);
	glScalef(3.0, 0.5, 15.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(techo.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Base fuente trasera lateral IZQUIERDA
	glTranslatef(-42.0, -27.0, -78.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(270, 0, 0, 1);
	glScalef(3.0, 0.5, 15.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(techo.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Agua fuente
	glTranslatef(-50.0, -27.0, -78.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(90, 0, 1, 0);
	glRotatef(0, 0, 0, 1);
	glScalef(15.0, 0.1, 15.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(0, agua.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Vitrales traseros IZQUIERDO
	glTranslatef(-17.0, -20.6, -71.0);
	glRotatef(0, 1, 0, 0);
	glRotatef(180, 0, 1, 0);
	glRotatef(270, 0, 0, 1);
	glScalef(13.0, 28.0, 0.1);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(biblioteca_vitrales.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna entrada trasera biblioteca 1
	glTranslatef(-38.5, -26.0, -72.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	biblioteca.cilindro(0.3, 13, 3, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Columna entrada trasera biblioteca 2
	glTranslatef(-33.5, -26.0, -72.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glDisable(GL_LIGHTING);
	biblioteca.cilindro(0.3, 13, 3, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Escalera entrada trasera biblioteca 1
	glTranslatef(-36.0, -26.0, -70.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(5.0, 0.4, 10.5);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(techo.GLindex, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Escalera entrada trasera biblioteca 1
	glTranslatef(-36.0, -26.6, -70.5);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(5.0, 0.4, 10.5);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(techo.GLindex, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Escalera entrada trasera biblioteca 1
	glTranslatef(-36.0, -27.2, -71.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(5.0, 0.4, 10.5);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(techo.GLindex, biblioteca_desagues.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Pared entrada trasera biblioteca DERECHA
	glTranslatef(-41.5, -20.0, -69.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(0, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(0.1, 12.0, 4.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(techo.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Pared entrada trasera biblioteca IZQUIERDA
	glTranslatef(-31.0, -20.0, -69.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(0, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(0.1, 12.0, 4.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(techo.GLindex, 0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix(); //Base desague biblioteca central
	glTranslatef(-3.0, -27.5, -54.0);
	glRotatef(180, 1, 0, 0);
	glRotatef(270, 0, 1, 0);
	glRotatef(180, 0, 0, 1);
	glScalef(40.0, 0.8, 5.0);
	glDisable(GL_LIGHTING);
	biblioteca.prisma2(biblioteca_desagues.GLindex, techo.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


}





//FUNCIONES PARA HACER EL TERRENO
void cuadropasto()
{
	glPushMatrix();
	glTranslatef(5.0, 0.0, 0.0);
	prisma1.prisma(10, 7, 7, pastocuadros.GLindex);
	glPushMatrix();
	glTranslatef(4.25, 0, 0);
	prisma1.prisma(10, 1.5, 7, suelocuadros.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-4.25, 0, 0);
	prisma1.prisma(10, 1.5, 7, suelocuadros.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 0, 4.25);
	prisma1.prisma(10, 10, 1.5, suelocuadros.GLindex);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0, 0, -4.25);
	prisma1.prisma(10, 10, 1.5, suelocuadros.GLindex);
	glPopMatrix();

	glPopMatrix();

}



void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glPushMatrix();

	glRotatef(g_lookupdown, 1.0f, 0, 0);

	gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
		objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
		objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);


	glPushMatrix();
	glPushMatrix(); //Creamos cielo
	glDisable(GL_LIGHTING);
	glTranslatef(0, 0, 0);

	fig1.skybox(5000, 5000, 5000, text1.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();
	
	//Globo
	glPushMatrix();
		glTranslatef(200.0, 100.0, 0.0);
		glTranslatef(mov_globo_X, mov_globo_Y, mov_globo_Z);
		glRotatef(0, 1, 0, 0);
		glRotatef(180, 0, 1, 0);
		glRotatef(180, 0, 0, 1);
		glScalef(1.0, 1.0, 1.0);
		glDisable(GL_LIGHTING);
		prisma1.esfera(5, 10, 10, globo.GLindex);
		prisma1.cilindro(0.1, 14, 10, 0);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	//Leonardita
	glPushMatrix();
	glTranslatef(491 , -13, 65);
	glDisable(GL_LIGHTING);
	prisma1.cilindro(1, 50, 50, paredamarilla.GLindex); //cilindro. Altura 2do parametro
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(490, 52, 65);
	glDisable(GL_LIGHTING);
	glutWireSphere(15,30,30);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//COLOCANDO ZONA DE COMERCIO
	glPushMatrix();
	glTranslatef(30, 5, 78);
	glScalef(0.23, 1, 1);
	glRotatef(180, 0, 1, 0);
	ZonadeComercio.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();
	

	//COLOCANDO ARQUITECTURA
	
	glPushMatrix();
	glTranslatef(360, 3, 108);
	glRotatef(-270, 0, 1, 0);
	glScalef(0.2, 1, 0.35);
	Arquitectura.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();
	

	//COLOCANDO TALLER
	
	glPushMatrix();
	glTranslatef(505, -9, 35);
	glRotatef(-180, 0, 1, 0);
	glScalef(0.3, 1, 0.2);
	Taller.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	//ARBOLES TALLER
	glPushMatrix();
	glTranslatef(525, -13, 50);
	glScalef(2, 2, 2);
	arbol1();
	glTranslatef(0, 0, 8);
	arbol2();
	glPopMatrix();
	
	//COLOCANDO DERECHO
	glPushMatrix();
	glScalef(0.7, 0.7, 0.7);
	glTranslatef(605, 15, -470);
	Derecho();
	glPopMatrix();

	//COLOCANDO RECTORÍA
	glPushMatrix();
	glScalef(0.8, 0.8, 0.8);
	glTranslatef(395, 66, -240);
	Rectoria();
	glPopMatrix();

	//COLOCANDO BIBLIOTECA CENTRAL
	glPushMatrix();
	glTranslatef(422, 50, -201);
	glScalef(1.9, 1.9, 1.9);
	BibliotecaCentral();
	glPopMatrix();

	//COLOCANDO ANEXO DE DERECHO
	glPushMatrix();
	glTranslatef(985.5, -28, -248.5);
	glScalef(0.2, 0.2, 0.2);
	glRotatef(-90, 0, 1, 0);
	AnexoDerecho.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	//COLOCANDO DGOSE
	glPushMatrix();
	glTranslatef(615, -25, 0);
	glScalef(0.1, 0.1, 0.1);
	glRotatef(-90, 0, 1, 0);
	DGOSE.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	//COLOCANDO POSGRADO ARQUITECTURA

	glPushMatrix();
	glTranslatef(1050, -40, -22);
	glScalef(0.8, 0.8, 0.9);
	glRotatef(-90, 0, 1, 0);
	PosgradoArquitectura();
	glPopMatrix();

	//COLOCANDO TORRE DE HUMANIDADES

	glPushMatrix();
	glTranslatef(1200, -27, -300);
	glScalef(0.5, 0.5, 0.5);
	glRotatef(-90, 0, 1, 0);
	TorreDeHumanidades.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	//COLOCANDO INGENIERIA
	
	glPushMatrix();
	glTranslatef(950, -28.5, 61.5);
	glScalef(0.25, 0.25, 0.25);
	glRotatef(-90, 0, 1, 0);
	Ingenieria.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();
	
	//TEXTURA ESTADIO
	glPushMatrix();
	glTranslatef(-5, 29, -18);
	glDisable(GL_LIGHTING);
	prisma1.prisma(50, 10, 46, estadio1.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5, 80, -145);
	glDisable(GL_LIGHTING);
	prisma1.prisma(100, 10, 205, estadio2.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();




	//AVION

	glPushMatrix();
	glTranslatef(-400, 300, 0);
	glScalef(0.01, 0.01, 0.01);
	glTranslatef(movavionx, movaviony, movavionz);
	glRotatef(angRotavion, 0, 1, 0);
	turbosonic.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();

	
	//BOTE

	glPushMatrix();
	glTranslatef(190, 5, -97);
	glScalef(0.05, 0.05, 0.05);
	glTranslatef(mov_barco_x,0,mov_barco_z);
	glRotatef(angRotbote, 0, 1, 0);
	bote.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();






	//CUADROPASTO ENTRE 2 CICLOPISTAS 
	glPushMatrix();
	glTranslatef(0, 0, 10);
	for (int i = 1; i <= 32; i++){
		glDisable(GL_LIGHTING);
		cuadropasto();
		glEnable(GL_LIGHTING);
		glTranslatef(9, 0, 0);
	}
	glPopMatrix();

	//PISO CONCRETO
	glPushMatrix();
	glTranslatef(3.5, 4.5, 19.5); //18.5
	for (int i = 1; i <= 41; i++){
		glDisable(GL_LIGHTING);
		prisma1.prisma(1, 7, 9, concreto.GLindex);
		glEnable(GL_LIGHTING);
		glTranslatef(7, 0, 0);
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(287, 4.5, 19.5);
	glDisable(GL_LIGHTING);
	prisma1.prisma(1, 3.2, 9, concreto.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//PISO ZONA ARQUITECTURA
	glPushMatrix();
	glTranslatef(284.4, -0.2, 28.5);//41
	glDisable(GL_LIGHTING);
	prisma1.prisma(9.7, 8.5, 9, sueloarqui.GLindex); //34
	glEnable(GL_LIGHTING);
	glPopMatrix();


	/*escalera costado arqui
	escalerasArqui(289.5,4.3);*/

	//escalera del costado piso arqui
	float transx = 289.5;
	float transy = 4.3;

	for (int i = 1; i <= 4; i++)
	{
		glPushMatrix();
		glTranslatef(transx, transy, 28.5);
		glDisable(GL_LIGHTING);
		prisma1.prisma(1, 1.7, 9, pisoescaleras.GLindex);
		glEnable(GL_LIGHTING);
		transx = transx + 1.7;
		transy = transy - 1;
		glPopMatrix();
	}

	//escalón largo
	glPushMatrix();
	glTranslatef(297.3, 0.3, 28.5);
	glDisable(GL_LIGHTING);
	prisma1.prisma(1, 5, 8.7, pisoescaleras.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	float transx2 = 300.7;
	float transy2 = -0.5; //-0.7

	for (int i = 1; i <= 4; i++) //con la función
	{
		glPushMatrix();
		glTranslatef(transx2, transy2, 28.5);
		glDisable(GL_LIGHTING);
		prisma1.prisma(1, 1.7, 9, pisoescaleras.GLindex);
		glEnable(GL_LIGHTING);
		transx2 = transx2 + 1.7;
		transy2 = transy2 - 1;
		glPopMatrix();
	}


	//Escaleras frente a arqui (Hacerlo con la función)
	float transy3 = 4.3; //x 307.6
	float transz3 = 32.5; //y 4.3

	for (int i = 1; i <= 7; i++)
	{
		glPushMatrix();
		glTranslatef(347, transy3, transz3); //28.5
		glDisable(GL_LIGHTING);
		prisma1.prisma(1, 105, 1.5, pisoescaleras.GLindex);
		glEnable(GL_LIGHTING);
		transz3 = transz3 - 1.5;
		transy3 = transy3 - 1;
		glPopMatrix();
	}

	//CONTINUA PISO ARQUI
	glPushMatrix();
	glTranslatef(290, 0.42, 43.5); //324.5 0.46

	for (int j = 0; j <= 2; j++){
		for (int i = 0; i <= 5; i++){
			glDisable(GL_LIGHTING);
			prisma1.prisma(8.5, 20, 20, sueloarqui.GLindex); //89
			glEnable(GL_LIGHTING);
			glTranslatef(20, 0, 0);
		}
		glTranslatef(-120,0,20);
	}
	glPopMatrix();


	//PLATAFORMA DE ZONA DE COMERCIO
	glPushMatrix();
	glTranslatef(3.5, 0.4, 28.2); //-4, 28.2

	//glPushMatrix();
	for (int i = 1; i <= 40; i++){
		for (int i = 1; i <= 4; i++){
			glDisable(GL_LIGHTING);
			prisma1.prisma(10.8, 7, 8.5, suelodepiedra.GLindex);
			glEnable(GL_LIGHTING);
			glTranslatef(0, 0, 8.5);
		}
		//glPopMatrix();
		glTranslatef(7, 0, -34);
	}
	glPopMatrix();


	//CICLOPISTA
	glPushMatrix();
	glTranslatef(2, 4.51, 6.6); //glTranslatef(2,4.51,4.96);
	for (int i = 1; i <= 63; i++){
		glDisable(GL_LIGHTING);
		prisma1.prisma(1, 4, 3, tartan.GLindex);
		glEnable(GL_LIGHTING);
		glTranslatef(4, 0, 0);
	}
	glPopMatrix();

	//continúa ciclopista lado izquierdo
	glPushMatrix();
	glTranslatef(255, 4.51, 6.6);
	for (int i = 1; i <= 9; i++){
		glDisable(GL_LIGHTING);
		prisma1.prisma(1, 4, 3, tartan.GLindex);
		glEnable(GL_LIGHTING);
		glTranslatef(4, 0, 0);
	}
	glPopMatrix();

	//DESVIACIÓN CICLOPISTA
	glPushMatrix();
	glTranslatef(253, 4.51, 9.3);
	glDisable(GL_LIGHTING);
	prisma1.prisma(1, 3, 8.5, tartan.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//continúa ciclopista lado derecho
	glPushMatrix();
	glTranslatef(253.5, 4.51, 13.5);
	for (int i = 1; i <= 9; i++){
		glDisable(GL_LIGHTING);
		prisma1.prisma(1, 4, 3, tartan.GLindex);
		glEnable(GL_LIGHTING);
		glTranslatef(4, 0, 0);
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(287, 4.51, 13.5);
	glDisable(GL_LIGHTING);
	prisma1.prisma(1, 3.9, 3, tartan.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	//RAMPA IZQ CICLOPISTA 
	glPushMatrix();
	glTranslatef(299.2, 0.81, 6.6);
	glDisable(GL_LIGHTING);
	glRotatef(-20, 0, 0, 1);
	prisma1.prisma(1, 22, 3, tartan.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	//RAMPA DER CICLOPISTA 
	glPushMatrix();
	glTranslatef(299.1, 0.82, 13.5);
	glDisable(GL_LIGHTING);
	glRotatef(-20, 0, 0, 1);
	prisma1.prisma(1, 22, 3, tartan.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//RAMPA CONCRETO1
	glPushMatrix();
	glTranslatef(299.1, 0.82, 10);
	glDisable(GL_LIGHTING);
	glRotatef(-20, 0, 0, 1);
	prisma1.prisma(1, 22, 4, concreto.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//RAMPA CONCRETO2
	glPushMatrix();
	glTranslatef(298.6, -0.7, 19.5);   //0.82
	glDisable(GL_LIGHTING);
	glRotatef(-20, 0, 0, 1);
	prisma1.prisma(4, 22, 9, concreto.GLindex); //1
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//CICLOPISTA BAJO RAMPA IZQ
	glPushMatrix();
	glTranslatef(319, -2.5, 6.6);
	glDisable(GL_LIGHTING);
	prisma1.prisma(1, 22, 3, tartan.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(341, -2.5, 6.6);
	glDisable(GL_LIGHTING);
	prisma1.prisma(1, 22, 3, tartan.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(362, -2.5, 6.6);
	glDisable(GL_LIGHTING);
	prisma1.prisma(1, 21.8, 3, tartan.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//BAJO RAMPA CONCRETO1
	glPushMatrix();
	glTranslatef(319, -2.5, 10);
	glDisable(GL_LIGHTING);
	prisma1.prisma(1, 22, 3.8, concreto.GLindex); //3
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(341, -2.5, 10);
	glDisable(GL_LIGHTING);
	prisma1.prisma(1, 22, 3.8, concreto.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(362, -2.5, 10);
	glDisable(GL_LIGHTING);
	prisma1.prisma(1, 21.8, 3.8, concreto.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//CICLOPISTA BAJO RAMPA DER
	glPushMatrix();
	glTranslatef(319, -2.5, 13.5);
	glDisable(GL_LIGHTING);
	prisma1.prisma(1, 22, 3, tartan.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(341, -2.5, 13.5);
	glDisable(GL_LIGHTING);
	prisma1.prisma(1, 22, 3, tartan.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(362, -2.5, 13.5);
	glDisable(GL_LIGHTING);
	prisma1.prisma(1, 21.8, 3, tartan.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//BAJO RAMPA CONCRETO2
	glPushMatrix();
	glTranslatef(319, -2.5, 19.5);
	glDisable(GL_LIGHTING);
	prisma1.prisma(1, 22, 9, concreto.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(341, -2.5, 19.5);
	glDisable(GL_LIGHTING);
	prisma1.prisma(1, 22, 9, concreto.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(362, -2.5, 19.5);
	glDisable(GL_LIGHTING);
	prisma1.prisma(1, 21.8, 9, concreto.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();











	//ARBOLES ZONA DE ARRIBA
	//COLOCACIÓN DE ÁRBOLES ISLAS

	glPushMatrix();
	glTranslatef(50, 5, -20);
	arbol2();
	glTranslatef(50,0 ,-5 );
	arbol3();
	glTranslatef(0, 0, -10);
	arbol1();
	glTranslatef(0, 0, -10);
	arbol2();
	glTranslatef(0, 0, -10);
	arbol4();
	glTranslatef(-10, 0,10);
	arbol2();
	glTranslatef(0, 0, 10);
	arbol3();
	glTranslatef(0, 0, 10);
	arbol2();
	glTranslatef(0, 0, 10);
	arbol1();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(280, 5, -100);
	glScalef(2, 2, 2);
	arbol1();
	glTranslatef(-10, 0, 10);
	arbol2();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(370, -5, -70);
	glScalef(2, 2, 2);
	arbol1();
	glTranslatef(-8, 0, 0);
	arbol2();
	glTranslatef(0, 0, 8);
	arbol3();
	glTranslatef(8, 0, 0);
	arbol4();
	glTranslatef(0, 0, -16);
	arbol2();
	glTranslatef(-8, 0, 0);
	arbol1();

	glPopMatrix();


		//ESCLAERAS EXPLANADA ROJA
		glPushMatrix();
		glTranslatef(17, 3, -68);
		glRotatef(-90, 0, 1, 0);
		int escaleras2xaladorectoria = -60;
		int escaleras2yaladorectoria = 23;
		float escalerastrasl2aladorectoria = -38;
		for (int i = 1; i <= 10; i++){
			glPushMatrix();
			glTranslatef(escaleras2xaladorectoria, escaleras2yaladorectoria, escalerastrasl2aladorectoria);
			glDisable(GL_LIGHTING);
			prisma1.prisma(10, 2, 16, piedra.GLindex);
			glEnable(GL_LIGHTING);
			escaleras2xaladorectoria = escaleras2xaladorectoria + 2;
			escaleras2yaladorectoria = escaleras2yaladorectoria - 1;
			glTranslatef(0, 0, -16);
			glDisable(GL_LIGHTING);
			prisma1.prisma(10, 2, 16, piedra.GLindex);
			glEnable(GL_LIGHTING);
			glTranslatef(0, 0, -16);
			glDisable(GL_LIGHTING);
			prisma1.prisma(10, 2, 16, piedra.GLindex);
			glEnable(GL_LIGHTING);
			glTranslatef(0, 0, -16);
			glDisable(GL_LIGHTING);
			prisma1.prisma(10, 2, 16, piedra.GLindex);
			glEnable(GL_LIGHTING);
			glTranslatef(0, 0, -16);
			glDisable(GL_LIGHTING);
			prisma1.prisma(10, 2, 16, piedra.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
		}
		glPopMatrix();



		glPushMatrix();
		glTranslatef(187, 3, -100);
		glRotatef(360, 0, 1, 0);
		int escaleras2xaladorectoria2x = -60;
		int escaleras2yaladorectoria2y= 23;
		float escalerastrasl2aladorectoria2l = -38;
		for (int i = 1; i <= 20; i++){
			glPushMatrix();
			glTranslatef(escaleras2xaladorectoria2x, escaleras2yaladorectoria2y, escalerastrasl2aladorectoria2l);
			glDisable(GL_LIGHTING);
			prisma1.prisma(10, 2, 16, piedra.GLindex);
			glEnable(GL_LIGHTING);
			escaleras2xaladorectoria2x = escaleras2xaladorectoria2x + 2;
			escaleras2yaladorectoria2y = escaleras2yaladorectoria2y - 1;
			glTranslatef(0, 0, -16);
			glDisable(GL_LIGHTING);
			prisma1.prisma(10, 2, 16, piedra.GLindex);
			glEnable(GL_LIGHTING);
			glTranslatef(0, 0, -16);
			glDisable(GL_LIGHTING);
			prisma1.prisma(10, 2, 16, piedra.GLindex);
			glEnable(GL_LIGHTING);
			glTranslatef(0, 0, -16);
			glDisable(GL_LIGHTING);
			prisma1.prisma(10, 2, 16, piedra.GLindex);
			glEnable(GL_LIGHTING);
			glTranslatef(0, 0, -16);
			glDisable(GL_LIGHTING);
			prisma1.prisma(10, 2, 16, piedra.GLindex);
			glEnable(GL_LIGHTING);
			glTranslatef(0, 0, -16);
			glDisable(GL_LIGHTING);
			prisma1.prisma(10, 2, 16, piedra.GLindex);
			glEnable(GL_LIGHTING);

			glPopMatrix();
		}
		glPopMatrix();

		//EXPLANADA ROJA
		glPushMatrix();
		glTranslatef(20, 29, -138);

		for (int i = 1; i <= 5; i++){
			for (int j = 1; j <= 7; j++){
				
				glDisable(GL_LIGHTING);
				prisma1.prisma(3, 20, 20, suelorojo.GLindex);
				glEnable(GL_LIGHTING);
				glTranslatef(16, 0, 0);
			}
			glTranslatef(-112, 0, -20);
		}
		glPopMatrix();

		//PIEDRAS A LADO EXPLANADA ROJA
		glPushMatrix();
		glTranslatef(24, 22, -50);
		glDisable(GL_LIGHTING);
		prisma1.prisma(35, 47, 20, piedra.GLindex);
		glEnable(GL_LIGHTING);
		glTranslatef(13, 0, -44);
		glDisable(GL_LIGHTING);
		prisma1.prisma(35, 20, 68, piedra.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(137, 22, -106);
		glDisable(GL_LIGHTING);
		prisma1.prisma(35, 20, 47, piedra.GLindex);
		glEnable(GL_LIGHTING);

		glPopMatrix();

		glPushMatrix();
		glTranslatef(63, 22, -238);
		glDisable(GL_LIGHTING);
		prisma1.prisma(35, 125, 20, piedra.GLindex);
		glEnable(GL_LIGHTING);

		glTranslatef(0, 0, -55);
		glDisable(GL_LIGHTING);
		prisma1.prisma(35, 125, 20, piedra.GLindex);
		glEnable(GL_LIGHTING);
		/*
		glTranslatef(143, 30, -50);
		glDisable(GL_LIGHTING);
		prisma1.prisma(150, 155, 20, fondo1biblio.GLindex);
		glEnable(GL_LIGHTING);
		*/
		glPopMatrix();


		//Segunda parte larga escaleras piedra
		glPushMatrix();
		glTranslatef(17, 3, -68);
		glRotatef(-90, 0, 1, 0);
		glDisable(GL_LIGHTING);
		glTranslatef(-38, 17, -38);
		prisma1.prisma(3, 6, 16, piedra.GLindex);
		glEnable(GL_LIGHTING);
		for (int i = 1; i <= 4; i++){
			glTranslatef(0, 0, -16);
			glDisable(GL_LIGHTING);
			prisma1.prisma(3, 6, 16, piedra.GLindex);
			glEnable(GL_LIGHTING);
		}
		glPopMatrix();

		glPushMatrix();
		glTranslatef(17, 3, -68);
		glRotatef(-90, 0, 1, 0);
		int escaleras2x2aladorectoria = -35;
		int escaleras2y2aladorectoria = 13;
		float escalerastrasl2dosaladorectoria = -38;
		for (int i = 1; i <= 13; i++){
			glPushMatrix();
			glTranslatef(escaleras2x2aladorectoria, escaleras2y2aladorectoria, escalerastrasl2dosaladorectoria);
			glDisable(GL_LIGHTING);
			prisma1.prisma(10, 2, 16, piedra.GLindex);
			glEnable(GL_LIGHTING);
			escaleras2x2aladorectoria = escaleras2x2aladorectoria + 2;
			escaleras2y2aladorectoria = escaleras2y2aladorectoria - 1;
			glTranslatef(0, 0, -16);
			glDisable(GL_LIGHTING);
			prisma1.prisma(10, 2, 16, piedra.GLindex);
			glEnable(GL_LIGHTING);
			glTranslatef(0, 0, -16);
			glDisable(GL_LIGHTING);
			prisma1.prisma(10, 2, 16, piedra.GLindex);
			glEnable(GL_LIGHTING);
			glTranslatef(0, 0, -16);
			glDisable(GL_LIGHTING);
			prisma1.prisma(10, 2, 16, piedra.GLindex);
			glEnable(GL_LIGHTING);
			glTranslatef(0, 0, -16);
			glDisable(GL_LIGHTING);
			prisma1.prisma(10, 2, 16, piedra.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();
		}
		glPopMatrix();


		//PASO DE PILARES A LADO DE RECTORIA
		glPushMatrix();
		glTranslatef(190, 5, -400);
		glRotatef(90, 0, 1, 0);
		for (int i = 1; i <= 25; i++){
			glDisable(GL_LIGHTING);
			prisma1.cilindro(0.5, 10, 30, concretopilar.GLindex);
			glTranslatef(0, 0, 10);
			prisma1.cilindro(0.5, 10, 30, concretopilar.GLindex);
			glTranslatef(0, 10, -5);
			prisma1.prisma(2, 10, 13, paredroja.GLindex);
			glEnable(GL_LIGHTING);
			glTranslatef(-10, -10, -5);
		}
		glPopMatrix();


		//SUELO BIBLIOTECA CENTRAL
		glPushMatrix();
		glTranslatef(298, -5, -240.1);

		for (int i = 1; i <= 5; i++){
			for (int j = 1; j <= 7; j++){

				glDisable(GL_LIGHTING);
				prisma1.prisma(3, 20, 20, paredroja.GLindex);
				glEnable(GL_LIGHTING);
				glTranslatef(16, 0, 0);
			}
			glTranslatef(-112, 0, -20);
		}
		glPopMatrix();
		
		//PIEDRAS BAJO MURAL BIBLIOTECA CENTRAL
		glPushMatrix();
		glTranslatef(398, -20, -250);
		for (int i = 1; i <= 4; i++){
			glDisable(GL_LIGHTING);
			prisma1.prisma(35, 49, 40, piedra.GLindex);
			glEnable(GL_LIGHTING);
		
			glTranslatef(0, 0, -40);
		}

		glPopMatrix();

	//CUADROS PARTE ARRIBA DOBLE FOR
	float posicionI = -9;
	float posicionJ = 0;
	for (int i = 1; i <= 45; i++){

		posicionJ = 0;
		posicionI = posicionI + 9;

		for (int j = 1; j <= 32; j++){
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(posicionJ, 0, -posicionI);
			cuadropasto();
			glEnable(GL_LIGHTING);
			posicionJ = posicionJ + 9;
			glPopMatrix();
		}
	}
	//231
	//ESCALERAS PRIMERAS
	int escaleras1x = 290;
	int escaleras1y = 0;
	float escalerastrasl = -18;
	for (int i = 1; i <= 4; i++){
		glPushMatrix();
		glTranslatef(escaleras1x, escaleras1y, escalerastrasl);
		glDisable(GL_LIGHTING);
		prisma1.prisma(10, 2, 46.2, pisoescalera1.GLindex);
		glEnable(GL_LIGHTING);
		escaleras1x = escaleras1x + 2;
		escaleras1y = escaleras1y - 1;

		glTranslatef(0, 0, -46.2);
		glDisable(GL_LIGHTING);
		prisma1.prisma(10, 2, 46.2, pisoescalera1.GLindex);
		glEnable(GL_LIGHTING);
		glTranslatef(0, 0, -46.2);
		glDisable(GL_LIGHTING);
		prisma1.prisma(10, 2, 46.2, pisoescalera1.GLindex);
		glEnable(GL_LIGHTING);
		glTranslatef(0, 0, -46.2);
		glDisable(GL_LIGHTING);
		prisma1.prisma(10, 2, 46.2, pisoescalera1.GLindex);
		glEnable(GL_LIGHTING);
		glTranslatef(0, 0, -46.2);
		glDisable(GL_LIGHTING);
		prisma1.prisma(10, 2, 46.2, pisoescalera1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();
	}

	glTranslatef(298, 0, 0);//Moviéndome a la esquina donde empiezan escaleras1 


	//Escalon Grande
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(0, 0, -18);
	prisma1.prisma(3, 6, 46.2, pisoescalera1.GLindex);
	glEnable(GL_LIGHTING);
	for (int i = 1; i <= 4; i++){
		glTranslatef(0, 0, -46.2);
		glDisable(GL_LIGHTING);
		prisma1.prisma(3, 6, 46.2, pisoescalera1.GLindex);
		glEnable(GL_LIGHTING);
	}
	glPopMatrix();

	//Escaleras primeras segunda parte

	int escaleras1x1 = 4;
	int escaleras1y1 = -3.5;
	float escalerastrasl1 = -18;
	for (int i = 1; i <= 4; i++){
		glPushMatrix();
		glTranslatef(escaleras1x1, escaleras1y1, escalerastrasl1);
		glDisable(GL_LIGHTING);
		prisma1.prisma(10, 2, 46.2, pisoescalera1.GLindex);
		glEnable(GL_LIGHTING);
		escaleras1x1 = escaleras1x1 + 2;
		escaleras1y1 = escaleras1y1 - 1;

		glTranslatef(0, 0, -46.2);
		glDisable(GL_LIGHTING);
		prisma1.prisma(10, 2, 46.2, pisoescalera1.GLindex);
		glEnable(GL_LIGHTING);
		glTranslatef(0, 0, -46.2);
		glDisable(GL_LIGHTING);
		prisma1.prisma(10, 2, 46.2, pisoescalera1.GLindex);
		glEnable(GL_LIGHTING);
		glTranslatef(0, 0, -46.2);
		glDisable(GL_LIGHTING);
		prisma1.prisma(10, 2, 46.2, pisoescalera1.GLindex);
		glEnable(GL_LIGHTING);
		glTranslatef(0, 0, -46.2);
		glDisable(GL_LIGHTING);
		prisma1.prisma(10, 2, 46.2, pisoescalera1.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();
	}


	glTranslatef(11, -7, 0);//Moviéndome a la esquina donde TERMINAN ESCALERAS 1

	//PIEDRA FALTANTE PARA LLEGAR A ARQUITECTURA 
	
	glPushMatrix();
	glTranslatef(84, -6, 20);
	glDisable(GL_LIGHTING);
	prisma1.prisma(20, 40, 30, piedra.GLindex);
	glEnable(GL_LIGHTING);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(118, -4, 20);
	glDisable(GL_LIGHTING);
	glRotatef(-10, 0, 0, 1);
	prisma1.prisma(10, 30, 40, piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(158, -7, 20);
	glDisable(GL_LIGHTING);
	prisma1.prisma(10, 50, 40, piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(197, -9, 20);
	glDisable(GL_LIGHTING);
	glRotatef(-10, 0, 0, 1);
	prisma1.prisma(10, 30, 40, pasto.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(220, -11, 20);
	glDisable(GL_LIGHTING);
	
	prisma1.prisma(10, 30, 40, pasto.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	//CUADRO SEÑORA BASURA A LADO ARQUI

	glPushMatrix();
	glTranslatef(91, -10, 65);
	glDisable(GL_LIGHTING);
	glScalef(6, 4, 6);
	cuadropasto();
	glEnable(GL_LIGHTING);
	glPopMatrix();
	

	glPushMatrix();
	glTranslatef(110, 10, 80);
	glScalef(2, 2, 2);
	arbol1();
	glTranslatef(8, 0, 0);
	arbol2();
	glTranslatef(8, 0, 0);
	arbol3();
	glTranslatef(0, 0, -8);
	arbol4();
	glTranslatef(-8, 0, 0);
	arbol1();
	glTranslatef(-8, 0, 0);
	arbol2();
	glTranslatef(0, 0, -8);
	arbol3();
	glTranslatef(8, 0, 0);
	arbol4();
	glTranslatef(8, 0, 0);
	arbol1();
	glPopMatrix();
	

	//RAMPA FRENTE ARQUI
	glPushMatrix();
	glTranslatef(165, -10, 59);
	glDisable(GL_LIGHTING);
	glRotatef(10, 1, 0, 0);
	prisma1.prisma(10, 30, 40, piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(193, -13, 70);
	glDisable(GL_LIGHTING);
	prisma1.prisma(10, 85, 100, piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(182, -10, 59);
	glDisable(GL_LIGHTING);
	glRotatef(10, 1, 0, 0);
	prisma1.prisma(10, 6, 40, piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(210, -12, 59);
	glDisable(GL_LIGHTING);
	prisma1.prisma(10, 50, 40, piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//SEGUNDA SECCION CUADRITOS PASTO
	float posicionI2 = -9;
	float posicionJ2 = 0;
	for (int i = 1; i <= 26; i++){

		posicionJ2 = 0;
		posicionI2 = posicionI2 + 9;

		for (int j = 1; j <= 7; j++){
			glPushMatrix();
			glDisable(GL_LIGHTING);
			glTranslatef(posicionJ2, 0, -posicionI2);
			cuadropasto();
			glEnable(GL_LIGHTING);
			posicionJ2 = posicionJ2 + 9;
			glPopMatrix();
		}
	}

	glTranslatef(64, 0, 0); //Moviéndome a la esquina finalizando cuadropastos

	glPushMatrix();
	glTranslatef(25, -2.5, -15);
	glDisable(GL_LIGHTING);
	glRotatef(-5, 0, 0, 1);
	prisma1.prisma(10, 50, 40, piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(25, -15, -95);
	glDisable(GL_LIGHTING);
	prisma1.prisma(40, 50, 120, piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();



	glTranslatef(30, 0, 0); //Moviéndome a la esquina del primer cuadro de piedra

	glPushMatrix();
	glTranslatef(33.5, -7, -15);
	glDisable(GL_LIGHTING);
	glRotatef(-10, 0, 0, 1);
	prisma1.prisma(10, 30, 40, piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glTranslatef(30, 0, 0); //Moviéndome a la esquina del segundo cuadro de piedra

	glPushMatrix();
	glTranslatef(3, -13, -52);
	glDisable(GL_LIGHTING);
	glRotatef(-10, 1, 0, 0);
	prisma1.prisma(10, 30, 40, piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glTranslatef(0, -8, -77); //Moviéndome a la esquina del tercer cuadro de piedra

	glPushMatrix();
	glTranslatef(3, -13, -14);
	glDisable(GL_LIGHTING);
	glRotatef(-10, 1, 0, 0);
	prisma1.prisma(10, 30, 40, piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glTranslatef(0, -8, -14); //Moviéndome a la esquina del cuarto cuadro de piedra

	glPushMatrix();
	glTranslatef(3, -9, -25);
	glDisable(GL_LIGHTING);
	glRotatef(-10, 1, 0, 0);
	prisma1.prisma(10, 30, 10, piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glTranslatef(0, -8, -33); //Moviéndome a la esquina del quinto PEQUEÑO cuadro de piedra

	glPushMatrix();
	glTranslatef(3, -2, -35);
	glDisable(GL_LIGHTING);
	prisma1.prisma(10, 30, 110, piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(16, -1.9, -110);
	glDisable(GL_LIGHTING);
	prisma1.prisma(10, 55, 320, piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();



	//ESCALERAS DE PIEDRA

	//Primera parte escaleras piedra
	glPushMatrix();
	//glTranslatef(-60, 23, -65);
	int escaleras2x = -60;
	int escaleras2y = 23;
	float escalerastrasl2 = -38;
	for (int i = 1; i <= 10; i++){
		glPushMatrix();
		glTranslatef(escaleras2x, escaleras2y, escalerastrasl2);
		glDisable(GL_LIGHTING);
		prisma1.prisma(10, 2, 15, piedra.GLindex);
		glEnable(GL_LIGHTING);
		escaleras2x = escaleras2x + 2;
		escaleras2y = escaleras2y - 1;
		glTranslatef(0, 0, -15);
		glDisable(GL_LIGHTING);
		prisma1.prisma(10, 2, 15, piedra.GLindex);
		glEnable(GL_LIGHTING);
		glTranslatef(0, 0, -15);
		glDisable(GL_LIGHTING);
		prisma1.prisma(10, 2, 15, piedra.GLindex);
		glEnable(GL_LIGHTING);
		glTranslatef(0, 0, -15);
		glDisable(GL_LIGHTING);
		prisma1.prisma(10, 2, 15, piedra.GLindex);
		glEnable(GL_LIGHTING);
		glTranslatef(0, 0, -15);
		glDisable(GL_LIGHTING);
		prisma1.prisma(10, 2, 15, piedra.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();
	}
	glPopMatrix();
	//Segunda parte larga escaleras piedra
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glTranslatef(-38, 17, -38);
	prisma1.prisma(3, 6, 15, piedra.GLindex);
	glEnable(GL_LIGHTING);
	for (int i = 1; i <= 4; i++){
		glTranslatef(0, 0, -15);
		glDisable(GL_LIGHTING);
		prisma1.prisma(3, 6, 15, piedra.GLindex);
		glEnable(GL_LIGHTING);
	}
	glPopMatrix();

	glPushMatrix();

	int escaleras2x2 = -35;
	int escaleras2y2 = 13;
	float escalerastrasl2dos = -38;
	for (int i = 1; i <= 13; i++){
		glPushMatrix();
		glTranslatef(escaleras2x2, escaleras2y2, escalerastrasl2dos);
		glDisable(GL_LIGHTING);
		prisma1.prisma(10, 2, 15, piedra.GLindex);
		glEnable(GL_LIGHTING);
		escaleras2x2 = escaleras2x2 + 2;
		escaleras2y2 = escaleras2y2 - 1;
		glTranslatef(0, 0, -15);
		glDisable(GL_LIGHTING);
		prisma1.prisma(10, 2, 15, piedra.GLindex);
		glEnable(GL_LIGHTING);
		glTranslatef(0, 0, -15);
		glDisable(GL_LIGHTING);
		prisma1.prisma(10, 2, 15, piedra.GLindex);
		glEnable(GL_LIGHTING);
		glTranslatef(0, 0, -15);
		glDisable(GL_LIGHTING);
		prisma1.prisma(10, 2, 15, piedra.GLindex);
		glEnable(GL_LIGHTING);
		glTranslatef(0, 0, -15);
		glDisable(GL_LIGHTING);
		prisma1.prisma(10, 2, 15, piedra.GLindex);
		glEnable(GL_LIGHTING);
		glPopMatrix();
	}
	glPopMatrix();


	glPushMatrix();
	//125 = 1/3 de las islas de largo
	glTranslatef(100, -2, -190);
	glDisable(GL_LIGHTING);
	prisma1.prisma(10, 125, 50, piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(195, -20, -190);
	glDisable(GL_LIGHTING);
	glRotatef(7, 0, 0, 1);
	prisma1.prisma(50, 300, 50, piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//Suelo de piedra a lado de derecho
	glPushMatrix();
		glTranslatef(81, -2, -242.5);
		glRotatef(4, 0, 0, 1);
		for (int i = 1; i <= 4; i++){
			glDisable(GL_LIGHTING);
			
			prisma1.prisma(10, 75, 55, suelopiedra.GLindex);
			glEnable(GL_LIGHTING);
			glTranslatef(75, 0, 0);
		}
	glPopMatrix();

	//Suelo de piedra a lado de derecho
	glPushMatrix();
	glTranslatef(65, -7, -296);
	glRotatef(4, 0, 0, 1);
	for (int i = 1; i <= 4; i++){
		glDisable(GL_LIGHTING);

		prisma1.prisma(10, 75, 55, suelopiedra.GLindex);
		glEnable(GL_LIGHTING);
		glTranslatef(75, 0, 0);
	}
	glPopMatrix();

	
	//Piedra que baja hacia anexo de Derecho
	glPushMatrix();
	glTranslatef(385, -22, -217);
	glDisable(GL_LIGHTING);
	glRotatef(-20, 0, 0, 1);
	prisma1.prisma(50, 110, 105, piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//Piedra horizontal anexo derecho
	glPushMatrix();
	glTranslatef(400, -22, -215);
	glDisable(GL_LIGHTING);
	prisma1.prisma(50, 100, 100, piedra.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	//Jardin Anexo de Derecho

	glPushMatrix();
	glTranslatef(530, -6, -215);
	glDisable(GL_LIGHTING);
	prisma1.prisma(10, 200, 50, pasto.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(590, 0, -215);
	glScalef(1.5, 1.5, 1.5);
	arbol1();
	glTranslatef(-8, 0, 0);
	arbol2();
	glTranslatef(-8, 0, 0);
	arbol3();
	glTranslatef(-8, 0, 0);
	arbol4();
	glTranslatef(-8, 0, 0);
	arbol1();
	glTranslatef(-8, 0, 0);
	arbol2();
	glTranslatef(-8, 0, 0);
	arbol3();
	glTranslatef(-8, 0, 0);
	arbol4();
	glTranslatef(-8, 0, 0);
	arbol1();
	glTranslatef(-8, 0, 0);
	arbol2();
	glTranslatef(-8, 0, 0);
	arbol3();
	glTranslatef(-8, 0, 0);
	arbol4();
	glPopMatrix();

	//Creando terreno de las ISLAS
	//375 largo /5 = 75
	//250 alto /5 = 50
	glPushMatrix();

	glTranslatef(81, -7, 60);

	for (int i = 1; i <= 5; i++){

		for (int j = 1; j <= 6; j++){

			glDisable(GL_LIGHTING);
			prisma1.prisma(20, 75, 50, pasto.GLindex);
			glEnable(GL_LIGHTING);
			glTranslatef(75, 0, 0);
		}
		glTranslatef(-450, 0, -50);

	}
	glPopMatrix();


	glTranslatef(250, 20, -40);  //Moviéndome al centro de las islas
	
	//Suelo Rojo a lado de Posgrado de Arquitectura
	glPushMatrix();
	glTranslatef(281, -32, -25);
	glDisable(GL_LIGHTING);
	prisma1.prisma(30, 75, 200, suelorojo.GLindex);
	glEnable(GL_LIGHTING);
	glTranslatef(58, 0, 25);
	glDisable(GL_LIGHTING);
	prisma1.prisma(30, 40, 250, suelorojo.GLindex);
	glEnable(GL_LIGHTING);

	glPopMatrix();

	glPushMatrix();
	glTranslatef(369, -19, 131);

	for (int i = 1; i <= 20; i++){
		for (int j = 1; j <= 15; j++){

			glDisable(GL_LIGHTING);
			prisma1.prisma(3, 20, 20, paredroja.GLindex);
			glEnable(GL_LIGHTING);
			glTranslatef(20, 0, 0);
		}
		glTranslatef(-300, 0, -20);
	}
	glPopMatrix();


	//PASO CON COLUMNAS A LADO DE INGENIERÍA
	glPushMatrix();
	glTranslatef(350, -17, 128);

	for (int i = 1; i <= 38; i++){
		glDisable(GL_LIGHTING);
		prisma1.cilindro(0.5, 10, 30, concretopilar.GLindex);
		glTranslatef(0, 0, 10);
		prisma1.cilindro(0.5, 10, 30, concretopilar.GLindex);
		glTranslatef(0, 10, -5);
		prisma1.prisma(2, 10, 13, concretoPosgradoArquitectura.GLindex);
		glEnable(GL_LIGHTING);
		glTranslatef(-10, -10, -5);
	}
	glPopMatrix();


	//SUELO A LADO DE INGENIERÍA

	glPushMatrix();
	glTranslatef(-130, -19, 215);

	for (int i = 1; i <= 5; i++){
		for (int j = 1; j <= 30; j++){

			glDisable(GL_LIGHTING);
			prisma1.prisma(3, 20, 20, paredroja.GLindex);
			glEnable(GL_LIGHTING);
			glTranslatef(20, 0, 0);
		}
		glTranslatef(-600, 0, -20);
	}
	glPopMatrix();

	//SUELO PASTO A LADO DGOSE

	glPushMatrix();
	glTranslatef(-245, -19, 200);

	for (int i = 1; i <= 3; i++){
		for (int j = 1; j <= 4; j++){

			glDisable(GL_LIGHTING);
			prisma1.prisma(3, 30, 30, suelopastohoja.GLindex);
			glEnable(GL_LIGHTING);
			glTranslatef(30, 0, 0);
		}
		glTranslatef(-120, 0, -30);
	}
	glPopMatrix();



	//PIEDRA A LADO DGOSE
	glPushMatrix();
	glTranslatef(-185, -10, 163);
	glDisable(GL_LIGHTING);
	prisma1.prisma(30, 92, 5, piedra.GLindex);
	glEnable(GL_LIGHTING);

	glPopMatrix();
	glPushMatrix();
	glTranslatef(-185, -10, 162.9);
	glDisable(GL_LIGHTING);
	prisma1.prisma(29.9, 91.9, 4.9, paredaladodgose.GLindex);
	glEnable(GL_LIGHTING);

	glPopMatrix();

	//ULTIMO CUADRO DE PASTO RESTANTE A LADO DGOSE

	glPushMatrix();
	glTranslatef(-220, -19, 107);
	glDisable(GL_LIGHTING);
	prisma1.prisma(3, 50, 35, pasto.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//ULTIMO CUADRO DE PASTO RESTANTE A LADO POSGRADO ARQUI

	glPushMatrix();
	glTranslatef(282, -19, 100);
	glDisable(GL_LIGHTING);
	prisma1.prisma(3, 77, 50, pasto.GLindex);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	//COLOCACION ARBOLES POR LA DGOSE
	glPushMatrix();
	glTranslatef(-220, -17, 150);
	glScalef(2, 2, 2);
	arbol1();
	glTranslatef(8, 0, 0);
	arbol2();
	glTranslatef(8, 0, 0);
	arbol3();
	glTranslatef(8, 0, 0);
	arbol4();
	glTranslatef(8, 0, 0);
	arbol1();
	glTranslatef(0, 0, -8);
	arbol2();
	glTranslatef(-8, 0, 0);
	arbol3();
	glTranslatef(-8, 0, 0);
	arbol4();
	glTranslatef(-8, 0, 0);
	arbol1();
	glTranslatef(-8, 0, 0);
	arbol2();
	glPopMatrix();
	//ARBOLES POR DERECHO
	glPushMatrix();
	glTranslatef(-200, -17, -160);
	glScalef(2, 2, 2);
	arbol1();
	glTranslatef(8, 0, 0);
	arbol2();
	glTranslatef(8, 0, 0);
	arbol3();
	glTranslatef(8, 0, 0);
	arbol4();
	glTranslatef(8, 0, 0);
	arbol1();
	glTranslatef(8, 0, 0);
	arbol2();
	glTranslatef(8, 0, 0);
	arbol3();
	glTranslatef(8, 0, 0);
	arbol4();
	glTranslatef(8, 1, 0);
	arbol1();
	glTranslatef(8, 0.5, 0);
	arbol2();
	glTranslatef(8, 0.5, 0);
	arbol3();
	glTranslatef(8, 0.5, 0);
	arbol4();
	glTranslatef(8, 1.5, 0);
	arbol1();
	glTranslatef(8, 0.5, 0);
	arbol2();
	glTranslatef(8, 1.5, 0);
	arbol3();
	glTranslatef(8, 1, 0);
	arbol4();
	glTranslatef(8, 1.5, 0);
	arbol1();
	glTranslatef(8, 1, 0);
	arbol2();

	glTranslatef(0, 0, 8);
	arbol3();

	glTranslatef(-8, -1, 0);
	arbol4();
	glTranslatef(-8, -1.5, 0);
	arbol1();
	glTranslatef(-8, -1, 0);
	arbol2();
	glTranslatef(-8, -1.5, 0);
	arbol3();
	glTranslatef(-8, -0.5, 0);
	arbol4();
	glTranslatef(-8, -1.5, 0);
	arbol1();
	glTranslatef(-8, -0.5, 0);
	arbol2();
	glTranslatef(-8, -0.5, 0);
	arbol3();
	glTranslatef(-8, -0.5, 0);
	arbol4();
	glTranslatef(-8, -0.5, 0);
	arbol1();
	glTranslatef(-8, -0.5, 0);
	arbol2();
	glTranslatef(-8, 0, 0);
	arbol3();
	glTranslatef(-8, 0, 0);
	arbol4();
	glTranslatef(-8, 0, 0);
	arbol1();
	glTranslatef(-8, 0, 0);
	arbol2();
	glTranslatef(-8, 0, 0);
	arbol3();
	glTranslatef(-8, 0, 0);
	arbol4();
	glPopMatrix();


	//DESNIVELES ISLAS
	glPushMatrix();
	glTranslatef(-100, -17, -70);
	glScalef(1.5, 1.5, 1.5);
	glDisable(GL_LIGHTING);
	Desnivel.GLrender(NULL, _SHADED, 1.0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(100, -17, -70);
	glScalef(1.5, 1.5, 1.5);
	glRotatef(90, 0, 1, 0);
	glDisable(GL_LIGHTING);
	Desnivel.GLrender(NULL, _SHADED, 1.0);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(80, -17, 70);
	glScalef(1.5, 1.5, 1.5);
	glRotatef(180, 0, 1, 0);
	glDisable(GL_LIGHTING);
	Desnivel.GLrender(NULL, _SHADED, 1.0);
	glEnable(GL_LIGHTING);
	glPopMatrix();


	//COLOCANDO CABEZAS OLMECA
	glPushMatrix();
	glTranslatef(-200, -17, 110);
	glScalef(0.5, 0.5, 0.5);
	for (int i = 1; i <= 9; i++){
		glDisable(GL_LIGHTING);
		Olmeca.GLrender(NULL, _SHADED, 1.0);
		glRotatef(20, 0, 1, 0);
		glEnable(GL_LIGHTING);
		glTranslatef(60, 0, 0);
	}
		glPopMatrix();

	glPushMatrix();
		glTranslatef(150, -17, -100);
		glScalef(0.5, 0.5, 0.5);
		for (int i = 1; i <= 9; i++){
			glDisable(GL_LIGHTING);
			Olmeca.GLrender(NULL, _SHADED, 1.0);
			glRotatef(-20, 0, 1, 0);
			glEnable(GL_LIGHTING);
			glTranslatef(60, 0, 0);
		}
		glPopMatrix();

	//COLOCACIÓN DE ÁRBOLES ISLAS

		glPushMatrix();
		GrupoDeArboles();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(175, 0, -170);
		glRotatef(90, 0, 1, 0);
		GrupoDeArboles();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-20, 0, 0);
		glRotatef(180, 0, 1, 0);
		GrupoDeArboles();
		glPopMatrix();


		







	glColor3f(1.0, 1.0, 1.0);

	glPopMatrix();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 0.0, 0.0);
	pintaTexto(-12, 12.0, -14.0, (void *)font, "Proyecto");
	pintaTexto(-12, 10.5, -14, (void *)font, "Recorrido Virtual Ciudad Universitaria");
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers();

}

void animacion()
{
	fig3.text_izq -= 0.01;
	fig3.text_der -= 0.01;
	if (fig3.text_izq < -1)
		fig3.text_izq = 0;
	if (fig3.text_der < 0)
		fig3.text_der = 1;

	if (play_avion)
	{

		if (movavionx <= 65000){
			movavionx += 600.0;
		}
		if (movavionx > 65000 && movaviony == 0 && movavionz > -35000){
			angRotavion = -360;
			movavionz -= 600.0;
			//printf("%f",movavionz);
			
		}
		if (movavionx > 65000 && movavionx < 140000 && movaviony == 0 && movavionz == -35400){
			angRotavion += 10;
			movavionx += 600.0;
			printf("%f",movavionx);
			//printf("%f",movaviony);
			//printf("%f",movavionz);
		}
		if (movavionx > 140399 && movavionx < 190000 && movavionz == -35400){
			angRotavion += 50;
			movavionx += 600.0;
			movaviony -= 600.0;
			printf("%f", movavionx);
			//printf("%f",movaviony);
			//printf("%f",movavionz);
		}

		if (movavionx == 190200){
			angRotavion = -90;
			movavionx = 0;
			movaviony = 0;
			movavionz = 0;

		}

	}

	if (play_bote){
			switch (bandera_barco){
			case 0:
				angRotbote = 90;
				mov_barco_x -= 4;
				if (mov_barco_x < -300)
					bandera_barco = 1;
				break;

			case 1:
				mov_barco_z += 4;
				angRotbote = 180;
				if (mov_barco_z > 860)
					bandera_barco = 2;
				break;

			case 2:
				angRotbote = 270;
				mov_barco_x += 4;
				if (mov_barco_x > 0)
					bandera_barco = 3;
				break;

			case 3:
				angRotbote = 360;
				mov_barco_z -= 4;
				if (mov_barco_z < 0)
					bandera_barco = 0;
				break;
			}
		}


	

	if (play_globo){
		switch (bandera_globo){
		case 0:
			mov_globo_Y += 0.16;
			mov_globo_X += 0.08;
			mov_globo_Z -= 0.08;
			if (mov_globo_Y > 60)
				bandera_globo = 1;
			break;

		case 1:
			mov_globo_Y += 0.16;
			mov_globo_X -= 0.08;
			mov_globo_Z += 0.08;
			if (mov_globo_Y > 120)
				bandera_globo = 2;
			break;

		case 2:
			mov_globo_Y += 0.16;
			mov_globo_X += 0.08;
			mov_globo_Z -= 0.08;
			if (mov_globo_Y > 180)
				bandera_globo = 3;
			break;

		case 3:
			mov_globo_Y += 0.16;
			mov_globo_X -= 0.08;
			mov_globo_Z += 0.08;
			if (mov_globo_Y > 240)
				bandera_globo = 0;
			break;
		}
	}

	/*
	FRAME++;
	time = glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf(s, "FPS:%4.2f", FRAME*1000.0 / (time - timebase));
		timebase = time;
		FRAME = 0;
	}
	*/


	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 5000);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		objCamera.Move_Camera(CAMERASPEED + 1.2);
		break;

	case 's':
	case 'S':
		objCamera.Move_Camera(-(CAMERASPEED + 1.2));
		break;

	case 'a':
	case 'A':
		objCamera.Strafe_Camera(-(CAMERASPEED + 1.4));
		break;

	case 'd':
	case 'D':
		objCamera.Strafe_Camera(CAMERASPEED + 1.4);
		break;

	case 'r':		//PRIMERA POSICION
	case 'R':
	
		objCamera.Position_Camera(100, 7.0f, 3, 100, 7.0f, 0, 0, 1, 0);
		
		break;

	case 't':		//SEGUNDA POSICION
	case 'T':

		objCamera.Position_Camera(300, 7.0f, 3, 300, 7.0f, 0, 0, 1, 0);

		break;

	case 'y':		//TERCERA POSICION
	case 'Y':

		objCamera.Position_Camera(600, 7.0f, 3, 600, 7.0f, 0, 0, 1, 0);

		break;

	case 'u':		//CUARTA POSICION
	case 'U':

		objCamera.Position_Camera(900, 7.0f, 3, 900, 7.0f, 0, 0, 1, 0);

		break;


	case 'v':
	case 'V':
		
		if (play_avion == false)
		{

			play_avion = true;
		}
		else
		{
			play_avion = false;
		}
		break;

	case 'b':
	case 'B':
		if (play_bote == false)
			play_bote = true;
		else
			play_bote = false;
		break;

		

	case 'n':
	case 'N':
		if (play_globo)
			play_globo = false;
		else
			play_globo = true;
		break;


	case 'l':a++;
		printf("%f x es", a);
		break;
	case 'L':a--;
		printf("%fx es", a);
		break;
	case 'k':b++;
		printf("%f y e", b);
		break;
	case 'K':b--;
		printf("%f y es", b);
		break;

	case 'j':c++;
		printf("%f z es", c);
		break;
	case 'J':c--;
		printf("%f z es", c);
		break;



	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}

	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_PAGE_UP:
		//pos_camY -= 0.5f;
		//pos_cam.y += 0.5f;
		//eye_cam.y += 0.5f;
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		//pos_camY += 0.5f;
		//pos_cam.y -= 0.5f;
		//eye_cam.y -= 0.5f;
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View(CAMERASPEED);
		break;

	default:
		break;
	}
	glutPostRedisplay();
}




int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(1920, 1080);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Proyecto Valencia"); // Nombre de la Ventana
	//glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc		  ( animacion );
	glutMainLoop();          // 

	return 0;
}
