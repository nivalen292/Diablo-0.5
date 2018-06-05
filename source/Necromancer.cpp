#include "stdafx.h"
#include "Necromancer.h"

void Necromancer::copy(const Necromancer & other) {
	if (other.minion != NULL) {
		minion = new Skeleton(*other.minion);
	}
	else {
		minion = NULL;
	}
	attackNumber = other.attackNumber;
}

void Necromancer::del() {
	delete minion;
	minion = NULL;
}

Necromancer::Necromancer() : Enemy("Unnamed", 65, 2, 7), attackNumber(-1), minion(NULL) {
}

Necromancer::Necromancer(const char * name) : Enemy(name, 65, 2, 7), attackNumber(-1), minion(NULL) {
}

void Necromancer::attack(Entity * target) {
	attackNumber++;
	attackNumber %= 3;
	if (attackNumber == 0) {
		delete minion;
		minion = new Skeleton();
	}
	if (minion != NULL) {
		setAttackDmg(getIntelligence() + minion->getHp() / 10);
	}
	else {
		setAttackDmg(getIntelligence());
	}
	double dmg = getAttackDmg();
	printAttack(target->getName(), dmg);
	target->defend(dmg);
	if (!target->isAlive()) {

	}
}

void Necromancer::defend(double dmg) {
	if (minion != NULL) {
		minion->defend(dmg);
		if (!minion->isAlive()) {
			delete minion;
			minion = NULL;
		}
	}
	else {
		Enemy::defend(dmg);
	}
}

const char * Necromancer::getClassName() {
	return "Necromancer";
}

Necromancer::Necromancer(const Necromancer & other) : Enemy(other) {
	copy(other);
}

Necromancer & Necromancer::operator=(const Necromancer & other) {
	if (this != &other) {
		Enemy::operator=(other);
		del();
		copy(other);
	}
	return *this;
}

Necromancer::~Necromancer() {
	del();
}

Entity * Necromancer::clone() const {
	return new Necromancer(*this);
}
