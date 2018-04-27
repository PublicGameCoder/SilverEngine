#ifndef SCENE_H
#define SCENE_H

#include <SEConfig.h>

class Scene
{
public:
	Scene( std::string title );
	virtual ~Scene();
	std::string getTitle();
private:
	std::string _title;
};

#endif // !SCENE_H
