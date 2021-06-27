#include "Player.h"
#include <iostream>
#include <stdio.h>
#include <ctype.h>

Player::Player() :m_victory{ false }, m_shipTotal{ 7 }, m_shipGrid{} {
}

void Player::playerInstructions() {
	std::cout << "\n--------------------------------------------------\n";
	std::cout << "--------------------------------------------------\n";
	std::cout << "--------------------------------------------------\n";
	std::cout << "Pick a ship type to place on the grid: \n";
	std::cout << "--------------------------------------------------\n";
	std::cout << "Aircraft Carrier = A\n";
	std::cout << "Battleship = B\n";
	std::cout << "Cruiser = C\n";
	std::cout << "Destroyer = D\n";
	std::cout << "Submarine = S\n";
}

void Player::playerShipChoice() {
	playerInstructions();
	std::cout << "Ship choice: ";
	char choice{};
	std::cin >> choice;
	
	switch (toupper(choice)) {
	case 'A':
		gridPlacement(5);
		break;
	case 'S':
		gridPlacement(1);
		break;
	default:
		std::cout << "Incorrect input, try again\n";
		break;
	}
}

//need to add more logic here to avoid chance to go beyond bounds and that all player placements + size will not result in missing ships
void Player::gridPlacement(int shipSize) {
	if (shipSize == 1) {
		std::cout << "\nWhere would you like to place this ship... \n";
		
		bool correct{false};
		while (correct != true) {
			std::cout << "Letter: ";
			char letter{};
			std::cin >> letter;
			letter = toupper(letter);
			std::cin.ignore(INT_MAX, '\n');
			std::cin.clear();

			if (letter < 65 || letter > 74) {
				std::cout << "**Invalid letter, must be a letter between A to J**\n";
			}
			else {
				bool numCorrect{false};
				while (numCorrect != true){
					short num{};
					std::cout << "Number: ";
					std::cin >> num;
					if (num < 1 || num > 10) {
						std::cout << "**Invalid number, must be a number between 1-10**\n";
					}
					else {
						updatePlayerGrid(letter, num);
						numCorrect = true;
					}
				}
				correct = true;
			}
		}
	}

	else {
		short tilePlaced{ 1 };
		std::cout << "\nWhere would you like to place the start of this ship: ";
		while (tilePlaced < 2) {
			std::cout << "Letter: ";
			char letter{};
			std::cin >> letter;
			std::cin.ignore(INT_MAX, '\n');
			std::cin.clear();
			short num{};
			std::cout << "Number: ";
			std::cin >> num;
			updatePlayerGrid(letter, num);
		}
	}
}

void Player::updatePlayerGrid(char column, int row) {
	int col = static_cast<int>(column - 65);
	m_shipGrid[row-1][col] = 'X';
}

Player::~Player() {
}