#include <Scene.h>

Scene::Scene( std::string title ) {
	this->_title = title;
	this->_mainCamera = new Camera( MAINCAMERA );
	this->_backgroundColor = RGBAColor( 0.0f, 0.0f, 0.4f, 0.0f );
}

Scene::~Scene() {
	
}

Camera* Scene::getCamera() {
	return this->_mainCamera;
}

std::string Scene::getTitle() {
	return this->_title;
}