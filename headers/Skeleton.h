#ifndef SKELETON_H
#define SKELETON_H

#include "Enemy.h"

class Skeleton : virtual public Enemy {
private:

public:
	Skeleton();
	Skeleton(const char* name);
	Skeleton(const Skeleton& other);

	void attack(Entity* target);

	const char* getClassName();

	virtual Entity* clone() const;
};

#endif