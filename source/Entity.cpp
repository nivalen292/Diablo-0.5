#include "stdafx.h"
#include "Entity.h"
#include <iostream>
#include <cstring>

void Entity::copy(const Entity & other) {
	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);
	setHp(other.hp);
	setStrength(other.strength);
	setIntelligence(other.intelligence);
	attackDmg = other.attackDmg;
}

void Entity::del() {
	delete[] name;
	name = NULL;
}

Entity::Entity() : BASE_STRENGTH(0), BASE_INTELLIGENCE(0), name(NULL), hp(0), strength(0), intelligence(0), attackDmg(0) {
}

Entity::Entity(const char * name, double hp, double strength, double intelligence) : 
	BASE_STRENGTH(strength), BASE_INTELLIGENCE(intelligence), hp(hp), strength(strength),
	intelligence(intelligence), name(NULL) {
	setName(name);
	setAttackDmg();
}

Entity::Entity(const Entity & other) : BASE_STRENGTH(other.strength), BASE_INTELLIGENCE(other.intelligence) {
	copy(other);
	setAttackDmg(other.attackDmg);
}

Entity & Entity::operator=(const Entity & other) {
	if (this != &other) {
		del();
		copy(other);
	}
	return *this;
}

void Entity::setName(const char * name) {
	if (this->name != NULL) {
		delete[] name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Entity::defend(double dmg) {
	hp -= dmg;
}

bool Entity::isAlive() const {
	return hp > 0;
}

const char * Entity::getName() const {
	return name;
}

void Entity::setHp(double hp) {
	this->hp = hp;
}

double Entity::getHp() const {
	return hp;
}

void Entity::setStrength(double strength) {
	this->strength = strength;
}

double Entity::getStrength() const {
	return strength;
}

void Entity::setIntelligence(double intelligence) {
	this->intelligence = intelligence;
}

double Entity::getIntelligence() const {
	return intelligence;
}

double Entity::getAgility() const {
	return 0;
}

void Entity::setAttackDmg(double dmg) {
	this->attackDmg = dmg;
}

double Entity::getAttackDmg() {
	return attackDmg;
}

void Entity::printAttack(const char * name, double dmg) const {
	std::cout << getName() << " attacked " << name << " for " << dmg << " damage." << std::endl;
}

