#include "stdafx.h"
#include "Barbarian.h"
#include "Skeleton.h"
#include "Character.h"
#include "Enemy.h"

int main() {
	Character* b = new Barbarian("Grudger");
	Enemy* s1 = new Skeleton("Pesho the Skeleton");
	Enemy* s2 = new Skeleton("Clumsy Skeleton");
	b->engage();
	b->attack(s1);
	s1->attack(b);
	b->attack(s1);
	s1->attack(b);
	b->attack(s1);
	s1->attack(b);
	b->attack(s1);
	s1->attack(b);

	b->engage();
	b->attack(s2);
	s2->attack(b);
	b->attack(s2);
	s2->attack(b);

    return 0;
}

