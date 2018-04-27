#ifndef RENDERER_H
#define RENDERER_H

#include <Input.h>

class Window;
class Scene;

class Renderer
{
public:
	Renderer();
	virtual ~Renderer();

	void updateWindow(Window* window);
private:
	Window* _currentWindow;

	void updateScene( Scene* scene );
};

#endif // !RENDERER_H
