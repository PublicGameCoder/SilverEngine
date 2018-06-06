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

	std::string getType() {
		return this->_type;
	}

	std::string getPath() {
		return this->_path;
	}

	void load2DTexture( const std::string &filePath );

private:
	friend class Model;

	GLuint _textureID;
	int _nrChannels;
	int _width;
	int _height;
	std::string _type;
	std::string _path;
};

#endif // !TEXTURE_H
