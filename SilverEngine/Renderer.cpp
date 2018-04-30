#include <Renderer.h>
#include <Window.h>
#include <Scene.h>

Renderer::Renderer() {

}

Renderer::~Renderer() {

}

int r = 0.0f;
void Renderer::updateWindow( Window* window ) {
	this->_currentWindow = window;

	// Clear the screen
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	Input::getManager()->update( this->_currentWindow->getGLFWwindow() );

	//Draw background color
	RGBAColor color = this->_currentWindow->getCurrentScene()->getBGColor();
	glClearColor( color.r, color.g, color.b, 0.0f );

	updateScene( this->_currentWindow->getCurrentScene() );

	// Swap buffers
	glfwSwapBuffers( this->_currentWindow->getGLFWwindow() );
}

//Update the active scene ones per frame.
void Renderer::updateScene( Scene* scene ) {
	if ( scene->_updated )return;
	scene->_updated = true;
}