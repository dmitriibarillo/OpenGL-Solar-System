#ifndef MOON_H
#define MOON_H

#include <math.h>
#include <glut.h>
#include "globals.h"

class Moon
{
	//���������� �� �������
	float distanceFromPlanet;

	//����� ����������� ��� ������ ������� �������
	float orbitTime;

	//����� ����������� ��� �������� �� 360
	float rotationTime;
	
	//������ ����� ����
	float radius;
	
	//��������� �� ��������� � �������
	float position[3];
	
	//������� ��������
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
