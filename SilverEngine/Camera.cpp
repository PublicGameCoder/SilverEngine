#include <Camera.h>

Camera::Camera(std::string title, SE_ERROR* error ) : Entity( title, error) {
	this->_position = Point3( 0, 0, 650 );
	this->_rotation = Point3( 0, PI, 0 );

	this->_direction = glm::vec3( 0, 0, -5 );
	this->_up = glm::vec3( 0, 1, 0 );
	this->_right = glm::vec3( 1, 0, 0 );
}

Camera::~Camera() {

}

void Camera::updateCamera() {
	if ( USE3D ) {
		perspective();
	}
	else {
		orthographic();
	}

	// Direction vector: Spherical coordinates to Cartesian coordinates conversion
	this->_direction = glm::vec3(
		cos( _rotation.x ) * sin( this->_rotation.y ),
		sin( _rotation.x ),
		cos( this->_rotation.x ) * cos( this->_rotation.y )
	);
	//_direction = glm::vec3(0, 0, -5);

	// Right vector
	this->_right = glm::vec3(
		sin( _rotation.y - HALF_PI ),
		0,
		cos( _rotation.y - HALF_PI )
	);
	this->_right = glm::rotateZ( _right, _rotation.z*( float ) RAD_TO_DEG ); // rotateZ() in Degrees
																		//_right = glm::vec3(1, 0, 0);

																	  // Up vector
	this->_up = glm::cross( _right, _direction );
	//_up = glm::vec3(0, 1, 0);

	glm::vec3 pos = glm::vec3( _position.x, _position.y, _position.z );
	glm::vec3 offset = glm::vec3( _offset.x, _offset.y, _offset.z );

	// View matrix
	this->_viewMatrix = glm::lookAt(
		pos - offset, // Camera is at (xpos,ypos,1), in World Space
		pos - offset + _direction, // and looks towards Z
		_up  // Head is up
	);
}

void Camera::orthographic()
{
	// to compensate for the camera being not in the correct position
	this->_offset = Point3( SCREENWIDTH / 2, SCREENHEIGHT / 2, 0 );

	// Initial position : on +Z
	// Unintuitively, this is the centre of the screen, so add _offset
	this->_position = Point3( 0, 0, 650 ) + this->_offset;

	this->_projectionMatrix = glm::ortho( 0.0f, ( float ) SCREENWIDTH, ( float ) SCREENHEIGHT, 0.0f, 0.1f, 1000.0f );

	// Disable depth test (we don't need it in 2D)
	glDisable( GL_DEPTH_TEST );
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc( GL_LESS );
}

void Camera::perspective()
{
	// offset is 0,0,0 because in 3D we want 0,0,0 in the middle of the screen
	this->_offset = Point3( 0, 0, 0 );
	this->_position = Point3( 0, 0, 650 ) + this->_offset;

	// FoV, aspectratio, nearclip, farclip
	this->_projectionMatrix = glm::perspective( 45.0f, ( float ) SCREENWIDTH / ( float ) SCREENHEIGHT, 0.1f, 10000.0f );

	// Enable depth test
	glEnable( GL_DEPTH_TEST );
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc( GL_LESS );
}