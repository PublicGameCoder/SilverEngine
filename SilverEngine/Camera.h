#ifndef CAMERA_H
#define CAMERA_H

#include <Entity.h>
#include <Window.h>

class Camera : public Entity
{
public:
	Camera( std::string title );
	virtual ~Camera();
	void updateCamera( Window* window );

private:
};

#endif
