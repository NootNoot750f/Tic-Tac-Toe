//
// Created by nickh on 10/21/2024.
//

#include "game.h"
#include <iostream>
#include <string>
using namespace std;

game::game() : player1('O'), player2('X') {}

void game::start() {
    cout << "Welcome to Tic Tac Toe" << endl;
    char playAgain = 'y';

    while (playAgain == 'y') {
        board.reset();
        play();
        cout << "Play Again? y or n: ";
        cin >> playAgain;
    }
}

void game::play() {
    player* currentPlayer = &player1;
    while (true) {
        board.displayBoard();
        int move = currentPlayer->getMove();
        if (isValidMove(move)) {
            board.makeMove(move, currentPlayer->getLetter());
            if (board.checkWin(currentPlayer->getLetter())) {
                board.displayBoard();
                cout << "Player " << currentPlayer->getLetter() << " won!" << endl;
                break;
            }
            if (board.isDraw()) {
                board.displayBoard();
                cout << "It's a tie!" << endl;
                break;
            }
            //
            currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
        } else {
            cout << "Invalid move, please enter a valid move." << endl;
        }
    }
}

bool game::isValidMove(int move) {
    return board.cellFree(move);
}
