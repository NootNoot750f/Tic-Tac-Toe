//
// Created by nickh on 10/21/2024.
//

#ifndef GAME_H
#define GAME_H
#include "player.h"
#include "board.h"

#include <iostream>
#include <string>
using namespace std;


class game {
public:
    game();
    void start();

private:
    board board;
    player player1;
    player player2;
    void play();
    bool isValidMove(int move);
    void controlEnd();
};



#endif //GAME_H
