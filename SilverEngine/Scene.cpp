#include <Scene.h>

Scene::Scene( std::string title, SE_ERROR* error ) {
	this->_title = title;
	this->_mainCamera = new Camera( MAINCAMERA, error);
	this->_backgroundColor = RGBAColor( 0.0f, 0.0f, 0.4f, 0.0f );
	this->_destructEntitiesOnDestroy = true;
	this->_updated = false;
}

Scene::~Scene() {
	std::vector<Entity*>::iterator it = _entities.begin();
	while ( it != _entities.end() ) {
		_entities.erase( it );
		if ( this->_destructEntitiesOnDestroy ) {
			delete *it;
		}
		else {
			(*it)->setScene( nullptr );
		}
	}
}

void Scene::updateScene() {
	this->getCamera()->updateCamera();
	for (Entity* child : this->getEntities()) {
		child->update();
	}
}

void Scene::addEntity( Entity* entity) {
	if ( entity->getScene() != nullptr ) {
		entity->getScene()->removeEntity( entity );
	}
	this->_entities.push_back( entity );
	entity->setScene( this );
}

void Scene::removeEntity( Entity* entity) {
	std::vector<Entity*>::iterator it = std::find( _entities.begin(), _entities.end(), entity );
	if ( it != _entities.end() ) {
		this->_entities.erase( it );
		entity->setScene( nullptr );
	}
}

Camera* Scene::getCamera() {
	return this->_mainCamera;
}

std::string Scene::getTitle() {
	return this->_title;
}

std::vector<Entity*> Scene::getEntities() {
	return this->_entities;
}