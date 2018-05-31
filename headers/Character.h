#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.h"

class Enemy;

class Character : public Entity {
private:
	unsigned int level;

protected:
	bool inFight;

	// levelUp attributes
	unsigned int enemiesSlain;
	unsigned int enemiesToSlay;
	
public:

	Character();
	Character(const char* name, unsigned int level, double hp, double strength, double intelligence);

	void increaseEnemiesSlain();

	virtual const char* getClassName() { return "Character"; };

	virtual void levelUp();

	// attack scheme
	virtual void engage();
	virtual void disengage();
};

#endif