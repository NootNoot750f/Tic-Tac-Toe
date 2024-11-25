#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"

class game {
private:
    board board;
    player player1;
    player player2;

    void askArchetype(player& p);
    bool isValidMove(int move);
    void handleBattle();

public:
    game();
    void start();
    void play();
};

#endif
