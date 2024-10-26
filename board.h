//
// Created by nickh on 10/21/2024.
//

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
using namespace std;

class board {
public:
    board(); // Constructor
    bool makeMove(int cell, char player);
    void displayBoard() const;
    bool checkWin(char player);
    bool isDraw();
    bool cellFree(int cell) const;

    void reset();

private:
    vector<char> grid;
};

#endif // BOARD_H
