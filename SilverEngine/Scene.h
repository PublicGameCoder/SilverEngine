#ifndef SCENE_H
#define SCENE_H

#include <SEConfig.h>
#include <Color.h>
#include <Camera.h>

class Scene
{
public:
	Scene( std::string title );
	virtual ~Scene();
	std::string getTitle();
	Camera* getCamera();

	RGBAColor getBGColor() {
		return this->_backgroundColor;
	}
	void setBGColor( RGBAColor color ) {
		this->_backgroundColor = color;
	}
private:
	std::string _title;
	Camera* _mainCamera;

	RGBAColor _backgroundColor;
};

#endif // !SCENE_H
