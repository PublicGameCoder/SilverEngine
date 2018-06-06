#include <Sprite.h>

Sprite::Sprite( std::string filePath ) {
	this->_texture = ResourceManager::getManager()->getTexture( filePath );
	this->_mesh = nullptr;//new Mesh();
	this->_shader = ResourceManager::getManager()->getShader(DEFAULTMESHSHADERVERTEX,DEFAULTMESHSHADERFRAGMENT);
}

Sprite::~Sprite() {
	delete this->_mesh;
}