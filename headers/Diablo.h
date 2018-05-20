#ifndef DIABLO_H
#define DIABLO_H

#include "Skeleton.h"
#include "Eretic.h"

class Diablo : public Skeleton, public Eretic {
private:
	int attackNumber;
public:
	Diablo();
	Diablo(const char* name);

	void attack(Entity* target);

	const char* getClassName();
};

#endif