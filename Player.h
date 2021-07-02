#ifndef PLAYER_H
#define PLAYER_H
#include <array>
#include <string>

class Player{
private:
	bool m_victory{};
	short m_shipTotal{};
	enum class Direction{Up, Down, Right, Left, None};
public:
	Player();
	std::string m_shipGrid[11][11];
	//bool hasWon(bool victoryCheck);
	short getShipTotal()const;
	void playerInstructions();
	void gridPlacement(int shipSize);
	void playerShipChoice();
	void updatePlayerGrid(char column, short row);
	bool checkValidFirstPlacement(char letter, short number, int shipSize);
	bool checkValidSecondPlacement(char letter, short number, char previousLet, short previousNum, int shipSize);
	void printInstruction(short tilePlacementTotal)const;
	void fillInnerPositions(char letter, short number, char previousLet, short previousNum, int shipSize, Direction direction);
	void setDirection(char letter, short number, char previousLet, short previousNum, Direction &direction);
	~Player();
};

#endif

