#pragma once
#include <string>

class Weapon {
protected:
    std::string name;
    int damage;

public:
    Weapon(std::string n, int d);
    virtual ~Weapon();

    int getDamage() const;
    std::string getName() const;
};

