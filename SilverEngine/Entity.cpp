#include <Entity.h>

//The constructor of the entity.
Entity::Entity(std::string title, SE_ERROR* error) {
	this->_parent = nullptr;
	this->_scene = nullptr;
	this->_sprite = nullptr;
	this->setTitle( title, error );
}

//The deconstructor of the entity.
Entity::~Entity() {
	if ( this->_parent != nullptr ) {
		this->_parent->removeChild( this );//Removes this entity from the parent's list of children and sets the parent to nullptr.
	}
}

void Entity::update() {
	for ( Entity* child : _childs ) {
		child->update();
	}
}

//Add a specified entity to become child of the entity.
void Entity::addChild( Entity* child, SE_ERROR* error ) {
	this->_childs.push_back( child );
	child->setParent( this );
	child->setTitle( child->getTitle(), error );
}

//Remove a specified child from the entity's list of children.
void Entity::removeChild( Entity* child ) {
	std::vector<Entity*>::iterator it = std::find( _childs.begin(), _childs.end(), child );
	if ( it != _childs.end() ) {
		_childs.erase( it );
		child->setParent( nullptr );//Remove the link towards the parent.
	}
}

//Set a specified entity as parent of this entity.
void Entity::setParent( Entity* parent ) {
	Entity* p = getParent();
	if ( p != nullptr ) {
		p->removeChild( this );
	}
	this->_parent = parent;
}
//Sets the scene of the entity existence.
void Entity::setScene( Scene* scene ) {
	this->_scene = scene;
}

//Gets the scene of the entity existence.
Scene* Entity::getScene() {
	Scene* scene = _scene;
	if ( scene == nullptr ) {
		if ( this->getParent() != nullptr ) {
			scene = this->getParent()->getScene();
		}
	}
	return scene;
}

//Sets the name of the entity in the hierarchy.
void Entity::setTitle(std::string title, SE_ERROR* error) {
	Entity* parent = this->getParent();
	if ( parent != nullptr ) {
		std::vector<Entity*> nameDups = parent->getChilds( title );
		if ( !nameDups.empty() && nameDups.size() > 1 ) {
			title += " " + std::to_string( nameDups.size() - 2);
			*error = SE_FAILED_NAMEALREADYEXISTSBUTGOTCHANGED;
		}
	}
	this->_title = title;
}

//Sets the sprite of the entity.
void Entity::setSprite( Sprite* sprite ) {
	this->_sprite = sprite;
}
//Sets the position in local space.
void Entity::setPosition( Vector3 position ) {
	this->_position = position;
}

//Sets the rotation in local space.
void Entity::setRotation( Vector3 rotation ) {
	this->_rotation = rotation;
}

//Sets the scale in local space.
void Entity::setScale( Vector3 scale ) {
	this->_scale = scale;
}

//Sets the model of the entity.
void Entity::setModel( Model* model ) {
	this->_model = model;
}

//Gets the child of the entity by name.
Entity* Entity::getChild( std::string title ) {
	for ( Entity* entity : _childs ) {
		if ( std::strcmp( entity->getTitle().c_str(), title.c_str() ) == 0 ) {
			return entity;
		}
	}
	return nullptr;
}
//Gets all the childs of the entity with the given name.
std::vector<Entity*> Entity::getChilds( std::string title ) {
	std::vector<Entity*> childs = std::vector<Entity*>();
	for ( Entity* entity : this->_childs ) {
		if ( std::strcmp( entity->getTitle().c_str(),title.c_str()) == 0) {
			childs.push_back( entity );
		}
	}
	return childs;
}
//Gets the sprite of the entity.
Sprite* Entity::getSprite() {
	return this->_sprite;
}
//Returns the parent of this entity.
Entity* Entity::getParent() {
	return this->_parent;
}

//Gets the name of the entity in the hierarchy.
std::string Entity::getTitle() {
	return this->_title;
}

//Gets the position in local space.
Vector3 Entity::getPosition() {
	return this->_position;
}

//Gets the rotation in local space.
Vector3 Entity::getRotation() {
	return this->_rotation;
}

//Gets the scale in local space.
Vector3 Entity::getScale() {
	return this->_scale;
}

//Gets the model of the entity.
Model* Entity::getModel() {
	return this->_model;
}