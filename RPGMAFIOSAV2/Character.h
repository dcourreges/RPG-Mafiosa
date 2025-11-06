#pragma once
#include <string>



class Character {
protected:
    std::string name;
    int hp;
    int attack;
    int dmg;

public:
    Character(const std::string& n, int h, int a);
    virtual ~Character();

    virtual void takeDamage(int dmg);

    virtual void MAttack(Character* target);
    virtual int getAttack() const;

    bool isAlive() const;
    std::string getName() const;
    int getHP() const;
    void MAttack(Character* target) const;
    int LanceAttack() const;
};
