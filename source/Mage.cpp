#include "stdafx.h"
#include "Mage.h"
#include <iostream>

void Mage::reduceMana(int mana) {
	this->mana -= mana;
}

Mage::Mage() : Character("Unnamed", 1, 70, 4, 12),
	manaCap(100), mana(100), STAT_DIVIDER((int)(BASE_STRENGTH + BASE_INTELLIGENCE)) {
}

Mage::Mage(const char * name) : Character(name, 1, 70, 4, 12), manaCap(100), mana(100),
	STAT_DIVIDER((int)(BASE_STRENGTH + BASE_INTELLIGENCE)) {
}

void Mage::attack(Entity * target) {
	if (mana >= manaCap / 10) {
		if (!inFight) {
			engage();
		}

		double dmg = ((mana / manaCap) * 0.75 + (((mana / manaCap) * 0.75) * 0.5)) * getIntelligence();
		reduceMana(manaCap / 10);
		target->defend(dmg);
		printAttack(target->getName(), dmg);

		if (!target->isAlive()) {
			increaseEnemiesSlain();
			refillMana();
			disengage();
		}
	}
	else {
		std::cout << "Not enough mana" << std::endl;
	}
}

void Mage::defend(double dmg) {
	Character::defend(dmg);
}

void Mage::levelUp() {
	Character::levelUp();
	setStrength((BASE_STRENGTH / STAT_DIVIDER * 5) + getStrength());
	setIntelligence((BASE_INTELLIGENCE / STAT_DIVIDER * 5) + getIntelligence());
	manaCap = manaCap + manaCap * 0.10;
	mana = manaCap;
}


const char * Mage::getClassName() {
	return "Sorcerer";
}

void Mage::refillMana() {
	mana = manaCap;
}

void Mage::disengage() {
	Character::disengage();
}

void Mage::engage() {
	Character::engage();
}

Entity * Mage::clone() const {
	return new Mage(*this);
}
