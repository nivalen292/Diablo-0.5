#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "Character.h"

class Barbarian : public Character {
private:
	double rage;
protected:
	// levelUp attributes
	const int STAT_DIVIDER;

	// base stats
	// no new base stats

	// attack scheme
	double getAttackDmg();
public:
	Barbarian();
	Barbarian(const char* name);

	void setRage(double rage);
	double getRage() const;

	// funcs
	void attack(Enemy* target);
	void defend(Enemy* target);
	void levelUp();
};

#endif