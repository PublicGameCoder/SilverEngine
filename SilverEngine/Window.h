#ifndef WINDOW_H
#define WINDOW_H

#include <OpenGLInc.h>
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

	Scene* getCurrentScene();
	SceneManager* getSceneManager();

private:
	bool _running;
	std::string _title;

	Renderer _renderer;
	SceneManager* _sceneManager;

	GLFWwindow* _window;

	GLfloat s_Width, s_Height;

	Scene* _currentScene;
};

#endif // !ENGINE_H
