#ifndef SPRITE_H
#define SPRITE_H

#include <ResourceManager.h>
#include <Mesh.h>

class Sprite
{
public:
	Sprite(std::string filePath);
	virtual ~Sprite();

	Texture* getTexture() {
		return this->_texture;
	}
	Mesh* getMesh() {
		return this->_mesh;
	}
	Shader* getSahder() {
		return this->_shader;
	}
	GLfloat getWidth() {
		return (this->_texture != nullptr)? this->_texture->getWidth() : 0;
	}
	GLfloat getHeight() {
		return (this->_texture != nullptr)? this->_texture->getHeight() : 0;
	}
private:
	Texture* _texture;
	Mesh* _mesh;
	Shader* _shader;
};

#endif // !SPRITE_H
