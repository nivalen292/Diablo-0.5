#include "stdafx.h"
#include "Enemy.h"
#include "Barbarian.h"
#include <iostream>


Barbarian::Barbarian() : Character("Unnamed", 1, 100, 10, 3), rage(0), 
	STAT_DIVIDER((int)(BASE_STRENGTH + BASE_INTELLIGENCE)), offsetDmg(0), enraged(false) {
	setAttackDmg(getStrength() + (0.2 * getIntelligence()));
}

Barbarian::Barbarian(const char * name) : Character(name, 1, 100, 10, 3), rage(0), 
	STAT_DIVIDER((int)(BASE_STRENGTH + BASE_INTELLIGENCE)), offsetDmg(0), enraged(false) {
	setAttackDmg(getStrength() + (0.2 * getIntelligence()));
}

void Barbarian::setRage(double rage) {
	this->rage = rage;
}

double Barbarian::getRage() const {
	return rage;
}

void Barbarian::increaseRage(int rage) {
	if (this->rage + rage > 100) {
		this->rage = 100;
		std::cout << getName() << " gained " << 100 - this->rage << " rage." << std::endl;
	}
	else {
		this->rage += rage;
		std::cout << getName() << " gained " << rage << " rage." << std::endl;
	}
}

const char * Barbarian::getClassName() {
	return "Barbarian";
}

void Barbarian::attack(Entity * target) {
	if (!inFight) {
		engage();
	}
	double dmg = getAttackDmg();
	target->defend(dmg);
	printAttack(target->getName(), dmg);

	increaseRage(2);
	if (!target->isAlive()) {
		increaseEnemiesSlain();
		disengage();
	}
}

void Barbarian::defend(double dmg) {
	Character::defend(dmg);
	increaseRage(3);
}

void Barbarian::levelUp() {
	Character::levelUp();
	setStrength((BASE_STRENGTH / STAT_DIVIDER * 5) + getStrength());
	setIntelligence((BASE_INTELLIGENCE / STAT_DIVIDER * 5) + getIntelligence());
	setAttackDmg(offsetDmg + getStrength() + getIntelligence() * 0.2); // TO FIX
}

void Barbarian::disengage() {
	Character::disengage();
	setAttackDmg(getAttackDmg() - offsetDmg); // derage
	enraged = false;
}

void Barbarian::engage() {
	Character::engage();
	enrage();
}

void Barbarian::enrage() {
	if (!enraged) {
		enraged = true;
		double oldDmg = getAttackDmg();
		setAttackDmg(getAttackDmg() + (rage / 5));
		offsetDmg = getAttackDmg() - oldDmg;
		std::cout << getName() << " enraged and gained " << rage / 5 << " damage." << std::endl;
		rage = 0;
	}
}

Entity * Barbarian::clone() const {
	return new Barbarian(*this);
}
