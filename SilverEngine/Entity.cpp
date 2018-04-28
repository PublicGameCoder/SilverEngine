#include <Entity.h>

Entity::Entity(std::string title) {

}

Entity::~Entity() {

}

std::string Entity::getTitle() {
	return this->_title;
}

Vector3 Entity::getPosition() {
	return this->_position;
}
Vector3 Entity::getRotation() {
	return this->_rotation;
}
Vector3 Entity::getScale() {
	return this->_scale;
}