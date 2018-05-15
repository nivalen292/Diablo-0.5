#include "stdafx.h"
#include "Enemy.h"
#include "Character.h"
#include <cstring>

void Enemy::copy(const Enemy & other) {
	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);
	setHp(other.hp);
	setStrength(other.strength);
	setIntelligence(other.intelligence);
	attackDmg = other.attackDmg;
}

void Enemy::del() {
	delete[] name;
}

bool Enemy::hasKilledCharacter(Character * target) {
	return !target->isAlive();
}

Enemy::Enemy() : BASE_STRENGTH(0), BASE_INTELLIGENCE(0), name(NULL), hp(0), strength(0), intelligence(0), attackDmg(0) {
}

Enemy::Enemy(const char * name, double hp, double strength, double intelligence)  : 
	BASE_STRENGTH(strength), BASE_INTELLIGENCE(intelligence), hp(hp), strength(strength), intelligence(intelligence) {
	setAttackDmg();
}

Enemy::Enemy(const Enemy & other) : BASE_STRENGTH(other.strength), BASE_INTELLIGENCE(other.intelligence) {
	copy(other);
	setAttackDmg(other.attackDmg);
}

Enemy::~Enemy() {
	del();
}

Enemy & Enemy::operator=(const Enemy & other) {
	if (this != &other) {
		del();
		copy(other);
	}
	return *this;
}

void Enemy::setName(const char * name) {
	if (this->name != NULL) {
		delete[] name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

const char * Enemy::getName() const {
	return name;
}

void Enemy::setHp(double hp) {
	this->hp = hp;
}

double Enemy::getHp() const {
	return hp;
}

void Enemy::setStrength(double strength) {
	this->strength = strength;
}

double Enemy::getStrength() const {
	return strength;
}

void Enemy::setIntelligence(double intelligence) {
	this->intelligence = intelligence;
}

double Enemy::getIntelligence() const {
	return intelligence;
}

void Enemy::setAttackDmg(double dmg) {
}

double Enemy::getAttackDmg() {
	return attackDmg;
}

void Enemy::defend(Character * target) {
	double characterDmg = target->getAttackDmg();
	characterDmg *= (strength / 100);
	hp -= characterDmg;
}

bool Enemy::isAlive() const {
	return (hp > 0);
}