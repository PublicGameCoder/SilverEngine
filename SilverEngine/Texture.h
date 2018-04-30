#ifndef TEXTURE_H
#define TEXTURE_H

#include <OpenGLInc.h>

#include <SEConfig.h>

class ResourceManager;

class Texture
{
public:
	Texture();
	virtual ~Texture();

	GLuint getID() {
		return _textureID;
	}

	int getWidth() {
		return _width;
	}

	int getHeight() {
		return _height;
	}

	int getChannels() {
		return _nrChannels;
	}

	void load2DTexture( const std::string &filePath );
	void loadSkybox( std::vector<std::string> &faces );

private:
	GLuint _textureID;
	int _nrChannels;
	int _width;
	int _height;
};

#endif // !TEXTURE_H
