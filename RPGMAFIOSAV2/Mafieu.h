#pragma once
#include "Character.h"
#include "Weapon.h"

class Mafieu : public Character {
private:
    int xp;
    int influence;
    int car;
    int level;
    int bdg;
    Weapon* weapon;

public:
    Mafieu(std::string n);

    void addXP(int amount);
    void addLevel(int amount);
    void addInfluence(int amount);
    void subInfluence(int amount);
    void setCar(int value);
    void equipWeapon(Weapon* w);

    int getXP() const;
    int getLevel() const;
    int getCar() const;
    int getInfluence() const;
    int getAttack() const override;
	int getBdg() const { return bdg; }

    void setHP(int value) { hp = value; }
    void setInflu(int value) { influence = value; }
    void setLvl(int value) { level = value; }
    void setBdg(int value) { bdg = value; }
    void MAttack(Character* target);
};



