#include "Moon.h"
#include <cmath>

Moon::Moon(float distanceFromPlanet, float orbitTime, float rotationTime, float radius, GLuint texture){
	this->distanceFromPlanet = distanceFromPlanet;
	this->orbitTime = orbitTime;
	this->rotationTime = rotationTime;
	this->radius = radius;
	this->texture = texture;
}

Moon::Moon(float distanceFromPlanet, float orbitTime, float rotationTime, float radius, RGB_ *color){
	this->distanceFromPlanet = distanceFromPlanet;
	this->orbitTime = orbitTime;
	this->rotationTime = rotationTime;
	this->radius = radius;
	this->color = color;
}

//¬ычисление позиции по отношению к планете
void Moon::calculatePosition(float time){
	float angle = time *  PI / orbitTime;

	position[0] = sin(angle) * distanceFromPlanet;
	position[1] = cos(angle) * distanceFromPlanet;
	position[2] = 0;

	rotation = time * 360 / rotationTime;
}

void Moon::render(void){
	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, texture);
	glTranslatef(position[0] * distanceScale, position[1] * distanceScale, position[2] * distanceScale);
	glRotatef(-rotation, 0.0f, 0.0f, 1.0f);
	
	GLUquadricObj* quadric = gluNewQuadric();
	gluQuadricTexture(quadric, true);
	gluQuadricNormals(quadric, GLU_SMOOTH);

	gluSphere(quadric, radius * planetSizeScale, 30, 30);

	glPopMatrix();
}

void Moon::renderOrbit(void){
	glBegin(GL_LINE_STRIP);
		for (float angle = 0.0f; angle < 6.283185307f; angle += 0.1f) {
			glVertex3f(sin(angle) * distanceFromPlanet * distanceScale, cos(angle) * distanceFromPlanet * distanceScale, 0.0f);
		}
		glVertex3f(0.0f, distanceFromPlanet * distanceScale, 0.0f);
	glEnd();
}