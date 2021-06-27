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
	
	switch (putchar(toupper(choice))) {
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

void Player::gridPlacement(int shipSize) {
	if (shipSize == 1) {
		std::cout << "\nWhere would you like to place this ship... \n";
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
	else {
		std::cout << "\nWhere would you like to place the start of this ship: ";
	}
}

void Player::updatePlayerGrid(char column, int row) {
	int col = static_cast<int>(column - 97);
	m_shipGrid[row-1][col] = 'X';
}

/*std::string Player::getGrid() const {
	return m_shipGrid[11][11];
}*/

Player::~Player() {
}