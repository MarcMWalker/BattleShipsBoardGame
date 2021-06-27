#include <iostream>
#include "Board.h"
#include "Player.h"
#include <Windows.h>
#include <string>
#include <array>
#include <algorithm>

void loopChanges(Player &player, Board &board) {
	for (int row{ 0 }; row < 11; ++row) {
		for (int col{ 0 }; col < 11; ++col) {
			if (player.m_shipGrid[col][row] == "X") {
				board.m_playerMarkers[col][row] = " X |";
			}
		}
	}
}

int main() {
	HWND hwnd = GetConsoleWindow();
	if (hwnd != NULL) { MoveWindow(hwnd, 0, 0, 780, 780, TRUE); }

	Board newBoard;
	newBoard.setBoard();
	newBoard.printInstructions();
	newBoard.printBoard();
	Player player1;
	player1.playerShipChoice();
	loopChanges(player1, newBoard);
	newBoard.updateBoard();
	newBoard.printBoard();
	return 0;
}
