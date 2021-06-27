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
	
	//add more ships later when check completed
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
					std::cin.ignore(INT_MAX, '\n');
					std::cin.clear();
					if (num < 1 || num > 10) {
						std::cout << "**Invalid number, must be a number between 1-10**\n";
					}

					//Check to see if spot already filled by a ship part
					/*
					int col = static_cast<int>(letter - 65);
					if (m_shipGrid[num - 1][col] == "X") {
						std::cout << "**This spot is already taken**\n";
					}*/

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
		std::cout << "\nWhere would you like to place the start of this ship: \n";
		while (tilePlaced < 2) {
			
			bool correct{ false };
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
					bool numCorrect{ false };
					while (numCorrect != true) {
						short num{};
						std::cout << "Number: ";
						std::cin >> num;
						std::cin.ignore(INT_MAX, '\n');
						std::cin.clear();

						if (num < 1 || num > 10) {
							std::cout << "**Invalid number, must be a number between 1-10**\n";
						}

						else if (tilePlaced == 1) {
							if (checkValidPlacements(letter, num, shipSize) == true) {
								updatePlayerGrid(letter, num);
								numCorrect = true;
							}
							else {
								std::cout << "The ship will not be able to fit here";
							}
						}
						//create new funtion to check possible allowed placements
						else if (tilePlaced == 2) {
							if (checkValidPlacements(letter, num, shipSize) == true) {
								updatePlayerGrid(letter, num);
								numCorrect = true;
							}
							else {
								std::cout << "The ship will not be able to fit here";
							}
							//fill up tiles to the second tile and update grid after
							correct = true;
						}
					}
					tilePlaced++;
				}
			}
		}
	}
}

bool Player::checkValidPlacements(char letter, short number, int shipSize) {
	int col = static_cast<int>(letter - 65);
	int check{ col - shipSize };

	//Sort of works left and right checks in limited capacity, but needs much more code additions

	//check up,down,right,left directions. if ok then a move can be made
	//works correctly for left side <---
	if ((col - shipSize) > 0 && m_shipGrid[number-1][col] != "X") {
		for (int i{ shipSize }; i > 0; --i) {
			if (m_shipGrid[i][col] == "X") {
				return false;
			}
		}
	}
	//check right side
	if ((col + shipSize) < 10 && m_shipGrid[number - 1][col] != "X") {
		for (int i{ 0 }; i < shipSize; ++i) {
			if (m_shipGrid[i][col] == "X") {
				return false;
			}
		}
	}
	return true;
}

void Player::updatePlayerGrid(char column, short row) {
	int col = static_cast<int>(column - 65);
	m_shipGrid[row-1][col] = 'X';
}

Player::~Player() {
}