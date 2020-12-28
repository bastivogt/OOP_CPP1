#include <string>

using namespace std;

#ifndef CREATURE_H
#define CREATURE_H


class Creature {
private:
    int age;
    int height;
    int weight;
    string name;

public:
    int getAge();
    int getHeight();
    int getWeight();
    string getName();
    Creature(string name, int age, int height, int weight);
};

#endif // CREATURE_H
