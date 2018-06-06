#ifndef ENTITY_H
#define ENTITY_H

#include <SEConfig.h>
#include <VectorX.h>
#include <Sprite.h>
#include <Input.h>

class Entity
{
public:
	//The constructor of the entity.
	Entity(std::string title, SE_ERROR* error );
	//The deconstructor of the entity.
	virtual ~Entity();

	//Add a specified entity to become child of the entity.
	void addChild( Entity* child, SE_ERROR* error );

	//Sets the name of the entity in the hierarchy.
	void setTitle(std::string title, SE_ERROR* error );
	//Sets the sprite of the entity.
	void setSprite( Sprite* sprite );
	//Sets the position in local space.
	void setPosition( Vector3 position );
	//Sets the rotation in local space.
	void setRotation( Vector3 rotation );
	//Sets the scale in local space.
	void setScale( Vector3 scale );
	//Sets the model of the entity.
	void setModel( Model* model );

	//Gets the child of the entity by name.
	Entity* getChild( std::string title );
	//Gets the sprite of the entity.
	Sprite* getSprite();
	//Returns the parent of this entity.
	Entity* getParent();
	//Gets the name of the entity in the hierarchy.
	std::string getTitle();
	//Gets the position in local space.
	Vector3 getPosition();
	//Gets the rotation in local space.
	Vector3 getRotation();
	//Gets the scale in local space.
	Vector3 getScale();
	//Gets the model of the entity.
	Model* getModel();
	//The update function of the entity class
	virtual void update();
private:
	//Makes the scene permitted to use private variables/functions of this entity.
	friend class Scene;
	//The scene the entity exists in.
	Scene* _scene;
	//Sets the scene of the entity existence.
	void setScene( Scene* scene );

	//Name of entity in the hierarchy
	std::string _title;

	///Family functions
	//Childs of the entity
	std::vector<Entity*> _childs;
	//Remove a specified child from the entity's list of children.
	void removeChild( Entity* child );
	//Gets all the childs of the entity with the given name.
	std::vector<Entity*> getChilds( std::string title );
	//Set a specified entity as parent of this entity.
	void setParent( Entity* parent );
	//The pointer to the parent of this entity.
	Entity* _parent;
protected:
	//Gets the scene of the entity existence.
	Scene* getScene();
	//The position of this entity in local space.
	Vector3 _position;
	//The rotation of this entity in local space.
	Vector3 _rotation;
	//The scale of this entity in local space.
	Vector3 _scale;
	//Sprite of the entity
	Sprite* _sprite;
	//Model of the entity
	Model* _model;
};

#endif // !ENTITY_H
