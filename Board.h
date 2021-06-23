#ifndef BOARD_H
#define BOARD_H
#include <array>
#include <string>

class Board{
private:
	std::string m_board[13][13];
	bool m_filled[11][11];
	char m_boardMarkers[11][11];
	std::string m_letters{"ABCDEFGHIJ "};
public:
	void setBoard();
	void setMarkers(std::string markers[11][11]);
	void updateBoard(std::string theBoard[11][11], char markers[11][11]);
	void printBoard();

	Board();
	~Board();
};
#endif

//board gets setup
//print board
//board recieves opposite players ship locations
//board checks markers on player shots that hit or miss
//update view of board