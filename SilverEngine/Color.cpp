#include <Color.h>

RGBAColor::RGBAColor() {
	this->r = 0.0f;
	this->g = 0.2f;
	this->b = 0.2f;
	this->a = 0.0f;
}

RGBAColor::RGBAColor( float red, float green, float blue, float alpha ) {
	this->r = red;
	this->g = green;
	this->b = blue;
	this->a = alpha;
}

RGBAColor::~RGBAColor() {

}