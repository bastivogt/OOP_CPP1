#include "creature.h"

Creature::Creature(string name, int age, int height, int weight) {
    this->name = name;
    this->age = age;
    this->height = height;
    this->weight = weight;
}

int Creature::getAge() {
    return this->age;
}

int Creature::getHeight() {
    return this->height;
}

int Creature::getWeight() {
    return this->weight;
}

string Creature::getName() {
    return this->name;
}
