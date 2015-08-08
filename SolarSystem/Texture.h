#ifndef TEXTURE_H
#define TEXTURE_H

#include <glaux.h>
#include <glut.h>


class Texture
{
	GLuint	texture;
public:
	Texture(wchar_t* path);
	
	GLuint GetTexture();

};
#endif 



