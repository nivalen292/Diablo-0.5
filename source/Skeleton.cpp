#include "stdafx.h"
#include "Enemy.h"
#include "Character.h"
#include "Skeleton.h"
#include <iostream>

Skeleton::Skeleton() : Enemy("Unnamed", 32, 3, 0) {
}

Skeleton::Skeleton(const char * name) : Enemy(name, 32, 3, 0) {
}

void Skeleton::attack(Character * target) {
	setAttackDmg(getStrength() + target->getIntelligence() / 10);
	double dmg = getAttackDmg();
	printAttack(target->getName(), dmg);
	target->defend(dmg);
	if (!target->isAlive()) {
		
	}
}
