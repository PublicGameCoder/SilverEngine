#include <Demo/Smiley.h>

Smiley::Smiley(std::string name, SE_ERROR* error ) : Entity( name, error) {
	Sprite* spr = new Sprite("assets/awesomeface.png");
	this->setSprite( spr );
}

Smiley::~Smiley() {

}

void Smiley::update() {
	if ( Input::getManager()->getKey( KeyCode::Right ) ) {
		std::cout << "Switching scenes!" << std::endl;
		Window* window = Input::getManager()->getWindow();
		Scene* scene = window->getCurrentScene();
		window->getSceneManager()->next( scene );
	}else if ( Input::getManager()->getKey( KeyCode::Left ) ) {
		std::cout << "Switching scenes!" << std::endl;
		Window* window = Input::getManager()->getWindow();
		Scene* scene = window->getCurrentScene();
		window->getSceneManager()->prev( scene );
	}
}