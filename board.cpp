#include "board.h"
using namespace std;

// Constructor
board::board() : grid{'1', '2', '3', '4', '5', '6', '7', '8', '9'} {}

// Display the current state of the board
void board::displayBoard() const {
    cout << " | " << grid[0] << " | " << grid[1] << " | " << grid[2] << " | " << endl;
    cout << "-----------" << endl;
    cout << " | " << grid[3] << " | " << grid[4] << " | " << grid[5] << " | " << endl;
    cout << "-----------" << endl;
    cout << " | " << grid[6] << " | " << grid[7] << " | " << grid[8] << " | " << endl; // Fix indexing
}

// Make a move on the board
bool board::makeMove(int cell, char player) {
    if (cellFree(cell)) {
        grid[cell - 1] = player; // Update the cell with the player's mark
        return true;
    }
    return false;
}

// Check if a player has won
bool board::checkWin(char player) {
    // Check rows and columns for a win
    for (int i = 0; i < 3; i++) {
        if (grid[i * 3] == player && grid[i * 3 + 1] == player && grid[i * 3 + 2] == player) {
            return true; // Row win
        }
        if (grid[i] == player && grid[i + 3] == player && grid[i + 6] == player) {
            return true; // Column win
        }
    }
    // Check diagonals for a win
    if (grid[0] == player && grid[4] == player && grid[8] == player) {
        return true; // Diagonal win
    }
    if (grid[2] == player && grid[4] == player && grid[6] == player) {
        return true; // Diagonal win
    }
    return false;
}

// Check if the game is a draw
bool board::isDraw() {
    for (char cell : grid) {
        if (cell >= '1' && cell <= '9') {
            return false; // There's still an available cell
        }
    }
    return true; // No available cells, it's a draw
}

// Check if a cell is free
bool board::cellFree(int cell) const {
    return (cell >= 1 && cell <= 9 && grid[cell - 1] >= '1' && grid[cell - 1] <= '9');
}

// Reset the board to its initial state
void board::reset() {
    for (int i = 0; i < 9; ++i) {
        grid[i] = '1' + i; // Reassign cells to default values ('1' to '9')
    }
}
