#include "solarsystem.h"
#include "globals.h"
#include "Texture.h"
#include "Camera.h"
#include <glut.h>

CCamera Camera;


int screenWidth, screenHeight;

SolarSystem solarSystem;

double time;
double timeSpeed;

void timer(int) {
	glutPostRedisplay(); // перерисовка окна
	glutTimerFunc(10, timer, 0); // устанавливаем таймер
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	
	glEnable(GL_LIGHTING);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_SMOOTH);

	
	glEnable(GL_LIGHTING);
	glDisable(GL_LIGHTING);

	/*
	Texture* sun = new Texture(L"../Bitmaps/sunmap.bmp");
	Texture* mercury = new Texture(L"../Bitmaps/mercurymap.bmp");
	Texture* venus = new Texture(L"../Bitmaps/venusmap.bmp");
	Texture* earth = new Texture(L"../Bitmaps/earthmap.bmp");
	Texture* mars = new Texture(L"../Bitmaps/marsmap.bmp");
	Texture* jupiter = new Texture(L"../Bitmaps/jupitermap.bmp");
	Texture* saturn = new Texture(L"../Bitmaps/saturnmap.bmp");
	Texture* uranus = new Texture(L"../Bitmaps/uranusmap.bmp");
	Texture* neptune = new Texture(L"../Bitmaps/neptunemap.bmp");
	Texture* pluto = new Texture(L"../Bitmaps/plutomap.bmp");
	*/

	Texture* sun = new Texture(L"../bmp/sun.bmp");
	Texture* mercury = new Texture(L"../bmp/mercury.bmp");
	Texture* venus = new Texture(L"../bmp/venus.bmp");
	Texture* earth = new Texture(L"../bmp/earth.bmp");
	Texture* mars = new Texture(L"../bmp/mars.bmp");
	Texture* jupiter = new Texture(L"../bmp/jupiter.bmp");
	Texture* saturn = new Texture(L"../bmp/saturn.bmp");
	Texture* uranus = new Texture(L"../bmp/uranus.bmp");
	Texture* neptune = new Texture(L"../bmp/neptune.bmp");
	Texture* moon = new Texture(L"../bmp/moon.bmp");

	/*
	solarSystem.addPlanet(0, 1, 500, 695500, sun->GetTexture()); // sun
	solarSystem.addPlanet(57910000, 88, 58.6*365, 2440, mercury->GetTexture()); // mercury
	solarSystem.addPlanet(108200000, 224.65, 243*365, 6052, venus->GetTexture()); // venus
	solarSystem.addPlanet(149600000, 365, 1*365, 6371, earth->GetTexture()); // earth
	solarSystem.addPlanet(227939100, 686, 1.03f*365, 3389, mars->GetTexture()); // mars
	solarSystem.addPlanet(778500000, 4332, 0.4139*365, 69911, jupiter->GetTexture()); // jupiter
	solarSystem.addPlanet(1433000000, 10759, 0.44375*365, 58232, saturn->GetTexture()); // saturn
	solarSystem.addPlanet(2877000000, 30685, 0.718056*365, 25362, uranus->GetTexture()); // uranus
	solarSystem.addPlanet(4503000000, 60188, 0.6713*365, 24622, neptune->GetTexture()); // neptune
	
	solarSystem.addMoon(3, 70000000, 27.3, 27.3, 1738, moon->GetTexture()); // 
	*/

	solarSystem.addPlanet(0, 1, 500, 695500, sun->GetTexture()); // sun
	solarSystem.addPlanet(57910000, 88, 58.65*100, 2440, mercury->GetTexture()); // mercury
	solarSystem.addPlanet(108200000, 224.7, 243.02*100, 6052, venus->GetTexture()); // venus
	solarSystem.addPlanet(149600000, 365, 1*100, 6371, earth->GetTexture()); // earth
	solarSystem.addPlanet(228000000, 687, 1.015f*100, 3390, mars->GetTexture()); // mars
	solarSystem.addPlanet(778500000, 4332, 0.42f*100, 69911, jupiter->GetTexture()); // jupiter
	solarSystem.addPlanet(1433000000, 10759, 0.44*100, 58232, saturn->GetTexture()); // saturn
	solarSystem.addPlanet(2800000000, 30685, 0.71833*100, 25362, uranus->GetTexture()); // uranus
	solarSystem.addPlanet(455000000, 60188, 0.6653*100, 24764, neptune->GetTexture()); // neptune
	
	solarSystem.addMoon(3, 384400*70, 27.3, 27.3, 1738, moon->GetTexture()); // test moon for the earth
	

	time = 2.552f;
	timeSpeed = 0.1f;

	timer(0);
}


void display(void) {
	time += timeSpeed;
	solarSystem.calculatePositions(time);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70.0f, (float)screenWidth / (float)screenHeight, 0.001f, 500.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	

	Camera.Render();
	
	GLfloat lightPosition[] = { 0.0, 0.0, 0.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

	solarSystem.render();
	glDisable(GL_LIGHTING);

	solarSystem.renderOrbits();
	
	glDisable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble) screenWidth, (GLdouble) screenHeight, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glFlush();
	glutSwapBuffers();
}

void reshape(int w, int h) {
	screenWidth = w;
	screenHeight = h;
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
}

void Key(unsigned char key, int x, int y) {
	switch (key)
	{
	case '+':
		timeSpeed += 0.1;
		break;
	case '-':
		timeSpeed -= 0.1;
		break;
	}
}


void KeyDown(unsigned char key, int x, int y) {
	switch (key) {
		case 27:		//ESC
			PostQuitMessage(0);
			break;
		case 'a':		
			Camera.RotateY(5.0);
			display();
			break;
		case 'd':		
			Camera.RotateY(-5.0);
			display();
			break;
		case 'w':		
			Camera.MoveForward( -0.1 ) ;
			display();
			break;
		case 's':		
			Camera.MoveForward( 0.1 ) ;
			display();
			break;
		case 'y':		
			Camera.RotateX(5.0);
			display();
			break;
		case 'h':		
			Camera.RotateX(-5.0);
			display();
			break;
		case 'c':		
			Camera.StrafeRight(-0.1);
			display();
			break;
		case 'v':		
			Camera.StrafeRight(0.1);
			display();
			break;
		case 'k':
			Camera.MoveUpward(-0.3);
			display();
			break;
		case 'i':
			Camera.MoveUpward(0.3);
			display();
			break;
		case 'l':
			Camera.RotateZ(-5.0);
			display();
			break;
		case 'j':
			Camera.RotateZ(5.0);
			display();
			break;
	}
}



int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1200, 700);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(KeyDown);
	glutKeyboardUpFunc(Key);
	glutMainLoop();
	return 0;
}
