#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H

#include <vector>
#include "Planet.h"

using namespace std;

class SolarSystem
{
	vector<Planet> planets;

public:	
	SolarSystem();

	void calculatePositions(float time);
	
	void addPlanet(float distanceFromSun, float orbitTime, float rotationTime, float radius, GLuint texture);

	void addPlanet(float distanceFromSun, float orbitTime, float rotationTime, float radius, RGB_ *color);

	void addMoon(int planetIndex, float distanceFromPlanet, float orbitTime, float rotationTime, float radius, GLuint texture);

	void addMoon(int planetIndex, float distanceFromPlanet, float orbitTime, float rotationTime, float radius, RGB_ *color);

	void render();

	void renderOrbits();

	void getPlanetPosition(int index, float* vec);

	float getRadiusOfPlanet(int index);
};

#endif