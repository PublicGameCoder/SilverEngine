#ifndef SCENE_H
#define SCENE_H

#include <SEConfig.h>
#include <Color.h>
#include <Camera.h>

class Scene
{
public:
	void updateScene();

	std::string getTitle();
	Camera* getCamera();

	RGBAColor getBGColor() {
		return this->_backgroundColor;
	}
	void setBGColor( RGBAColor color ) {
		this->_backgroundColor = color;
	}

	void addEntity( Entity* entity );
	void removeEntity( Entity* entity);

private:
	friend class SceneManager;
	friend class Renderer;
	Scene( std::string title, SE_ERROR* error );
	virtual ~Scene();
	//Destroy every entity in the scene when scene gets deconstructed. (DEFAULT = TRUE)
	bool _destructEntitiesOnDestroy;
	std::vector<Entity*> getEntities();

	std::string _title;
	Camera* _mainCamera;

	RGBAColor _backgroundColor;

	std::vector<Entity*> _entities;

	bool _updated;
};

#endif // !SCENE_H
