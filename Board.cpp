#include "Board.h"
#include <iostream>

Board::Board() : m_board{}, m_playerMarkers{}, m_filled{} {
}

void Board::setBoard() {
	//Initial setup of board
	std::string space{ "  |" };
	std::string newString{};
	m_board[0][0] = "  |", m_board[1][0] = "1 |", m_board[2][0] = "2 |", m_board[3][0] = "3 |", 
	m_board[4][0] = "4 |", m_board[5][0] = "5 |", m_board[6][0] = "6 |", m_board[7][0] = "7 |", 
	m_board[8][0] = "8 |", m_board[9][0] = "9 |", m_board[10][0] = "10|";

	for (int i{ 1 }; i < 12; ++i) {
		newString = (m_letters.at(i - 1) + space);
		m_board[0][i] = newString;
	}
	for (int col{ 1 }; col < 11; ++col) {
		for (int row{ 1 }; row < 11; ++row) {
			m_board[col][row] = "   |";
		}
	}
}

void Board::updateBoard() {
	for (int col{ 0 }; col < 11; ++col) {
		for (int row{ 0 }; row < 11; ++row) {
			if (m_playerMarkers[col][row] == " X |") {
				m_board[col+1][row+1] = " X |";
			}
		}
	}
}

void Board::printBoard() const {
	std::cout << "Map:\n";
	std::cout << "-------------------------------------------------\n\n";
	for (int i{ 0 }; i < 11; ++i) {
		for (int j{ 1 }; j < 12; ++j) {
			std::cout << m_board[i][j - 1];
		}
		std::cout << "\n+++++++++++++++++++++++++++++++++++++++++++\n";
	}
}

void Board::printInstructions() const{
	std::cout << "-------------------------------------------------\n";
	std::cout << "Instructions for Battleships:\n";
	std::cout << "-------------------------------------------------\n";
	std::cout << "1: Arrange your ship fleet on the grid.\n";
	std::cout << "2: Take turns firing at the other player.\n";
	std::cout << "3: Player that sinks all their opponent ships wins!\n";
	std::cout << "-------------------------------------------------\n";
	std::cout << "Fleet selection:\n";
	std::cout << "1x Aircraft Carrier (5 tiles)\n";
	std::cout << "1x Battleship (4 tiles)\n";
	std::cout << "1x Cruiser (3 tiles)\n";
	std::cout << "2x Destroyer (2 tiles)\n";
	std::cout << "2x Submarine (1 tile)\n";
	std::cout << "-------------------------------------------------\n";
}

Board::~Board() {
}