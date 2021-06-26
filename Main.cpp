#include <iostream>
#include "Board.h"
#include "Player.h"
#include <Windows.h>
#include <string>
#include <array>
#include <algorithm>

int main() {
	HWND hwnd = GetConsoleWindow();
	if (hwnd != NULL) { MoveWindow(hwnd, 0, 0, 780, 780, TRUE); }

	Board newBoard;
	newBoard.setBoard();
	newBoard.printInstructions();
	newBoard.printBoard();
	Player player1;
	player1.playerShipChoice();
	if (player1.m_shipGrid[0][0] == "X") {
		newBoard.m_playerMarkers[0][0] = " X |";
	}
	newBoard.updateBoard();
	newBoard.printBoard();
	return 0;
}