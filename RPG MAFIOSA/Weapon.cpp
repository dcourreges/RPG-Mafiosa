#include "Weapon.h"

Weapon::Weapon(std::string n, int d) : name(n), damage(d) {}
Weapon::~Weapon() {}

int Weapon::getDamage() const { return damage; }
std::string Weapon::getName() const { return name; }
