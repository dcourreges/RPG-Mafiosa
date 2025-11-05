#pragma once
#include <string>

class Character {
protected:
    std::string name;
    int hp;
    int attack;

public:
    Character(const std::string& n, int h, int a);
    virtual ~Character();

    virtual void takeDamage(int dmg);

    virtual void attack(Character* target);
    virtual int getAttack() const;

    bool isAlive() const;
    std::string getName() const;
    int getHP() const;
};