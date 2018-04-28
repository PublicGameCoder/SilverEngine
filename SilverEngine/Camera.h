#ifndef CAMERA_H
#define CAMERA_H

#include <OpenGLInc.h>
#include <Entity.h>

class Camera : public Entity
{
public:
	Camera( std::string title );
	virtual ~Camera();
	void updateCamera();

private:
	void orthographic();
	void perspective();

	glm::mat4 _viewMatrix; ///< @brief The viewMatrix of the Camera
	glm::mat4 _projectionMatrix; ///< @brief The (orthographic) projectionMatrix of the Camera

	Point3 _offset; ///< @brief The internal offset of the Camera. When Camera is in the middle of the screen, its position is (0,0,0).

	glm::vec3 _up; ///< @brief The up vector of the Camera.
	glm::vec3 _right; ///< @brief The right vector of the Camera.
	glm::vec3 _direction; ///< @brief The vector where the Camera is looking.

};

#endif
