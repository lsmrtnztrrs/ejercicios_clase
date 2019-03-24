//Semestre 2019 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************		Martinez Torres Luis Martin     	******//
//*************											******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol=0, 
mercury=0,
venus=0,
year=0, 
day=0,
moon=0,
mars=0,
jupiter=0,
saturn=0,
urano=0,
neptuno=0;


float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat MercurioDiffuse[] = { 0.0f, 0.3f, 0.3f, 1.0f };			// Mercurio
GLfloat MercurioSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MercurioShininess[] = { 50.0 };

GLfloat VenusDiffuse[] = { 0.0f, 0.3f, 0.3f, 1.0f };			// Venus
GLfloat VenusSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat VenusShininess[] = { 50.0 };


GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

GLfloat JupiterDiffuse[] = { 0.7f, 0.3f, 0.0f, 1.0f };			// Jupiter
GLfloat JupiterSpecular[] = { 1.0, 0.5, 0.0 , 1.0 };
GLfloat JupiterShininess[] = { 50.0 };

GLfloat SaturnDiffuse[] = { 0.7f, 0.3f, 0.0f, 1.0f };			// Jupiter
GLfloat SaturnSpecular[] = { 1.0, 0.5, 0.0 , 1.0 };
GLfloat SaturnShininess[] = { 50.0 };

GLfloat UranoDiffuse[] = { 0.0f, 0.3f, 0.3f, 1.0f };			// Urano
GLfloat UranoSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat UranoShininess[] = { 50.0 };


GLfloat NeptunoDiffuse[] = { 0.0f, 0.3f, 0.3f, 1.0f };			// Neptuno
GLfloat NeptunoSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat NeptunoShininess[] = { 50.0 };



void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	glLightfv(GL_LIGHT1, GL_DIFFUSE, SunDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SunSpecular);
	

	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);

}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX,0.0,-5.0+camaraZ);			//camara
		
	glPushMatrix();
		glRotatef(sol,0.0,1.0,0.0);	//El Sol gira sobre su eje
		glColor3f( 1.0,1.0,0.0 );	//Sol amarillo
		glDisable(GL_LIGHTING);
		glutSolidSphere(1.9,50,50);  //Draw Sun (radio,H,V);
		glEnable(GL_LIGHTING);
		glLightfv(GL_LIGHT1, GL_POSITION, SunPosition);
	glPopMatrix();


	glPushMatrix();
	glRotatef(mercury, 0.0, 0.0, 1.0);
	glTranslatef(5.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MercurioDiffuse);
	glutSolidSphere(0.8, 20, 20); // Mars
	glPopMatrix();

	glPushMatrix();
	glRotatef(venus, 0.0, 0.0, 1.0);
	glTranslatef(9.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, VenusDiffuse);
	glutSolidSphere(0.8, 20, 20); // Mars
	glPopMatrix();
	
	glPushMatrix();
		glRotatef(year, 0.0, 1.0, 0.0);
		glTranslatef(13.0, 0.0, 0.0);
		glPushMatrix();
			glRotatef(day, 0.0, 1.0, 0.0);
			glColor3f(0.0, 1.0, 0.0);
			glMaterialfv(GL_FRONT,GL_DIFFUSE,EarthDiffuse);
			glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);
			glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
			glutSolidSphere(1.0, 20, 20);// Earth
		glPopMatrix();

		glRotatef(moon, 1.0, 0.0, 0.0);
		glTranslatef(0.0, 2.5, 0.0);
		glColor3f(0.6, 0.6, 0.6);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
		glutSolidSphere(0.3, 20, 20); // Moon
	glPopMatrix();


	glPushMatrix();
		glPushMatrix();
			glRotatef(mars, 0.0, 0.0, 1.0);
			glTranslatef(16.5, 0.0, 0.0);
			glColor3f(1.0, 0.0, 0.0);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MarsDiffuse);
			glutSolidSphere(0.8, 20, 20); // Mars
		glPopMatrix();
				glRotatef(moon, 1.0, 0.0, 0.0);
				glTranslatef(0.0, 2.5, 0.0);
				glColor3f(0.6, 0.6, 0.6);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
				glutSolidSphere(0.3, 20, 20); // Moon
		glPopMatrix();

	glPopMatrix();

	glPushMatrix();
		glRotatef(36.0, 0.0, 0.0, 1.0);
		glRotatef(jupiter, 0.0, 1.0, 0.0);
		glTranslatef(-19.0, 0.0, 0.0);
		glColor3f(0.7, 0.3, 0.0);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, JupiterDiffuse);
		glutSolidSphere(1.8, 20, 20); // Jupiter
	glPopMatrix();

	glPushMatrix();
		glRotatef(-43.0, 0.0, 0.0, 1.0);
		glRotatef(saturn, 0.0, 1.0, 0.0);
		glTranslatef(23.0, 0.0, 0.0);
		glColor3f(0.0, 0.5, 0.5);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, SaturnDiffuse);
		glutSolidSphere(1.8, 20, 20); // Saturno
		glColor3f(0.0, 0.3, 0.3);
		glutSolidTorus(0.2, 2.1, 2, 30);
	glPopMatrix();


	glPushMatrix();
	glRotatef(urano, 0.0, 0.0, 1.0);
	glTranslatef(27, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, UranoDiffuse);
	glutSolidSphere(0.8, 20, 20); // Urano
	glPopMatrix();



	glPushMatrix();
	glRotatef(neptuno, 0.0, 0.0, 1.0);
	glTranslatef(30, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, NeptunoDiffuse);
	glutSolidSphere(0.8, 20, 20); // Neptuno
	glPopMatrix();


	glutSwapBuffers ( );

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if(dwElapsedTime >= 30)
	{

		mercury = (mercury - 3) % 360;
		venus = (venus - 4) % 360;
		sol = (sol - 5) % 360;
		year = (year + 5) % 360;
		day = (day + 20) % 360;
		moon = (moon + 5) % 360;
		mars = (mars - 5) % 360;
		jupiter = (jupiter + 6) % 360;
		saturn = (saturn -8) % 360;
		urano = (urano - 6) % 360;
		neptuno = (neptuno - 5) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 'i':		
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   
		case 'L':
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		
		break;
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6 Sistema Solar"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}