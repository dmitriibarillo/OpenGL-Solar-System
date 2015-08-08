#include "SolarSystem.h"


SolarSystem::SolarSystem(void) {

}

void SolarSystem::calculatePositions(float time){
	for (int i = 0; i < planets.size(); i++) {
		planets[i].calculatePosition(time);
	}
}
	
void SolarSystem::addPlanet(float distanceFromSun, float orbitTime, float rotationTime, float radius, GLuint texture){
	planets.push_back(Planet(distanceFromSun, orbitTime, rotationTime, radius, texture));
}

void SolarSystem::addPlanet(float distanceFromSun, float orbitTime, float rotationTime, float radius, RGB_* color){
	planets.push_back(Planet(distanceFromSun, orbitTime, rotationTime, radius, color));
}


void SolarSystem::addMoon(int planetIndex, float distanceFromPlanet, float orbitTime, float rotationTime, float radius, GLuint texture){
	planets[planetIndex].addMoon(distanceFromPlanet, orbitTime, rotationTime, radius, texture);
}

void SolarSystem::addMoon(int planetIndex, float distanceFromPlanet, float orbitTime, float rotationTime, float radius, RGB_ *color){
	planets[planetIndex].addMoon(distanceFromPlanet, orbitTime, rotationTime, radius, color);
}

void SolarSystem::render(){
	for (int i = 0; i < planets.size(); i++) {
		planets[i].render();
	}
}

void SolarSystem::renderOrbits(){	
	for (int i = 0; i < planets.size(); i++) {
		planets[i].renderOrbit();
	}
}

void SolarSystem::getPlanetPosition(int index, float* vec){
	planets[index].getPosition(vec);
}

float SolarSystem::getRadiusOfPlanet(int index){
	return planets[index].getRadius();
}
