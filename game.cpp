#include "game.h"
#include <iostream>
#include <string>
#include <fstream>
#include "player.h"
using namespace std;

game::game() : player1('O', "default"), player2('X', "default"), gamesPlayed(0), player1Wins(0), player2Wins(0), ties(0) {}

void game::start() {
    cout << "Welcome to Tic Tac Toe!" << endl;
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
        } else {
            cout << "Invalid game type selected. Please choose 'regular' or 'battle'." << endl;
            continue;
        }


        cout << "Play Again? (y or n): ";
        cin >> playAgain;
        while (playAgain != 'y' && playAgain != 'n') {
            cout << "Invalid choice. Please enter 'y' to play again or 'n' to quit: ";
            cin >> playAgain;
        }
    }

    generateReport();
}

void game::handleBattle() {
    askArchetype(player1);
    askArchetype(player2);

    board.reset();
    player* currentPlayer = &player1;

    while (true) {
        board.displayBoard();
        int move;

        cout << "Player " << currentPlayer->getLetter() << ", enter your move (1-9): ";
        while (true) {
            cin >> move;
            if (cin.fail() || move < 1 || move > 9) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter a number between 1 and 9: ";
            } else {
                break;
            }
        }

        if (isValidMove(move)) {
            board.makeMove(move, currentPlayer->getLetter());
            if (board.checkWin(currentPlayer->getLetter())) {
                board.displayBoard();
                cout << "Player " << currentPlayer->getLetter() << " won!" << endl;
                updateStats(currentPlayer->getLetter(), false);
                break;
            }
            if (board.isDraw()) {
                board.displayBoard();
                cout << "It's a tie!" << endl;
                updateStats(currentPlayer->getLetter(), true);
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
        int move;

        cout << "Player " << currentPlayer->getLetter() << ", enter your move (1-9): ";
        while (true) {
            cin >> move;
            if (cin.fail() || move < 1 || move > 9) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter a number between 1 and 9: ";
            } else {
                break;

            }
        }

        if (isValidMove(move)) {
            board.makeMove(move, currentPlayer->getLetter());
            if (board.checkWin(currentPlayer->getLetter())) {
                board.displayBoard();
                cout << "Player " << currentPlayer->getLetter() << " won!" << endl;
                updateStats(currentPlayer->getLetter(), false);
                break;
            }
            if (board.isDraw()) {
                board.displayBoard();
                cout << "It's a tie!" << endl;
                updateStats(currentPlayer->getLetter(), true);
                break;
            }

            currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
        } else {
            cout << "Invalid move, please enter a valid move." << endl;
        }
    }
}

void game::updateStats(char winner, bool isDraw) {
    gamesPlayed++;
    if (isDraw) {
        ties++;
    } else if (winner == player1.getLetter()) {
        player1Wins++;
    } else if (winner == player2.getLetter()) {
        player2Wins++;
    }
}

void game::generateReport() {
    ofstream report("game_report.txt");
    if (report.is_open()) {
        report << "Tic-Tac-Toe Game Report\n";
        report << "------------------------\n";
        report << "Games Played: " << gamesPlayed << "\n";
        report << "Player 1 Wins: " << player1Wins << "\n";
        report << "Player 2 Wins: " << player2Wins << "\n";
        report << "Ties: " << ties << "\n";
        report.close();
        cout << "Game report generated: game_report.txt" << endl;
    } else {
        cout << "Failed to create game report." << endl;
    }
}
