//
// Created by nickh on 10/21/2024.
//

#include "player.h"
#include <iostream>
#include <limits>
#include <string>
using namespace std;

player :: player(char letter) : letter(letter){}

char player :: getLetter() {
    return letter;

}

int player :: getMove() {
    int move;
    cout  << "It is " << letter << "'s turn" << endl;
    while (true) {
        cin >> move;

        if(cin.fail() || move < 1 || move > 9) {
            cout << "Illegal move. Please enter a number 1-9" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max());
        }else {
            break;

        }

    }

    return move;
//No return statement?
}