#include "stdafx.h"
#include "Eretic.h"

Eretic::Eretic() : Enemy("Unnamed", 20, 1, 4) {
}

Eretic::Eretic(const char * name) : Enemy(name, 20, 1, 4) {
}

void Eretic::attack(Entity * target) {
	setAttackDmg(getIntelligence() + getLowestStat(target));
	double dmg = getAttackDmg();
	printAttack(target->getName(), dmg);
	target->defend(dmg);
	if (!target->isAlive()) {

	}
}

double Eretic::getLowestStat(Entity * target) {
	double stat = target->getStrength();
	if (stat > target->getAgility() && target->getAgility() > 0) {
		stat = target->getAgility();
	}
	if (stat > target->getIntelligence() && target->getIntelligence() > 0) {
		stat = target->getIntelligence();
	}
	return stat;
}

const char * Eretic::getClassName() {
	return "Eretic";
}

Entity * Eretic::clone() const {
	return new Eretic(*this);
}
