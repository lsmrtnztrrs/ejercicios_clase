//Semestre 2019 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
#include "Main.h"
void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Poner aqui codigo ha dibujar


	 //C
	glBegin(GL_POLYGON);


	glVertex3f(1.0, 1.0, 0.0); //V1
	glVertex3f(4.0, 1.0, 0.0); //V2
	glVertex3f(4.0, 2.0, 0.0); //V3
	glVertex3f(2.0, 2.0, 0.0); //V4
	glVertex3f(2.0, 4.0, 0.0); //V5
	glVertex3f(1.0, 5.0, 0.0); //V8

	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(1.0, 4.0, 0.0);  //Cuadrado superior de la letra
	glVertex3f(4.0, 4.0, 0.0);
	glVertex3f(4.0, 5.0, 0.0);
	glVertex3f(1.0,5.0,0.0);
	
	glEnd();

	// G

	glBegin(GL_POLYGON);


	glVertex3f(5.0, 1.0, 0.0); //V1
	glVertex3f(8.0, 1.0, 0.0); //V2
	glVertex3f(8.0, 2.0, 0.0); //V3
	glVertex3f(6.0, 2.0, 0.0); //V4
	glVertex3f(6.0, 4.0, 0.0); //V5
	glVertex3f(5.0, 5.0, 0.0); //V8

	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(5.0, 4.0, 0.0);
	glVertex3f(8.0, 4.0, 0.0);
	glVertex3f(8.0, 5.0, 0.0);
	glVertex3f(5.0, 5.0, 0.0);

	glEnd();

	glBegin(GL_TRIANGLE_FAN); //Parte 2

	glVertex3f(8.0, 4.0, 0.0);
	glVertex3f(8.0, 2.0, 0.0);
	glVertex3f(7.0, 2.0, 0.0);
	glVertex3f(7.0, 4.0, 0.0);

	glEnd();

	

	glFlush();
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

	// Ortogonal
	glOrtho(0,20,0,20,-1,2);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}

