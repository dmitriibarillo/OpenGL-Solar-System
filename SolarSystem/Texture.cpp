#include "Texture.h"
#include <tchar.h>

Texture::Texture(wchar_t* path)
{
	AUX_RGBImageRec *texture1;
	texture1 = auxDIBImageLoad(path);

	// Создание текстуры
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST); // 
	//glTexImage2D(GL_TEXTURE_2D, 0, 3, texture1->sizeX, texture1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, texture1->data);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, texture1->sizeX, texture1->sizeY, GL_RGB, GL_UNSIGNED_BYTE, texture1->data); // ( НОВОЕ )
 
}

GLuint Texture::GetTexture(){
	return texture;
}



