#ifndef BOUNTY_HUNTER_H
#define BOUNTY_HUNTER_H

#include "Character.h"

class BountyHunter : public Character {
private:
	double agility;
	const int STAT_DIVIDER;
	const int BASE_AGILITY;

	int specialAttack;

public:
	BountyHunter();
	BountyHunter(const char* name);

	void attack(Entity* target);
	void defend(double dmg);
	void levelUp();

	void setAgility(double agility);
	double getAgility();

	const char* getClassName();

	void disengage();
	void engage();


	virtual Entity* clone() const;
};

#endif