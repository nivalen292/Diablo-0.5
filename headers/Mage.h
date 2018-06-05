#ifndef MAGE_H
#define MAGE_H

#include "Character.h"

class Mage : public Character {
private:
	double manaCap;
	double mana;
	const int STAT_DIVIDER;

	void reduceMana(int mana);

public:
	Mage();
	Mage(const char* name);

	void attack(Entity* target);
	void defend(double dmg);
	void levelUp();

	const char* getClassName();

	void refillMana();

	void disengage();
	void engage();

	virtual Entity* clone() const;
};

#endif