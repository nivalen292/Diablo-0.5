#include "stdafx.h"
#include "Character.h"
#include <cstring>
#include <cmath>

void Character::copy(const Character & other) {
	setName(other.name);
	setLevel(other.level);
	setHp(other.hp);
	setStrength(other.strength);
	setIntelligence(other.intelligence);
}

void Character::del() {
	delete[] name;
}

bool Character::hasKilledEnemy(Enemy * target) {
	return !target->isAlive();
}

Character::Character() : name(NULL), level(0), hp(0), strength(0), intelligence(0),
		enemiesSlain(0), enemiesToSlay(0), BASE_STRENGTH(0), BASE_INTELLIGENCE(0) {

}

Character::Character(const char * name, unsigned int level, double hp, double strength, double intelligence) :
		name(NULL), level(level), hp(hp), strength(strength), intelligence(intelligence),
		enemiesSlain(0), enemiesToSlay(pow(2, level)), BASE_STRENGTH(strength), BASE_INTELLIGENCE(intelligence) {
	setName(name);
}

Character::Character(const Character & other) : BASE_STRENGTH(strength), BASE_INTELLIGENCE(intelligence) {
	copy(other);
}

Character::~Character() {
	del();
}

Character & Character::operator=(const Character & other) {
	if (this != &other) {
		del();
		copy(other);
	}
	return *this;
}

void Character::setHp(double hp) {
	this->hp = hp;
}

void Character::setLevel(unsigned int level) {
	this->level = level;
}

double Character::getLevel() const {
	return level;
}

double Character::getHp() const {
	return hp;
}

void Character::setStrength(double strength) {
	this->strength = strength;
}

double Character::getStrength() const {
	return strength;
}

void Character::setIntelligence(double intelligence) {
	this->intelligence = intelligence;
}

double Character::getIntelligence() const {
	return intelligence;
}

void Character::defend(Enemy * target) {
	double enemyDmg = target->getAttackDmg();
	enemyDmg *= (strength / 100);
	setHp(getHp() - enemyDmg);
}

void Character::levelUp() {
	level++;
	setHp(getHp() + (getHp() * 0.10));
	enemiesToSlay = pow(2, level);
}

bool Character::isAlive() const {
	return (hp <= 0);
}

void Character::setName(const char * name) {
	if (name != NULL) {
		delete[] name;
	}
	name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

const char * Character::getName() const {
	return name;
}