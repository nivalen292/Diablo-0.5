#include "stdafx.h"
#include  "Enemy.h"
#include "Barbarian.h"


Barbarian::Barbarian() : Character(), rage(0), STAT_DIVIDER(13), offsetDmg(0) {
	setAttackDmg();
}

Barbarian::Barbarian(const char * name) : Character(name, 1, 100, 10, 3), rage(0), 
	STAT_DIVIDER((int)(BASE_STRENGTH + BASE_INTELLIGENCE)), offsetDmg(0) {
	setAttackDmg(getStrength() + (0.2 * getIntelligence()));
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
	target->setHp(target->getHp() - getAttackDmg());
	setRage(rage + 2);
	if (!target->isAlive()) {
		setAttackDmg(getAttackDmg() - offsetDmg); // derage
	}
}

void Barbarian::defend(Enemy * target) {
	Character::defend(target);
	setRage(rage + 3);
}

void Barbarian::levelUp() {
	Character::levelUp();
	setStrength((BASE_STRENGTH / STAT_DIVIDER * 5) + getStrength());
	setIntelligence((BASE_INTELLIGENCE / STAT_DIVIDER * 5) + getIntelligence());
	setAttackDmg(); // lookup
}

void Barbarian::enrage() { // call inside Game::fight(op1, op2)
	double oldDmg = getAttackDmg();
	setAttackDmg(getAttackDmg() + (rage / 5));
	offsetDmg = getAttackDmg() - oldDmg;
	rage = 0;
}
