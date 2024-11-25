#ifndef ARCHETYPE_H
#define ARCHETYPE_H
#include <string>
using namespace std;

class archetype {
public:
    archetype(string name, string description);
    string getName();
    string getDescription();

private:
    string name;
    string description;
};

#endif //ARCHETYPE_H
