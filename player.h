#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class player {
private:
    char letter;
    std::string archetype;
    bool usedSpecialMove;

public:
    player(char letter, std::string archetype);
    int getMove();
    void setArchetype(std::string newArchetype);
    std::string getArchetype() const;
    void useSpecialMove();
    bool canUseSpecialMove() const;
    char getLetter() const;
};

#endif
