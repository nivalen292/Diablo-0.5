#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Character;

class Enemy : public Entity {
private:

public:
	Enemy();
	Enemy(const char* name, double hp, double strength, double intelligence);

	virtual const char* getClassName() { return "Enemy"; };

};

#endif