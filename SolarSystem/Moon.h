#ifndef MOON_H
#define MOON_H

#include <math.h>
#include <glut.h>
#include "globals.h"

class Moon
{
	//расстояние от планеты
	float distanceFromPlanet;

	//время необходимое для одного полного оборота
	float orbitTime;

	//время необходимое для вращения на 360
	float rotationTime;
	
	//радиус самой луны
	float radius;
	
	//положение по отношению к планете
	float position[3];
	
	//текущее вращение
	float rotation;

	RGB_ *color;

	GLuint texture;

public:
	Moon(float distanceFromPlanet, float orbitTime, float rotationTime, float radius, GLuint texture);

	Moon(float distanceFromPlanet, float orbitTime, float rotationTime, float radius, RGB_ *color);

	void calculatePosition(float time);

	void render(void);

	void renderOrbit(void);
};

#endif
