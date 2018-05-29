#ifndef NECROMANCER_H
#define NECROMANCER_H

#include "Enemy.h"
#include "Skeleton.h"

class Necromancer : public Enemy {
private:
	Skeleton * minion;
	int attackNumber;

	void copy(const Necromancer& other);
	void del();
public:
	Necromancer();
	Necromancer(const char* name);

	void attack(Entity* target);
	void defend(double dmg);

	const char* getClassName();

	Necromancer(const Necromancer& other);
	Necromancer& operator=(const Necromancer& other);
	~Necromancer();
};

#endif