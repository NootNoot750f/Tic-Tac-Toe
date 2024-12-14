#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"

class game {
private:
    board board;
    player player1;
    player player2;

    // Add these missing variables
    int gamesPlayed;
    int player1Wins;
    int player2Wins;
    int ties;

    // Private helper functions
    void askArchetype(player& p);
    bool isValidMove(int move);
    void updateStats(char winner, bool isDraw);
    void generateReport();
    void play();
    void handleBattle();

public:
    game(); // Constructor
    void start(); // Main game loop
};

#endif
