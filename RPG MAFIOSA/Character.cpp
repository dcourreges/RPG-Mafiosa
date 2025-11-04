#include "Character.h"

void Character::takeDamage(int dmg) {
    hp -= dmg;
    if (hp < 0) hp = 0;
}

bool Character::isAlive() const { return hp > 0; }
std::string Character::getName() const { return name; }
int Character::getHP() const { return hp; }
int Character::getAttack() const { return attack; }