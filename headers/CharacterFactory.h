#ifndef CHARACTER_FACTORY_H
#define CHARACTER_FACTORY_H

#include "Character.h"
#include "Barbarian.h"

class CharacterFactory {
public:
	Character * getCharacter(const char* className, const char* name);
};

#endif