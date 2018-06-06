#include <Window.h>

void framebuffer_size_callback( GLFWwindow* window, int width, int height );

Window::Window(std::string title, SE_ERROR* error) {
	this->_title = title;
	this->_running = true;

	this->s_Width = SCREENWIDTH;
	this->s_Height = SCREENHEIGHT;

	glfwWindowHint( GLFW_SAMPLES, 4 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 2 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 1 );
	glfwWindowHint( GLFW_RESIZABLE, RESIZEABLE );

	GLFWmonitor* primaryMonitor = nullptr;

	if ( FULLSCREEN ) {
		primaryMonitor = glfwGetPrimaryMonitor();
	}

	this->_window = glfwCreateWindow( this->s_Width, this->s_Height, title.c_str(), primaryMonitor, nullptr );

	if ( _window == NULL ) {
		//fprintf( stderr, "Failed to open GLFW window.\n" );
		*error = SE_FAILED_GLFWCOULDNTCREATEWINDOW;
		glfwTerminate();
		this->_running = false;
		return;
	}

	glfwMakeContextCurrent( _window );

	glewExperimental = GL_TRUE;

	// Initialize GLEW
	if ( glewInit() != GLEW_OK ) {
		//fprintf( stderr, "Failed to initialize GLEW\n" );
		*error = SE_FAILED_GLEWINITIALIZATION;
		this->_running = false;
		return;
	}

	glViewport( 0, 0, this->s_Width, this->s_Height );

	ResourceManager::getManager();//Calling it ones for instantiating

	glfwSwapInterval( VSYNC );

	//Use when user is able to resize (this restricts the user's window size between 2 values on the x and y (WINDOW,MINX,MINY,MAXX,MAXY))
	//glfwSetWindowSizeLimits( _window, MINSWIDTH, MINSHEIGHT, MINSWIDTH, MINSHEIGHT );

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode( _window, GLFW_STICKY_KEYS, GL_TRUE );

	// Enable depth test
	//glEnable( GL_DEPTH_TEST ); //(Enabled by camera)
	// Accept fragment if it closer to the camera than the former one
	//glDepthFunc( GL_LESS ); //(Enabled by camera)

	// Cull triangles which normal is not towards the camera
	//glEnable( GL_CULL_FACE );

	// Blend textures so alpha channels work.
	glEnable( GL_BLEND );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

	//glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

	glfwSetFramebufferSizeCallback( this->_window, framebuffer_size_callback );

	_sceneManager = new SceneManager( error );
	_currentScene = _sceneManager->getScene( MAINSCENE, error );
}

void framebuffer_size_callback( GLFWwindow* window, int width, int height )
{
	glViewport( 0, 0, width, height );
}

Window::~Window() {
	this->_running = false;
}

float i = 0;
void Window::update() {
	glfwMakeContextCurrent( _window );
	this->getCurrentScene()->updateScene();
	this->_renderer.updateWindow( this );
	//True only for window update purposes
	if ( true ) {
		i += 0.05f;
		RGBAColor c = getCurrentScene()->getBGColor();
		c.r = cos( i );
		c.g = sin( i );
		c.b = tan( i );
		getCurrentScene()->setBGColor( c );
	}
}

bool Window::isRunning() {
	return (this->_running && !glfwWindowShouldClose(this->_window));
}

std::string Window::getTitle() {
	return this->_title;
}

GLFWwindow* Window::getGLFWwindow() {
	return this->_window;
}

SceneManager* Window::getSceneManager() {
	return this->_sceneManager;
}

Scene* Window::getCurrentScene() {
	return this->_currentScene;
}