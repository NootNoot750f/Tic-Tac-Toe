//
// Created by nickh on 10/21/2024.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
using namespace std;

class player {
public:
    player(char letter);
    char getLetter();
    int getMove();
private:
    char letter;
};



#endif //PLAYER_H
