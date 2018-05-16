#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "Character.h"

class Barbarian : public Character {
private:
	double rage;
	double offsetDmg;
protected:
	// levelUp attributes
	const int STAT_DIVIDER;

	// base stats
	// no new base stats

public:
	Barbarian();
	Barbarian(const char* name);

	void setRage(double rage);
	double getRage() const;
	void increaseRage(int rage);

	// funcs
	void attack(Enemy* target);
	void defend(double dmg);
	void levelUp();

	void disengage();
	void engage();

	void enrage();
};

#endif