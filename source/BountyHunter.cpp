#include "stdafx.h"
#include "BountyHunter.h"

BountyHunter::BountyHunter() : Character("Unnamed", 1, 80, 9, 6),
	agility(10), BASE_AGILITY(10),
	STAT_DIVIDER((int)(BASE_STRENGTH + BASE_INTELLIGENCE + 10)), specialAttack(0) {
	setAttackDmg(agility * 0.8);
}

BountyHunter::BountyHunter(const char * name) : Character(name, 1, 80, 9, 6),
	agility(10), BASE_AGILITY(10),
	STAT_DIVIDER((int)(BASE_STRENGTH + BASE_INTELLIGENCE + 10)), specialAttack(0) {
	setAttackDmg(agility * 0.8);
}

void BountyHunter::attack(Entity * target) {
	if (!inFight) {
		engage();
	}

	specialAttack++;
	specialAttack %= 3;

	double dmg = getAttackDmg();
	if (specialAttack == 0) {
		dmg = agility + 0.4 * agility + 0.6 * getStrength();
	}

	target->defend(dmg);
	printAttack(target->getName(), dmg);

	if (!target->isAlive()) {
		increaseEnemiesSlain();
		disengage();
	}
}

void BountyHunter::defend(double dmg) {
	Character::defend(dmg);
}

void BountyHunter::levelUp() {
	Character::levelUp();
	setStrength((BASE_STRENGTH / STAT_DIVIDER * 5) + getStrength());
	setIntelligence((BASE_INTELLIGENCE / STAT_DIVIDER * 5) + getIntelligence());
	setAgility((BASE_AGILITY / (double)STAT_DIVIDER) * 5 + agility);
	setAttackDmg(agility * 0.8);
}

void BountyHunter::setAgility(double agility) {
	this->agility = agility;
}

double BountyHunter::getAgility() {
	return agility;
}

const char * BountyHunter::getClassName() {
	return "BountyHunter";
}

void BountyHunter::disengage() {
	Character::disengage();
}

void BountyHunter::engage() {
	Character::disengage();
}

Entity * BountyHunter::clone() const {
	return new BountyHunter(*this);
}
