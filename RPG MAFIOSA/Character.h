#pragma once
#include <string>

class Character {
protected:
    std::string name;
    int hp;
    int attack;

public:
    Character(std::string n, int h, int a) : name(n), hp(h), attack(a) {}
    virtual ~Character() {}

    virtual void takeDamage(int dmg);
    bool isAlive() const;
    std::string getName() const;
    int getHP() const;
    int getAttack() const;
};
