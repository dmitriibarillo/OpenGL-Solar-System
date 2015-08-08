#ifndef PLANET_H
#define PLANET_H

#include <math.h>
#include "globals.h"
#include <vector>
#include "Moon.h"

using namespace std;
#include <glut.h>


class Planet
{
	// ���������� �� ������
	float distanceFromSun;
	
	// ����� ����������� ��� ������ ������� �������  ������ ������
	float orbitTime;

	// ����� ������� ������ ����������� ��� 
	float rotationTime;

	// ������ �������
	float radius;
	
	// ��������� �� ��������� � ������
	float position[3];

	// ������� �������� 
	float rotation;

	//���� �������
	RGB_ *color;

	GLuint texture;

	vector<Moon> moons;

public:
	Planet(float distanceFromSun, float orbitTime, float rotationTime, float radius, GLuint texture);

	Planet(float distanceFromSun, float orbitTime, float rotationTime, float radius, RGB_ *color);

	void calculatePosition(float time);

	void render(void);

	void renderOrbit(void);

	void getPosition(float* vec);

	float getRadius(void);

	void addMoon(float distanceFromPlanet, float orbitTime, float rotationTime, float radius, GLuint texture);
	
	void addMoon(float distanceFromPlanet, float orbitTime, float rotationTime, float radius, RGB_ *color);
};

#endif