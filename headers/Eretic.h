#ifndef ERETIC_H
#define ERETIC_H

#include "Enemy.h"

class Eretic : virtual public Enemy {
private:

public:
	Eretic();
	Eretic(const char* name);

	void attack(Entity* target);
	double getLowestStat(Entity* target);

	const char* getClassName();

	virtual Entity* clone() const;
};

#endif