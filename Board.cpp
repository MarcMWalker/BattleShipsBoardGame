#include "Board.h"
#include <iostream>

Board::Board() : m_board{}, m_boardMarkers{}, m_filled{} {
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
void Board::printBoard() {
	for (int i{ 0 }; i < 11; ++i) {
		for (int j{ 1 }; j < 12; ++j) {
			std::cout << m_board[i][j - 1];
		}
		std::cout << "\n+++++++++++++++++++++++++++++++++++++++++++\n";
	}
}
Board::~Board() {
}