#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <cstring>

bool Game::isValidPosition(int x, int y) {
	return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE);
}

bool Game::hasEnemy(int x, int y) {
	return (board[x][y] != NULL) && isValidPosition(x, y);
}

Game::Game() : BOARD_SIZE(10), currentX(0), currentY(0), moves(0) {
	fillBoard();
}

void Game::run() {
	displayInstructions();
	chooseCharacter();
	printBoard();
	printCurrentLocation();
	while (true) {
		if (currentX == BOARD_SIZE - 1 && currentY == BOARD_SIZE - 1) {
			break;
		}
		executeCommand();
	}
	std::cout << "Congratulation, you won in " << moves << " moves!" << std::endl;
}

void Game::chooseCharacter() {
	std::cout << "Choose you name (max length 20):" << std::endl;
	char name[20] = "";
	std::cin.getline(name, 20);
	std::cout << std::endl;
	char choice[20] = ""; // limited character names
	while (strcmp(choice, "Barbarian") != 0 && strcmp(choice, "Sorcerer") != 0 && strcmp(choice, "BountyHunter") != 0) {
		std::cout << "Choose you character!" << std::endl;
		std::cout << "Type in one of the folling:" << std::endl;
		std::cout << std::endl;
		std::cout << "Barbarian" << std::endl;
		std::cout << "Sorcerer" << std::endl;
		std::cout << "BountyHunter" << std::endl;
		std::cin.getline(choice, 20);
	}
	player = factory.getCharacter(choice, name);
	board[currentX][currentY] = player;
	std::cout << std::endl;
}

void Game::displayInstructions() {
	std::cout << "Welcome to the wonderful yet fearsome game Diablo 0.5!\n" 
		<< "You will be given a choice of character.\n" 
		<< "Your goal will be to travel to the south-eastern part of the board killing everything in your way.\n"
		<< "Moving onto a square with an enemy on it will cause you and the enemy to attack each other.\n"
		<< "Commands: move + direction(left, right, up, down)"<< std::endl;
	std::cout << std::endl;
}

void Game::fight(Entity * a, Entity * b) {
}

void Game::fillBoard() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			board[i][j] = NULL;
		}
	}
	// testing purposes
	board[0][1] = new Diablo("Doom");
	board[0][2] = new Skeleton("clumsy");
	board[0][3] = new Eretic();
	board[0][4] = new Skeleton("clumsy");
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
					moves++;
					printBoard();
				}
				else {
					moves++;
					printBoard();
					player->attack(board[currentX - 1][currentY]);
					if (board[currentX - 1][currentY]->isAlive()) {
						board[currentX - 1][currentY]->attack(player);
					}
					else {
						board[currentX - 1][currentY] = NULL;
						printBoard();
					}
				}
			}
			else {
				printBoard();
				std::cout << "Invalid move, you cannot go outside the board!" << std::endl;
			}
			break;
		case 'd':
			if (isValidPosition(currentX + 1, currentY)) {
				if (!hasEnemy(currentX + 1, currentY)) {
					board[currentX + 1][currentY] = player; // move player
					board[currentX][currentY] = NULL; // remove player from previous
					currentX++;
					moves++;
					printBoard();
				}
				else {
					moves++;
					printBoard();
					player->attack(board[currentX + 1][currentY]);
					if (board[currentX + 1][currentY]->isAlive()) {
						board[currentX + 1][currentY]->attack(player);
					}
					else {
						board[currentX + 1][currentY] = NULL;
						printBoard();
					}
				}
			}
			else {
				printBoard();
				std::cout << "Invalid move, you cannot go outside the board!" << std::endl;
			}
			break;
		case 'l':
			if (isValidPosition(currentX, currentY - 1)) {
				if (!hasEnemy(currentX, currentY - 1)) {
					board[currentX][currentY - 1] = player; // move player
					board[currentX][currentY] = NULL; // remove player from previous
					currentY--;
					moves++;
					printBoard();
				}
				else {
					moves++;
					printBoard();
					player->attack(board[currentX][currentY - 1]);
					if (board[currentX][currentY - 1]->isAlive()) {
						board[currentX][currentY - 1]->attack(player);
					}
					else {
						board[currentX][currentY - 1] = NULL;
						printBoard();
					}
				}
			}
			else {
				printBoard();
				std::cout << "Invalid move, you cannot go outside the board!" << std::endl;
			}
			break;
		case 'r':
			if (isValidPosition(currentX, currentY + 1)) {
				if (!hasEnemy(currentX, currentY + 1)) {
					board[currentX][currentY + 1] = player; // move player
					board[currentX][currentY] = NULL; // remove player from previous
					currentY++;
					moves++;
					printBoard();
				}
				else {
					moves++;
					printBoard();
					player->attack(board[currentX][currentY + 1]);
					if (board[currentX][currentY + 1]->isAlive()) {
						board[currentX][currentY + 1]->attack(player);
					}
					else {
						board[currentX][currentY + 1] = NULL;
						printBoard();
					}
				}
			}
			else {
				printBoard();
				std::cout << "Invalid move, you cannot go outside the board!" << std::endl;
			}
			break;
	}
	printCurrentLocation();
}

void Game::printBoard() {
	std::system("cls");
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] == NULL) {
				std::cout << "_";
			}
			else {
				const char* className = board[i][j]->getClassName();
				if (strcmp(className, "Barbarian") == 0
					|| strcmp(className, "Sorcerer") == 0
					|| strcmp(className, "BountyHunter") == 0) {
					std::cout << "*";
				}
				else {
					std::cout << className[0];
				}
			}
			std::cout << " ";
		}
		std::cout << std::endl;
	}

}

void Game::printCurrentLocation() {
	std::cout << "Move count: " << moves << std::endl;
	std::cout << "Current location: (" << currentX << "," << currentY << ")" << std::endl;
}

Game & Game::getGameInstance() {
	static Game game;
	return game;
}

Game::~Game() {
	/*for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			delete board[i][j];
			board[i][j] = NULL;
		}
	}*/
}
