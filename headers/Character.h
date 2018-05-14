#ifndef CHARACTER_H
#define CHARACTER_H

#include "Enemy.h"

class Character {
private:

	// stats
	char* name;
	unsigned int level;
	double hp;
	double strength;
	double intelligence;

	// utils
	void copy(const Character& other);
	void del();

protected:
	const double BASE_STRENGTH;
	const double BASE_INTELLIGENCE;

	// levelUp attributes
	unsigned int enemiesSlain;
	unsigned int enemiesToSlay;
	bool hasKilledEnemy(Enemy* target);

	// attack scheme
	virtual double getAttackDmg() = 0;
public:

	// canonical form
	Character();
	Character(const char* name, unsigned int level, double hp, double strength, double intelligence);
	Character(const Character& other);
	~Character();
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

	// funcs
	virtual void attack(Enemy* target) = 0;
	virtual void defend(Enemy* target);
	virtual void levelUp();

	bool isAlive() const;
};

#endif