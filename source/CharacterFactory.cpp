#include "stdafx.h"
#include "CharacterFactory.h"
#include <cstring>

Character * CharacterFactory::getCharacter(const char * className, const char* name) {
	if (strcmp(className, "Barbarian") == 0) {
		return new Barbarian(name);
	}
	if (strcmp(className, "Sorcerer") == 0) {
		return new Mage(name);
	}
	if (strcmp(className, "BountyHunter") == 0) {
		return new BountyHunter(name);
	}
	return NULL;
}
