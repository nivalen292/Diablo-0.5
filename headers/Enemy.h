#ifndef ENEMY_H
#define ENEMY_H

class Character;

class Enemy {
private:
	// stats
	char* name;
	double hp;
	double strength;
	double intelligence;

	double attackDmg;

	// utils
	void copy(const Enemy& other);
	void del();
protected:
	const double BASE_STRENGTH;
	const double BASE_INTELLIGENCE;

public:
	// canonical form
	Enemy();
	Enemy(const char* name, double hp, double strength, double intelligence);
	Enemy(const Enemy& other);
	~Enemy();
	Enemy& operator=(const Enemy& other);

	// setters and getters
	void setName(const char* name);
	const char* getName() const;

	void setHp(double hp);
	double getHp() const;

	void setStrength(double strength);
	double getStrength() const;

	void setIntelligence(double intelligence);
	double getIntelligence() const;

	void setAttackDmg(double dmg = 0);
	double getAttackDmg();

	// funcs
	virtual void attack(Character* target) = 0;
	virtual void defend(double dmg);

	bool isAlive() const;

	void printAttack(const char* name, double dmg) const;
};

#endif