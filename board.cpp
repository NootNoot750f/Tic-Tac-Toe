#include "board.h"

#include <iostream>
using namespace std;

board::board() : grid{'1', '2', '3', '4', '5', '6', '7', '8', '9'} {}

void board::displayBoard() const {
    cout << " | " << grid[0] << " | " << grid[1] << " | " << grid[2] << " | " << endl;
    cout << "-----------" << endl;
    cout << " | " << grid[3] << " | " << grid[4] << " | " << grid[5] << " | " << endl;
    cout << "-----------" << endl;
    cout << " | " << grid[6] << " | " << grid[7] << " | " << grid[8] << " | " << endl;
}

bool board::makeMove(int cell, char player) {
    if (cellFree(cell)) {
        grid[cell - 1] = player;
        return true;
    }
    return false;
}

bool board::checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if (grid[i * 3] == player && grid[i * 3 + 1] == player && grid[i * 3 + 2] == player) {
            return true;
        }
        if (grid[i] == player && grid[i + 3] == player && grid[i + 6] == player) {
            return true;
        }
    }
    if (grid[0] == player && grid[4] == player && grid[8] == player) {
        return true;
    }
    if (grid[2] == player && grid[4] == player && grid[6] == player) {
        return true;
    }
    return false;
}

bool board::isDraw() {
    for (char cell : grid) {
        if (cell >= '1' && cell <= '9') {
            return false;
        }
    }
    return true;
}

bool board::cellFree(int cell) const {
    return (cell >= 1 && cell <= 9 && grid[cell - 1] != 'X' && grid[cell - 1] != 'O');
}

void board::reset() {
    for (int i = 0; i < 9; ++i) {
        grid[i] = '1' + i;
    }
}

bool board::checkSwarmWin() {
    return grid[0] == 'O' && grid[2] == 'O' && grid[6] == 'O' && grid[8] == 'O';
}

void board::removeMark() {
    int mark;
    cout << "Choose a mark to remove (1-9): ";
    cin >> mark;
    if (mark >= 1 && mark <= 9 && grid[mark - 1] != 'X' && grid[mark - 1] != 'O') {
        grid[mark - 1] = ' ';
    } else {
        cout << "Invalid mark or no mark to remove. Try again." << endl;
        removeMark(); // Retry if invalid input
    }
}
