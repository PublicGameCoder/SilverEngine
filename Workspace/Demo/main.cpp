#include <Engine.h>
#include <Demo/Smiley.h>

int main( void )
{
	SE_ERROR error = 0;
	Engine engine(&error);
	Engine::printErr( error );

	engine.createWindow( "Map", &error );

	Window* win = engine.getMainWindow();
	win->getCurrentScene()->setBGColor( RGBAColor( 1.0f, 0.0f, 0.0f, 0.0f ) );

	Window* window1 = engine.getWindow( "Map", &error );

	window1->getCurrentScene()->setBGColor( RGBAColor( 0.0f, 1.0f, 0.0f, 0.0f ) );
	
	Scene* main_Scene = win->getCurrentScene();

	Entity* en = new Entity( "Wall", &error );

	Smiley* smiley1 = new Smiley( "Smiley", &error );
	en->addChild( smiley1, &error );

	main_Scene->addEntity( en );

	return engine.start();
}