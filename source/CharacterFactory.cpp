#include "stdafx.h"
#include "CharacterFactory.h"
#include <cstring>

Character * CharacterFactory::getCharacter(const char * className, const char* name) {
	if (className == NULL) {
		return NULL;
	}
	if (strcmp(className, "Barbarian") == 0) {
		return new Barbarian(name);
	}
	if (strcmp(className, "Sorcerer") == 0) {
		return new Mage(name);
	}
	return NULL;
}
