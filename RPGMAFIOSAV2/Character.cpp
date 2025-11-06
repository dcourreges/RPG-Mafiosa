#include "Character.h"

Character::Character(const std::string& n, int h, int a) : name(n), hp(h), dmg(a) {}
Character::~Character() {}

void Character::takeDamage(int dmg) {
    hp -= dmg;
    if (hp < 0) hp = 0;
}

bool Character::isAlive() const { return hp > 0; }
std::string Character::getName() const { return name; }
int Character::getHP() const { return hp; }

void Character::MAttack(Character* target) {
    target->takeDamage(getAttack());
}
int Character::LanceAttack() const { return 0; }
int Character::getAttack() const {


    return hp;
}