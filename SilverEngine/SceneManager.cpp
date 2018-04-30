#include <SceneManager.h>

std::map<std::string, Scene*> SceneManager::_scenes = std::map<std::string, Scene*>();

SceneManager::SceneManager( SE_ERROR* error ) {
	this->_selected = MAINSCENE;
	this->createScene( this->_selected, error );
}

SceneManager::~SceneManager() {

}

bool SceneManager::createScene( std::string title, SE_ERROR* error ) {
	if ( _scenes[title] != NULL && title != MAINSCENE) {
		*error = SE_FAILED_NAMEDUPLICATE;
		return false;
	}
	Scene* scene = new Scene( title, error);
	_scenes[title] = scene;
	return true;
}

std::vector<Entity*> SceneManager::removeScene( std::string title, bool deleteEntities, SE_ERROR* error ) {
	std::vector<Entity*> entities = std::vector<Entity*>();
	if ( _scenes[title] != NULL && title != MAINSCENE ) {
		std::map<std::string, Scene*>::iterator it = _scenes.find( title );
		if ( it != _scenes.end() ) {
			entities = it->second->getEntities();
			it->second->_destructEntitiesOnDestroy = deleteEntities;
			delete it->second;
			_scenes.erase( it );
		}
	}
	else if ( title == MAINSCENE ) {
		*error = SE_FAILED_MAINSCENECANTBEREMOVED;
	}
	else if ( _scenes[title] == NULL ) {
		*error = SE_FAILED_NAMEDOESNOTEXIST;
	}

	return entities;
}

Scene* SceneManager::getScene( std::string title, SE_ERROR* error ) {
	std::map<std::string, Scene*>::iterator it = _scenes.find( title );
	if ( it != _scenes.end() ) {
		return it->second;
	}
	*error = SE_FAILED_NAMEDOESNOTEXIST;
	return nullptr;
}

void SceneManager::next( Scene* current ) {
	std::map<std::string, Scene*>::iterator it = _scenes.find( current->getTitle() );
	it++;
	if ( it == _scenes.end() ) {
		it = _scenes.begin();
		it++;
	}
	*current = *(it->second);
}

void SceneManager::prev( Scene* current ) {
	std::map<std::string, Scene*>::iterator it = _scenes.find( current->getTitle() );
	it--;
	if ( it == _scenes.begin() ) {
		it = _scenes.end();
		it--;
	}
	*current = *(it->second);
}

void SceneManager::update() {
	std::map<std::string, Scene*>::iterator it = _scenes.begin();
	while ( it != _scenes.end() ) {
		it->second->_updated = false;
		++it;
	}
}