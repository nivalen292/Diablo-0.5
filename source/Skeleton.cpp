#include "stdafx.h"
#include "Enemy.h"
#include "Character.h"
#include "Skeleton.h"
#include <iostream>

Skeleton::Skeleton() : Enemy("Unnamed", 32, 3, 0) {
}

Skeleton::Skeleton(const char * name) : Enemy(name, 32, 3, 0) {
}

Skeleton::Skeleton(const Skeleton & other) : Enemy(other) {
}

void Skeleton::attack(Entity * target) {
	setAttackDmg(getStrength() + target->getIntelligence() / 10);
	double dmg = getAttackDmg();
	printAttack(target->getName(), dmg);
	target->defend(dmg);
	if (!target->isAlive()) {
		
	}
}

const char * Skeleton::getClassName() {
	return "Skeleton";
}

Entity * Skeleton::clone() const {
	return new Skeleton(*this);
}
