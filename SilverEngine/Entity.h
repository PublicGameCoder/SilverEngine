#ifndef ENTITY_H
#define ENTITY_H

#include <SEConfig.h>

class Entity
{
public:
	Entity(std::string title);
	virtual ~Entity();

	std::string getTitle();
private:
	std::string _title;
};

#endif // !ENTITY_H
