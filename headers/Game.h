#ifndef GAME_H
#define GAME_H

#include <cstdlib>

#include "Character.h"
#include "Enemy.h"
#include "Entity.h"
#include "Barbarian.h"
#include "Skeleton.h"
#include "Mage.h"
#include "Eretic.h"
#include "Diablo.h"
#include "Necromancer.h"
#include "CharacterFactory.h"


class Game {
private:
	int moves;
	Entity * player;
	const int BOARD_SIZE;
	int currentX;
	int currentY;
	Entity* board[10][10];
	CharacterFactory factory;

	bool isValidPosition(int x, int y);
	bool hasEnemy(int x, int y);

	Game();
public:

	void run();
	void chooseCharacter();
	void displayInstructions();
	void fight(Entity* a, Entity* b);
	void fillBoard();
	void executeCommand();
	void move(char direction);

	void printBoard();
	void printCurrentLocation();

	static Game& getGameInstance();

	~Game();
};

#endif