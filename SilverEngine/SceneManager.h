#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <SEConfig.h>
#include <Scene.h>

class SceneManager
{
public:
	SceneManager( SE_ERROR* error );
	virtual ~SceneManager();

	void next( Scene* current );

	void prev( Scene* current );

	Scene* getCurrent() {
		return _scenes[_selected];
	}

	static bool createScene( std::string title, SE_ERROR* error );
	static Scene* getScene( std::string title, SE_ERROR* error );

	void update();

private:
	std::string _selected;
	static std::map<std::string, Scene*> _scenes;
};

#endif // !SCENEMANAGER_H
