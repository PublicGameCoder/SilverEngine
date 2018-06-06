#ifndef ENGINE_H
#define ENGINE_H

#include <SEConfig.h>
#include <Window.h>

class Engine
{
public:
	Engine( SE_ERROR* error );
	virtual ~Engine();
	int start();


	Window* getMainWindow() {
		return _mainWindow;
	}
	bool createWindow( std::string title, SE_ERROR* error);
	Window* getWindow( std::string title, SE_ERROR* error);

	static void printErr( SE_ERROR error );
	static Engine* getInstance();
private:
	bool runnable;
	Window* _mainWindow;
	std::map<std::string, Window*> _windows;

	static Engine* instance;
};

#endif // !ENGINE_H