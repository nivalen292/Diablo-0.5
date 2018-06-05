#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "Character.h"

class Barbarian : public Character {
private:
	bool enraged;
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

	const char* getClassName();

	// funcs
	void attack(Entity* target);
	void defend(double dmg);
	void levelUp();

	void disengage();
	void engage();

	void enrage();


	virtual Entity* clone() const;
};

#endif