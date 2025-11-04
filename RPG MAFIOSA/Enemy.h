#pragma once
#include "Character.h"

class Enemy : public Character {
public:
    Enemy(std::string n, int h, int a) : Character(n, h, a) {}
};


