#include "Enemy.h"
#include <iostream>



Enemy::Enemy(std::string n, int h, int a) : Character(n, h, a) {}

void Enemy::Eattack(Character* target) {
    std::cout << getName() << " attaque le Mafieu !" << std::endl;
    target->takeDamage(getAttack());
}



