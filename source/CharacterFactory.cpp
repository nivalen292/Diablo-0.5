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
	return NULL;
}
