#include "stdafx.h"
#include "Game.h"
#include <iostream>

bool Game::isValidPosition(int x, int y) {
	return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE);
}

bool Game::hasEnemy(int x, int y) {
	return (board[x][y] != NULL) && isValidPosition(x, y);
}

Game::Game() : BOARD_SIZE(10), currentX(0), currentY(0) {
	fillBoard(BOARD_SIZE);
	board[currentX][currentY] = player;
}

void Game::run() {
	displayInstructions();
	chooseCharacter();
	printCurrentLocation();
	while (currentX != BOARD_SIZE - 1 && currentY != BOARD_SIZE - 1) {
		executeCommand();
	}
}

void Game::chooseCharacter() {
	std::cout << "Choose you name (max length 20):" << std::endl;
	char name[20] = "";
	std::cin.getline(name, 20);
	std::cout << "Choose you character!" << std::endl;
	std::cout << "Type in one of the folling:" << std::endl;
	std::cout << "Barbarian" << std::endl;
	std::cout << "Necromancer" << std::endl;
	std::cout << "Headhunter" << std::endl;
	char choice[20] = ""; // limited character names
	std::cin.getline(choice, 20);
	player = factory.getCharacter(choice, name);
	std::cout << std::endl;
}

void Game::displayInstructions() {
	std::cout << "Welcome to the wonderful yet fearsome game Diablo 0.5!" 
		<< "You will be given a choice of character." 
		<< "Your goal will be to travel to the south-eastern part of the board killing everything in your way." 
		<< "Commands: move + direction(left, right, up, down)"<< std::endl;
}

void Game::fight(Entity * a, Entity * b) {
}

void Game::fillBoard(int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j] = NULL;
		}
	}
	// testing purposes
	board[0][1] = new Skeleton("clumsy"); // TO FIX same name as player
}

void Game::executeCommand() {
	std::cout << "Enter a command:" << std::endl;
	char choice[20] = "";
	std::cin.getline(choice, 20);
	if (strcmp(choice, "move left") == 0) {
		move('l');
	}
	else if (strcmp(choice, "move right") == 0) {
		move('r');
	}
	else if (strcmp(choice, "move up") == 0) {
		move('u');
	}
	else if (strcmp(choice, "move down") == 0) {
		move('d');
	}
	else {
		std::cout << "Invalid command!" << std::endl;
	}
}

void Game::move(char direction) {
	switch (direction) {
		case 'u':
			if (isValidPosition(currentX - 1, currentY)) {
				if (!hasEnemy(currentX - 1, currentY)) {
					board[currentX - 1][currentY] = player; // move player
					board[currentX][currentY] = NULL; // remove player from previous
					currentX--;
				}
				else {
					player->attack(board[currentX - 1][currentY]);
					if (board[currentX - 1][currentY]->isAlive()) {
						board[currentX - 1][currentY]->attack(player);
					}
					else {
						board[currentX - 1][currentY] = NULL;
					}
				}
			}
			else {
				std::cout << "Invalid move, you cannot go outside the board!" << std::endl;
			}
			break;
		case 'd':
			if (isValidPosition(currentX + 1, currentY)) {
				if (!hasEnemy(currentX + 1, currentY)) {
					board[currentX + 1][currentY] = player; // move player
					board[currentX][currentY] = NULL; // remove player from previous
					currentX++;
				}
				else {
					player->attack(board[currentX + 1][currentY]);
					if (board[currentX + 1][currentY]->isAlive()) {
						board[currentX + 1][currentY]->attack(player);
					}
					else {
						board[currentX + 1][currentY] = NULL;
					}
				}
			}
			else {
				std::cout << "Invalid move, you cannot go outside the board!" << std::endl;
			}
			break;
		case 'l':
			if (isValidPosition(currentX, currentY - 1)) {
				if (!hasEnemy(currentX, currentY - 1)) {
					board[currentX][currentY - 1] = player; // move player
					board[currentX][currentY] = NULL; // remove player from previous
					currentY--;
				}
				else {
					player->attack(board[currentX][currentY - 1]);
					if (board[currentX][currentY - 1]->isAlive()) {
						board[currentX][currentY - 1]->attack(player);
					}
					else {
						board[currentX][currentY - 1] = NULL;
					}
				}
			}
			else {
				std::cout << "Invalid move, you cannot go outside the board!" << std::endl;
			}
			break;
		case 'r':
			if (isValidPosition(currentX, currentY + 1)) {
				if (!hasEnemy(currentX, currentY + 1)) {
					board[currentX][currentY + 1] = player; // move player
					board[currentX][currentY] = NULL; // remove player from previous
					currentY++;
				}
				else {
					player->attack(board[currentX][currentY + 1]);
					if (board[currentX][currentY + 1]->isAlive()) {
						board[currentX][currentY + 1]->attack(player);
					}
					else {
						board[currentX][currentY + 1] = NULL;
					}
				}
			}
			else {
				std::cout << "Invalid move, you cannot go outside the board!" << std::endl;
			}
			break;
	}
	printCurrentLocation();
}

void Game::printCurrentLocation() {
	std::cout << "Current location: (" << currentX << "," << currentY << ")" << std::endl;
}

Game & Game::getGameInstance() {
	static Game game;
	return game;
}

Game::~Game() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			delete board[i][j];
			board[i][j] = NULL;
		}
	}
}
