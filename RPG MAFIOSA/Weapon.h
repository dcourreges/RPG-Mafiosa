#pragma once
#include <string>

class Weapon {
protected:
    std::string name;
    int damage;

public:
    Weapon(std::string n, int d) : name(n), damage(d) {}
    virtual ~Weapon() {}

    int getDamage() const { return damage; }
    std::string getName() const { return name; }
};

