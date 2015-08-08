#ifndef GLOBALS_H
#define GLOBALS_H

const float distanceScale = 0.00000003f;

extern float planetSizeScale;

const float PI = 3.14159265359;

typedef struct RGB_{
	float r;
	float g;
	float b;
	RGB_(float r,float g,float b){
		this->r = r;
		this->g = g;
		this->b = b; 
	}

} RGB_;

#endif