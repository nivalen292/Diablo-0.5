#include "stdafx.h"
#include "Enemy.h"
#include "Character.h"
#include <iostream>
#include <cstring>

Enemy::Enemy() : Entity() {
}

Enemy::Enemy(const char * name, double hp, double strength, double intelligence)  : 
	Entity(name, hp, strength, intelligence) {
}
