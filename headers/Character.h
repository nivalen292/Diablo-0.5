#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.h"

class Enemy;

class Character : public Entity {
private:

	// stats
	char* name;
	unsigned int level;
	double hp;
	double strength;
	double intelligence;

	double attackDmg;

	// utils
	void copy(const Character& other);
	void del();

protected:
	bool inFight; // add to Enemy?

	const double BASE_STRENGTH;
	const double BASE_INTELLIGENCE;

	// levelUp attributes
	unsigned int enemiesSlain;
	unsigned int enemiesToSlay;
	
public:

	// canonical form
	Character();
	Character(const char* name, unsigned int level, double hp, double strength, double intelligence);
	Character(const Character& other);
	virtual ~Character();
	Character& operator=(const Character& other);

	// setters and getters
	void setName(const char* name);
	const char* getName() const;

	void setLevel(unsigned int level);
	double getLevel() const;

	void setHp(double hp);
	double getHp() const;

	void setStrength(double strength);
	double getStrength() const;

	void setIntelligence(double intelligence);
	double getIntelligence() const;

	double getAgility() const;

	void setAttackDmg(double dmg = 0);
	double getAttackDmg();

	virtual const char* getClassName();

	void increaseEnemiesSlain();

	// funcs
	virtual void attack(Entity* target) = 0;
	virtual void defend(double dmg);
	virtual void levelUp();

	// attack scheme
	virtual void engage();
	virtual void disengage();

	bool isAlive() const;

	void printAttack(const char* name, double dmg) const;
};

#endif