#ifndef PLAYER_H
#define PLAYER_H
#include <array>
#include <string>

class Player{
private:
	bool m_victory{};
	short m_shipTotal{};
public:
	Player();
	std::string m_shipGrid[11][11];
	//bool hasWon(bool victoryCheck);
	//void getVictory()const;
	void playerInstructions();
	void gridPlacement(int shipSize);
	void playerShipChoice();
	void updatePlayerGrid(char column, short row);
	bool checkValidPlacements(char letter, short number, int shipSize);
	~Player();
};

#endif

