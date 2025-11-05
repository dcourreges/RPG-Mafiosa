#pragma once
#include "Character.h"
#include "Weapon.h"

class Mafieu : public Character {
private:
    int xp;
    int influence;
    int car;
    int level;
    Weapon* weapon;

public:
    Mafieu(std::string n);

    void addXP(int amount);
    void addLevel(int amount);
    void addInfluence(int amount);
    void setCar(int value);
    void equipWeapon(Weapon* w);

    int getXP() const;
    int getLevel() const;
    int getCar() const;
    int getInfluence() const;
    int getAttack() const override;

    void attack(Character* target) override;
};


