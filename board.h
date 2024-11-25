#ifndef BOARD_H
#define BOARD_H

class board {
private:
    char grid[9];

public:
    board();
    void displayBoard() const;
    bool makeMove(int cell, char player);
    bool checkWin(char player);
    bool isDraw();
    bool cellFree(int cell) const;
    void reset();
    bool checkSwarmWin();
    void removeMark();
};

#endif
