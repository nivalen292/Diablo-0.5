#ifndef GAME_H
#define GAME_H

#include "Character.h"
#include "Enemy.h"

class Game {
private:
	
public:
	Game();

	static Game& getGameInstance();
};

#endif