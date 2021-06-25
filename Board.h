#ifndef BOARD_H
#define BOARD_H
#include <array>
#include <string>
#include "Player.h"

class Board{
private:
	std::string m_board[13][13];
	bool m_filled[11][11];
	char m_boardMarkers[11][11];
	std::string m_letters{"ABCDEFGHIJ "};
public:
	void setBoard();
	//void setMarkers(std::string markers[10][10]);
	void updateBoard(std::string playerMarkers[10][10]);
	void printBoard();
	void printInstructions();

	Board();
	~Board();
};
#endif

//board gets setup
//print board
//board recieves player & opposite player/AI ship locations
//board checks markers on player shots that hit or miss
//update view of board