#include "game.h"
#include <iostream>
#include <string>
#include "player.h"
using namespace std;

game::game() : player1('O', "default"), player2('X', "default") {}

void game::start() {
    cout << "Welcome to Tic Tac Toe" << endl;
    char playAgain = 'y';

    while (playAgain == 'y') {
        string gameType;
        cout << "Select game type: regular or battle: ";
        cin >> gameType;

        if (gameType == "regular") {
            board.reset();
            play();
        } else if (gameType == "battle") {
            handleBattle();
        }

        cout << "Play Again? y or n: ";
        cin >> playAgain;
    }
}

void game::handleBattle() {
    askArchetype(player1);
    askArchetype(player2);

    board.reset();
    player* currentPlayer = &player1;

    while (true) {
        board.displayBoard();
        int move = currentPlayer->getMove();


        if (currentPlayer->getArchetype() == "Pyromancer" && currentPlayer->canUseSpecialMove()) {
            char useSpecialMove;
            cout << "Player " << currentPlayer->getLetter() << ", do you want to use your Pyromancer ability to destroy a mark? (y/n): ";
            cin >> useSpecialMove;
            if (useSpecialMove == 'y') {
                currentPlayer->useSpecialMove();
                board.removeMark();
            }
        }

        if (isValidMove(move)) {
            board.makeMove(move, currentPlayer->getLetter());


            if (currentPlayer->getArchetype() == "Swarm" && board.checkSwarmWin()) {
                board.displayBoard();
                cout << "Player " << currentPlayer->getLetter() << " (Swarm) wins by filling corners!" << endl;
                break;
            }

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

            currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
        } else {
            cout << "Invalid move, please enter a valid move." << endl;
        }
    }
}

void game::askArchetype(player& p) {
    string archetype;
    cout << "Player " << p.getLetter() << ", select archetype ('Swarm'/'Pyromancer'): ";
    while (true) {
        cin >> archetype;
        if (archetype == "Swarm" || archetype == "Pyromancer") {
            p.setArchetype(archetype);
            break;
        } else {
            cout << "Invalid archetype. Please choose Swarm or Pyromancer: ";
        }
    }
}

bool game::isValidMove(int move) {
    return board.cellFree(move);
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
            currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
        } else {
            cout << "Invalid move, please enter a valid move." << endl;
        }
    }
}
