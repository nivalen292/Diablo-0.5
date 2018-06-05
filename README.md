# Diablo-0.5
CS OOP-Pract Project

## Introduction

A simple yet challenging game to play. Diablo 0.5 is a console application written for a CS course assignment. Users are
given a choice of 3 characters in order to engage in fierce combat(console commands) and be victorious.

## Usage

As mentioned above all you have to do is run the executable file and you will be guided forward. Still here is what you need to know:
- The game starts with you entering a name and picking a character type(case sensitive).
- Then you are introduced to the one and only board with a fixed size of 10x10.
- You can type ``` move ``` + a direction (up, right, down, left) in order for your character to move. If there is an enemy mob on the
desired square your character will attack the mob and get into combat. You do **NOT** need to finish the fight you have the choice to flee
or attack a different mob. **You do NOT leave combat until you kill atleast one mob!**
- Mobs will always spawn on the same spot. 
- Attempting the exit the board will result in a failure.
- You win by reaching the bottom-right most corner of the board.

## Architecture

Consists of 3 main classes:
- **Entity** - abstract class for the board pieces.
- **Character** - inherits from Entity and provides additional functionality for non AI.
- **Enemy** - also inherits from Entity. Since Enemy objects have a fixed amount of functionality, this class is created for future development.

Subclasses:
- Charater-based: **Barbarian**, **Sorcerer**, **BountyHunter**
- Enemy-based: **Necromancer**, **Skeleton**, **Eretic**, **Diablo**

Utility classes:
- **Game** - a singleton class which is responsible for booting up and safely exiting the game when the player is dead or is considered a winner.
- **CharacterFactory** - a factory(pseudo) implemented in order to restrict the use of the **new** operator and to make it easier to instantiate
Character objects.

This specific architecture is chosen because both **Character** and **Enemy** have a lot of functionallity in common and thus the **Entity** class is created. Also
this allows for future updates to become easier and smoother.


### Author
Ivelin Dinev
