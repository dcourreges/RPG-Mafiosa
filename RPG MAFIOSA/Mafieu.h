#pragma once
#include "Character.h"

class Mafieu : public Character {
private:
    int xp;
    int influence;
    int car = 0;
    int level = 0;
    int rnumber;



public:
    Mafieu(std::string n) : Character(n, 40, 6), xp(0), influence(0), level(0) {}

    void addXP(int amount);
    void addLevel(int amount);
    void addInfluence(int amount);
    void setCar(int amount);

    int getXP() const;
    int getLevel() const;
    int getCar() const;
    int dice() const;
    int getInfluence() const;
};

