#ifndef SKELETON_H
#define SKELETON_H

#include "Enemy.h"

class Skeleton : public Enemy {
private:

protected:

public:
	Skeleton();
	Skeleton(const char* name);

	void attack(Entity* target);
};

#endif