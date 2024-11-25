#include "archetype.h"

archetype::archetype(string name, string description) : name(name), description(description) {}

// Static instances
archetype swarm("Swarm", "The Swarm is a hive mind that introduces new ways to win the game. It can win using the normal rules of tic-tac-toe or by filling in all four corners of the board.");
archetype pyromancer("Pyromancer", "The Pyromancer is a powerful magic user that can destroy all of the current marks on the board. This special move can only be used once per game.");

string archetype::getName() {
    return name;
}

string archetype::getDescription() {
    return description;
}
