#include <Input.h>
#include <Window.h>

Input* Input::instance = NULL;

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	Input::getManager()->scrollCallback(window, xoffset, yoffset);
}

void window_iconify_callback( GLFWwindow* window, int iconified );

Input::Input() {
	currentWindow = NULL;

	prevWindowWidth = 0;
	prevWindowHeight = 0;

	windowWidth = 0;
	windowHeight = 0;

	for (unsigned int i = 0; i<GLFW_KEY_LAST; i++) {
		PressedKeys[i] = false;
		KeysUp[i] = false;
		KeysDown[i] = false;
	}
	for (unsigned int i = 0; i<GLFW_MOUSE_BUTTON_LAST; i++) {
		mouse[i] = false;
		mouseUp[i] = false;
		mouseDown[i] = false;
	}
}

Input::~Input() {

}

Input* Input::getManager(void) {
	if (!Input::instance) {
		Input::instance = new Input();
	}
	return Input::instance;
}

void Input::preprocessWindow(GLFWwindow* window) {
	if (std::find(monitoredWindows.begin(), monitoredWindows.end(), window) == monitoredWindows.end()) {
		//When window isn't monitored.

		glfwSetScrollCallback(window, scroll_callback);

		monitoredWindows.push_back(window);
	}
}

void Input::update(Window* w) {
	currentWindow = w;

	preprocessWindow(w->getGLFWwindow());

	glfwPollEvents();

	glfwGetWindowSize(this->currentWindow->getGLFWwindow(), &windowWidth, &windowHeight);

	/*
	if (prevWindowWidth != windowWidth || prevWindowHeight != windowHeight) {
		EventHandler::getManager()->call(WindowResizeEvent(currentWindow->getGLFWwindow(), windowWidth, windowHeight));
		prevWindowWidth = windowWidth;
		prevWindowHeight = windowHeight;
	}*/

	glfwSetWindowIconifyCallback( this->currentWindow->getGLFWwindow(), window_iconify_callback );

	glfwGetCursorPos(this->currentWindow->getGLFWwindow(), &mouseX, &mouseY);

	mouseX = ((float) SCREENWIDTH / windowWidth) * mouseX;
	mouseY = ((float) SCREENHEIGHT / windowHeight) * mouseY;

	for (unsigned int i = 32; i<97; i++) {
		processKey(i);
	}
	for (unsigned int i = 255; i<GLFW_KEY_LAST; i++) {
		processKey(i);
	}

	for (unsigned int i = 0; i<GLFW_MOUSE_BUTTON_LAST; i++) {
		processButton(i);
	}
}

void Input::processKey(unsigned int key) {
	if (glfwGetKey(this->currentWindow->getGLFWwindow(), key) == GLFW_PRESS) {
		if (!PressedKeys[key]) {
			PressedKeys[key] = true;
			KeysDown[key] = true;
			KeysUp[key] = false;
		}
		else {
			KeysDown[key] = false;
		}
	}
	if (glfwGetKey(this->currentWindow->getGLFWwindow(), key) == GLFW_RELEASE) {
		if (PressedKeys[key]) {
			PressedKeys[key] = false;
			KeysUp[key] = true;
			KeysDown[key] = false;
		}
		else {
			KeysUp[key] = false;
		}
	}
}

void Input::processButton(unsigned int button) {
	if (glfwGetMouseButton(this->currentWindow->getGLFWwindow(), button) == GLFW_PRESS) {
		if (mouse[button] == false) {
			mouse[button] = true;
			mouseDown[button] = true;
			mouseUp[button] = false;
		}
		else {
			mouseDown[button] = false;
		}
	}
	if (glfwGetMouseButton(this->currentWindow->getGLFWwindow(), button) == GLFW_RELEASE) {
		if (mouse[button] == true) {
			mouse[button] = false;
			mouseUp[button] = true;
			mouseDown[button] = false;
		}
		else {
			mouseUp[button] = false;
		}
	}
}

void Input::scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
	if (horizontalScrolls.find(window) == horizontalScrolls.end()) {
		horizontalScrolls.insert(std::pair<GLFWwindow*, int>(window, (xoffset > 0) ? 1 : -1));
	}
	else {
		horizontalScrolls.find(window)->second = (xoffset > 0) ? 1 : -1;
	}

	if (verticalScrolls.find(window) == verticalScrolls.end()) {
		verticalScrolls.insert(std::pair<GLFWwindow*, int>(window, (yoffset > 0) ? 1 : -1));
	}
	else {
		verticalScrolls.find(window)->second = (yoffset > 0) ? 1 : -1;
	}

	if (continuedHorizontalScrolls.find(window) == continuedHorizontalScrolls.end()) {
		continuedHorizontalScrolls.insert(std::pair<GLFWwindow*, int>(window, (xoffset > 0) ? 1 : -1));
	}
	else {
		continuedHorizontalScrolls.find(window)->second += (xoffset > 0) ? 1 : -1;
	}

	if (continuedVerticalScrolls.find(window) == continuedVerticalScrolls.end()) {
		continuedVerticalScrolls.insert(std::pair<GLFWwindow*, int>(window, (yoffset > 0) ? 1 : -1));
	}
	else {
		continuedVerticalScrolls.find(window)->second += (yoffset > 0) ? 1 : -1;
	}
}

void Input::setMouse( double xPos, double yPos ) {
	glfwSetCursorPos( currentWindow->getGLFWwindow(), xPos, yPos );
};

void window_iconify_callback( GLFWwindow* window, int iconified )
{
	if ( iconified )
	{
		// The window was iconified
		Time::pause();
	}
	else
	{
		// The window was restored
		Time::unpause();
	}
}