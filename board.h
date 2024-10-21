#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
using namespace std;

class board {
public:
    board(); // Constructor
    bool makeMove(int cell, char player); // Make a move on the board
    void displayBoard() const; // Display the current state of the board
    bool checkWin(char player); // Check if a player has won
    bool isDraw(); // Check if the game is a draw
    bool cellFree(int cell) const;

    void reset(); // Reset the board

private:
    vector<char> grid; // Change from int to char to store player marks
};

#endif // BOARD_H
