#ifndef ENTITY_H
#define ENTITY_H

#include <SEConfig.h>
#include <VectorX.h>
#include <Sprite.h>

class Entity
{
public:
	Entity(std::string title);
	virtual ~Entity();

	std::string getTitle();

	Vector3 getPosition();
	Vector3 getRotation();
	Vector3 getScale();
private:
	std::string _title;
	Sprite* _sprite;
protected:
	Vector3 _position;
	Vector3 _rotation;
	Vector3 _scale;
};

#endif // !ENTITY_H
