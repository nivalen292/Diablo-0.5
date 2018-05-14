#include "stdafx.h"
#include "Barbarian.h"


double Barbarian::getAttackDmg() {
	double dmg =  getStrength() + (0.2 * getIntelligence()) + (rage / 5);
	rage = 0;
	return dmg;
}

Barbarian::Barbarian() : Character(), rage(0), STAT_DIVIDER(13) {

}

Barbarian::Barbarian(const char * name) : Character(name, 1, 100, 10, 3), rage(0), 
	STAT_DIVIDER(BASE_STRENGTH + BASE_INTELLIGENCE) {
}

void Barbarian::setRage(double rage) {
	if (rage > 100) {
		this->rage = 100;
		return;
	}
	this->rage = rage;
}

double Barbarian::getRage() const {
	return rage;
}

void Barbarian::attack(Enemy * target) {
	static double dmg = getAttackDmg();
	target->setHealth(target->getHealth() - dmg);
	setRage(rage + 2);
}

void Barbarian::defend(Enemy * target) {
	Character::defend(target);
	setRage(rage + 3);
}

void Barbarian::levelUp() {
	Character::levelUp();
	setStrength((BASE_STRENGTH / STAT_DIVIDER * 5) + getStrength());
	setIntelligence((BASE_INTELLIGENCE / STAT_DIVIDER * 5) + getIntelligence());
}
