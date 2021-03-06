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
		m_shipTotal--;
		break;
	case 'S':
		gridPlacement(1);
		m_shipTotal--;
		break;
	default:
		std::cout << "Incorrect input, try again\n";
		break;
	}
	//std::cin.ignore(INT_MAX, '\n');
	//std::cin.clear();
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
		short tilePlaced{ 0 };
		short firstTileCopyNum{};
		char firstTileCopyLetter{};
		Direction shipDirection{ Direction::None };
		while (tilePlaced < 2) {
			printInstruction(tilePlaced);
			bool letCorrect{ false };
			while (letCorrect != true) {
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
					short num{};
					letCorrect = true;
					while (numCorrect != true && letCorrect == true) {
						std::cout << "Number: ";
						std::cin >> num;
						std::cin.ignore(INT_MAX, '\n');
						std::cin.clear();

						if (num < 1 || num > 10) {
							std::cout << "**Invalid number, must be a number between 1-10**\n";
						}

						else if (tilePlaced == 0) {
							if (checkValidFirstPlacement(letter, num, shipSize) == true) {
								updatePlayerGrid(letter, num);
								numCorrect = true;
								firstTileCopyLetter = toupper(letter);
								firstTileCopyNum = num;
								tilePlaced++;
							}
							else {
								std::cout << "The ship will not be able to fit here";
							}
						}
						//create new funtion to check possible allowed placements
						else if (tilePlaced == 1) {
							if (checkValidSecondPlacement(letter, num, firstTileCopyLetter, firstTileCopyNum, shipSize) == true) {
								setDirection(letter, num, firstTileCopyLetter, firstTileCopyNum, shipDirection);
								updatePlayerGrid(letter, num);
								numCorrect = true;
								letCorrect = true;
								fillInnerPositions(letter, num, firstTileCopyLetter, firstTileCopyNum,shipSize, shipDirection);
								tilePlaced++;
							}
							else {
								std::cout << "Not allowed to be placed here, ship must be placed in a straight line and be " << shipSize << " sections long...\n";
								numCorrect = false;
								letCorrect = false;
							}
						}
					}
				}
			}
		}
	}
}

bool Player::checkValidFirstPlacement(char letter, short number, int shipSize) {
	int col = static_cast<int>(letter - 64);
	int check{ col - shipSize };
	short checkNumber{ number };
	
	bool freeSpaceUp{true};
	bool freeSpaceDown{true};
	bool freeSpaceLeft{true};
	bool freeSpaceRight{true};

	//need to keep working on this for game logic checks
	//std::cout << m_shipGrid[number - 1][col - 1];
	//check left side
	//std::cout << col - shipSize;
	if ((col - shipSize) > 0) {
		if (m_shipGrid[number-1][col] != "X") {
			for (int i{ shipSize }; i > 0; i--) {
				if (m_shipGrid[number-1][i] == "X") {
					freeSpaceLeft = false;
					break;
				}
			}
		}
		else {
			freeSpaceLeft = false;
		}
	}
	else {
		freeSpaceLeft = false;
	}

	//std::cout << m_shipGrid[number - 1][col+1];
	//check right side
	//std::cout << col + (shipSize-2);
	if ((col + (shipSize-2)) < 11) {
		if (m_shipGrid[number - 1][col] != "X") {
			for (int i{ col }; i < shipSize; i++) {
				if (m_shipGrid[number - 1][i] == "X") {
					freeSpaceRight = false;
					break;
				}
			}
		}
		else {
			freeSpaceRight = false;
		}
	}
	else {
		freeSpaceRight = false;
	}

	//check up
	if (number - shipSize > 0) {
		if (m_shipGrid[number - shipSize][col-1] != "X") {
			for (int i{ shipSize }; i > shipSize; i--) {
				if (m_shipGrid[number-1][i] == "X") {
					freeSpaceUp = false;
					break;
				}
			}
		}
	}
	else {
		freeSpaceUp = false;
	}

	//check down
	if (number - shipSize < 11) {
		if (m_shipGrid[number - shipSize][col-1] != "X") {
			for (int i{ 0 }; i < shipSize; i++) {
				if (m_shipGrid[number][i] == "X") {
					freeSpaceDown = false;
					break;
				}
			}
		}
	}
	else {
		freeSpaceDown = false;
	}

	if (freeSpaceUp == false && freeSpaceDown == false && freeSpaceLeft == false && freeSpaceRight == false) {
		return false;
	}
	else {
		return true;
	}
}

bool Player::checkValidSecondPlacement(char letter, short number, char previousLet, short previousNum, int shipSize) {
	//bit messy atm, but works currently with left and right limits
	int test{ previousLet - (letter-1) };
	int test2{ test = -test };
	int test3{ previousNum - (number + -1) };
	int test4{ number - previousNum };

	if ((test) == -shipSize) {
		std::cout << "Ship size correct\n";
		return true;
	}

	else if ((test2) == shipSize) {
		std::cout << "Ship size correct\n";
		return true;
	}
	else if ((test-=2) == -shipSize) {
		std::cout << "Ship size correct\n";
		return true;
	}
	else if ((test2 += 2) == shipSize) {
		std::cout << "Ship size correct\n";
		return true;
	}
	else if ((test3 += 1) == shipSize) {
		std::cout << "Ship size correct\n";
		return true;
	}
	else if ((test3 -= 1) == -shipSize) {
		std::cout << "Ship size correct\n";
		return true;
	}
	else if ((test4 += 1) == shipSize) {
		std::cout << "Ship size correct\n";
		return true;
	}
	else if ((test4 -= 1) == -shipSize) {
		std::cout << "Ship size correct\n";
		return true;
	}

	else {
		std::cout << "Incorrect ship size...\n";
		return false;
	}
	
	if (letter == previousLet || number == previousNum) {
		return true;
	}
	else {
		return false;
	}

}

void Player::updatePlayerGrid(char column, short row) {
	int col = static_cast<int>(column - 65);
	m_shipGrid[row-1][col] = 'X';
}

void Player::fillInnerPositions(char letter, short number, char previousLet, short previousNum, int shipSize, Direction direction) {
	int col = static_cast<int>(previousLet - 65);
	if (direction == Direction::Right) {
		for (int i{ 1 }; i < shipSize; ++i) {
			m_shipGrid[previousNum-1][col+i] = 'X';
		}
	}
	else if (direction == Direction::Left) {
		for (int i{ 1 }; i < shipSize; ++i) {
			m_shipGrid[previousNum - 1][col - i] = 'X';
		}
	}
	else if (direction == Direction::Up) {
		for (int i{ 1 }; i < shipSize; ++i) {
			m_shipGrid[(previousNum - i)][col] = 'X';
		}
	}
	else if (direction == Direction::Down) {
		for (int i{ 0 }; i < shipSize-1; ++i) {
			m_shipGrid[(previousNum + i)][col] = 'X';
		}
	}
}

void Player::setDirection(char letter, short number, char previousLet, short previousNum, Direction& direction){
	if (previousLet > letter) {
		direction = Direction::Left;
	}
	else if (previousLet < letter) {
		direction = Direction::Right;
	}
	else if (previousNum > number) {
		direction = Direction::Up;
	}
	else if (previousNum < number) {
		direction = Direction::Down;
	}
}


void Player::printInstruction(short tilePlacementTotal) const {
	if (tilePlacementTotal == 0) {
		std::cout << "Where would you like to place the First ship marker...\n";
	}
	else if (tilePlacementTotal == 1) {
		std::cout << "Where would you like to place the Second ship marker...\n";
	}
}

short Player::getShipTotal()const {
	return m_shipTotal;
}

Player::~Player() {
}