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
	int money;
    int pdc;
    int possession;
    Weapon* weapon;

public:
    Mafieu(std::string n);

    void addXP(int amount);
    void addLevel(int amount);
    void addInfluence(int amount);
    void subInfluence(int amount);
    void setCar(int value);
    void setMoney(int value);
    void setPdc(int value);
    void equipWeapon(Weapon* w);

    void addMoney(int amount);
    void subMoney(int amount);

    int getXP() const;
    int getLevel() const;
    int getCar() const;
    int getInfluence() const;
    int getAttack() const override;
	int getBdg() const { return bdg; }
    int getMoney() const;
    int getPdc() const { return pdc; }



    void setHP(int value) { hp = value; }
    void setInflu(int value) { influence = value; }
    void setLvl(int value) { level = value; }
    void setBdg(int value) { bdg = value; }
    void MAttack(Character* target);
	void addPdc(int amount) { pdc += amount; }
    void subPdc(int amount) { pdc -= amount; }

    void ResetStats() {
        hp = 100;
        xp = 0;
        influence = 0;
        car = 0;
        level = 1;
        bdg = 0;
    }


    int getPossession() const;
	void setPossession(int value) { possession = value; }


};



