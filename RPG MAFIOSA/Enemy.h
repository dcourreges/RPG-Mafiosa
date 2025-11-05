#pragma once
#include "Character.h"

class Enemy : public Character {
public:
    Enemy(std::string n, int h, int a);
    void attack(Character* target) override;
};


