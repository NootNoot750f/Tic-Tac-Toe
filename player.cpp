#include "player.h"
#include <iostream>
#include <string>
using namespace std;

player::player(char letter, string archetype) : letter(letter), archetype(archetype), usedSpecialMove(false) {}

int player::getMove() {
    int move;
    cout << "Player " << letter << ", enter your move (1-9): ";
    cin >> move;
    return move;
}

void player::setArchetype(string newArchetype) {
    archetype = newArchetype;
}

string player::getArchetype() const {
    return archetype;
}

void player::useSpecialMove() {
    if (!usedSpecialMove) {
        usedSpecialMove = true;
    }
}

bool player::canUseSpecialMove() const {
    return !usedSpecialMove;
}

char player::getLetter() const {
    return letter;
}
