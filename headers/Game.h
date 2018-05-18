#ifndef GAME_H
#define GAME_H

#include "Character.h"
#include "Enemy.h"
#include "Entity.h"
#include "Barbarian.h"
#include "Skeleton.h"
#include "CharacterFactory.h"


class Game {
private:
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
	void chooseCharacter(); // add loop to handle wrong input
	void displayInstructions();
	void fight(Entity* a, Entity* b);
	void fillBoard(int size);
	void executeCommand();
	void move(char direction);
	void printCurrentLocation();

	static Game& getGameInstance();

	~Game();
};

#endif