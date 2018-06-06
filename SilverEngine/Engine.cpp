#include <Engine.h>

Engine* Engine::instance = nullptr;
Engine::Engine( SE_ERROR* error ) {
	instance = this;
	this->runnable = true;

	// Initialise GLFW
	if ( !glfwInit() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		this->runnable = false;
		*error = SE_FAILED_GLFWINITIALIZATION;
		return;
	}

	this->_mainWindow = new Window( TITLE, error );
	printf("Successfully initialized the engine.\n");
}

Engine::~Engine() {

	std::map<std::string, Window*>::iterator it = _windows.begin();
	while ( it != _windows.end() ) {
		delete it->second;
		it = _windows.erase( it );
	}

	delete _mainWindow;
}

int Engine::start() {

	while ( this->runnable && this->_mainWindow->isRunning() ) {
		Time::calcDelta();

		SceneManager::update();
		this->_mainWindow->update();
		std::map<std::string, Window*>::iterator windowIterator = _windows.begin();
		while (windowIterator != _windows.end() ){
			windowIterator->second->update();
			if ( !windowIterator->second->isRunning() ) {
				glfwDestroyWindow( windowIterator->second->getGLFWwindow() );
				windowIterator = _windows.erase( windowIterator );
			} else {
				++windowIterator;
			}
		}
	}
	printf( "Successfully deserialized the engine.\n" );
	return 0;
}

bool Engine::createWindow( std::string title, SE_ERROR* error) {
	if ( _windows[title] != NULL ) {
		*error = SE_FAILED_NAMEDUPLICATE;
		return false;
	}
	Window* window = new Window( title, error );
	_windows[title] = window;
	return true;
}

Window* Engine::getWindow( std::string title, SE_ERROR* error ) {
	if ( this->_mainWindow->getTitle() == title.c_str() ) {
		return (this->_mainWindow);
	}
	std::map<std::string, Window*>::iterator it = _windows.find( title );
	if ( it != _windows.end() ) {
		return it->second;
	}
	*error = SE_FAILED_NAMEDOESNOTEXIST;
	return nullptr;
}

void Engine::printErr( SE_ERROR error ) {
	switch (error) {
	case SE_SUCCESS:
		break;
	case SE_FAILED_UNDEFINED:
		printf( ":SE_ERROR:Undefined_error\n" );//UNDEFINED.
		break;
	case SE_FAILED_NAMEDUPLICATE:
		printf( ":SE_ERROR:Name_already_exists\n" );//NAMEDUPLICATE.
		break;
	case SE_FAILED_NAMEDOESNOTEXIST:
		printf( ":SE_ERROR:Name_does_not_exist\n" );//UNDEFINED.
		break;
	case SE_FAILED_GLFWINITIALIZATION:
		printf( ":SE_ERROR:GLFW_INIT_FAILED\n" );//GLFW Init failed.
		break;
	case SE_FAILED_GLFWCOULDNTCREATEWINDOW:
		printf( ":SE_ERROR:GLFW_WINDOW_CREATION_FAILED\n" );//GLFW couldn't create a window.
		break;
	case SE_FAILED_GLEWINITIALIZATION:
		printf( ":SE_ERROR:GLEW_INIT_FAILED\n" );//GLEW Init failed.
		break;
	case SE_FAILED_MAINSCENECANTBEREMOVED:
		printf( ":SE_ERROR:Main_Scene_can't_be_removed\n" );//GLEW Init failed.
		break;
	case SE_FAILED_NAMEALREADYEXISTSBUTGOTCHANGED:
		printf( ":SE_ERROR:Name_already_exists_but_got_changed\n" );//GLEW Init failed.
		break;
	default:
		printf( ":SE_ERROR:Undefined_error\n" );//UNDEFINED
		break;
	}
}

Engine* Engine::getInstance() {
	return instance;
}