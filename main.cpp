#include "main.h"
#include "game.h"
#include <iostream>
using namespace std;
int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "----------------------------" << endl;
    cout << "In this version of Tic-Tac-Toe, you can choose to play with different archetypes." << endl;
    cout << "Each archetype has special abilities that can change the rules of the game." << endl;

    cout << "How to Play:" << endl;
    cout << "1. Players take turns placing their marks (X or O) on the 3x3 grid." << endl;
    cout << "2. The goal is to get 3 of your marks in a row, either horizontally, vertically, or diagonally." << endl;
    cout << "3. Some archetypes, like Swarm, have additional win conditions that may require you to fill the corners." << endl;
    cout << "4. The Pyromancer archetype can destroy marks on the board once per game." << endl;

    cout << "Press Enter to start the game!" << endl;
    cin.ignore();

    game game;
    game.start();
    return 0;
}
