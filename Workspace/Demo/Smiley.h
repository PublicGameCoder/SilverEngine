#ifndef SMILEY_H
#define SMILEY_H

#include <Entity.h>
#include <Engine.h>

class Smiley : public Entity
{
public:
	Smiley(std::string name, SE_ERROR* error );
	virtual ~Smiley();

	virtual void update();
private:

};

#endif // !SMILEY_H