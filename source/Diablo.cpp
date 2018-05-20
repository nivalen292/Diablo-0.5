#include "stdafx.h"
#include "Diablo.h"

Diablo::Diablo() : Enemy("Unnamed", 350, 8, 4), Skeleton("Unnamed"), Eretic("Unnamed"), attackNumber(0) {
}

Diablo::Diablo(const char * name) : Enemy(name, 350, 8, 4), Skeleton(name), Eretic(name), attackNumber(0) {
}

void Diablo::attack(Entity * target) {
	attackNumber++;
	attackNumber %= 2;
	if (attackNumber == 1) {
		Skeleton::attack(target);
	}
	else if (attackNumber == 0) {
		Eretic::attack(target);
	}
	if (!target->isAlive()) {

	}
}

const char * Diablo::getClassName() {
	return "Diablo";
}
