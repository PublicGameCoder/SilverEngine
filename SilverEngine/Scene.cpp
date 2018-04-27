#include <Scene.h>

Scene::Scene( std::string title ) {
	this->_title = title;
}

Scene::~Scene() {
	
}

std::string Scene::getTitle() {
	return this->_title;
}