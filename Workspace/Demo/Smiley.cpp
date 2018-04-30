#include <Demo/Smiley.h>

Smiley::Smiley(std::string name, SE_ERROR* error ) : Entity( name, error) {
	Sprite* spr = new Sprite();
	this->setSprite( spr );
}

Smiley::~Smiley() {

}