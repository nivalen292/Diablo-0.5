#include "stdafx.h"
#include "Character.h"
#include "Enemy.h"
#include <iostream>
#include <cstring>
#include <cmath>

void Character::engage() {
	inFight = true;
}

void Character::disengage() {
	if (enemiesSlain == enemiesToSlay) {
		levelUp();
	}
	inFight = false;
}

Character::Character() : Entity(), inFight(false) {
}

Character::Character(const char * name, unsigned int level, double hp, double strength, double intelligence) :
		Entity(name, hp, strength, intelligence), level(1),
		enemiesSlain(0), enemiesToSlay(pow(2, level)), inFight(false) {
}

void Character::increaseEnemiesSlain() {
	enemiesSlain++;
}


void Character::levelUp() {
	std::cout << "Ding! You leveled up." << std::endl;
	level++;
	setHp(getHp() + (getHp() * 0.10));
	enemiesToSlay = (int)pow(2, level);
}

