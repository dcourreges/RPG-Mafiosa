#pragma once
#include "Character.h"

class Mafieu : public Character {
private:
    int xp;
    int influence;

public:
    Mafieu(std::string n) : Character(n, 40, 6), xp(0), influence(0) {}

    void addXP(int amount);
    void addInfluence(int amount);

    int getXP() const;
    int getInfluence() const;
};

