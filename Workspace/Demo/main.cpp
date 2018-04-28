#include <Engine.h>

int main( void )
{
	SE_ERROR error;
	Engine engine(&error);
	if ( error ) {
		Engine::printErr( error );
	}

	//When you want to create a new window.
	if ( !engine.createWindow( "Map", &error ) ) {
		Engine::printErr( error );
	}

	Window* win = engine.getMainWindow();
	//Window* win = engine.getWindow( TITLE, error);
	win->getCurrentScene()->setBGColor( RGBAColor( 1.0f, 0.0f, 0.0f, 0.0f ) );

	Window* window1 = engine.getWindow( "Map", &error );
	if ( error ) { Engine::printErr( error ); }
	window1->getCurrentScene()->setBGColor( RGBAColor( 0.0f, 1.0f, 0.0f, 0.0f ) );
	
	Scene* main_Scene = win->getCurrentScene();

	return engine.start();
}