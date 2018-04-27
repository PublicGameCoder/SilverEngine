#ifndef WINDOW_H
#define WINDOW_H

#include <OpenGLInc.h>
#include <Color.h>
#include <Renderer.h>
#include <ResourceManager.h>
#include <SceneManager.h>

class Window
{
public:
	Window(std::string title, SE_ERROR* error );
	virtual ~Window();

	void update();
	bool isRunning();
	std::string getTitle();
	GLFWwindow* getGLFWwindow();
	RGBAColor getBGColor() {
		return _backgroundColor;
	}
	void setBGColor(RGBAColor color) {
		_backgroundColor = color;
	}

	Scene* getCurrentScene();
	SceneManager* getSceneManager();

private:
	bool _running;
	std::string _title;
	RGBAColor _backgroundColor;

	Renderer _renderer;
	SceneManager* _sceneManager;

	GLFWwindow* _window;

	GLfloat s_Width, s_Height;

	Scene* _currentScene;
};

#endif // !ENGINE_H
