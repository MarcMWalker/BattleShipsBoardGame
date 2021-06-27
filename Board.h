#ifndef BOARD_H
#define BOARD_H
#include <array>
#include <string>
#include "Player.h"

class Board{
private:
	std::string m_board[11][11];
	bool m_filled[11][11];
	std::string m_letters{"ABCDEFGHIJ "};
public:
	std::string m_playerMarkers[11][11];
	void setBoard();
	void updateBoard();
	void printBoard()const;
	void printInstructions()const;
	Board();
	~Board();
};
#endif

//board gets setup
//print board
//board recieves player & opposite player/AI ship locations
//board checks markers on player shots that hit or miss
//update view of board