#include "Mafieu.h"
#include <iostream>

Mafieu::Mafieu(std::string n) : Character(n, 100, 6), xp(0), influence(0), car(0), level(1), bdg(0), money(10), pdc(0), weapon(nullptr) {}

void Mafieu::addXP(int amount) {
    xp += amount;
    addLevel(0);
}

void Mafieu::addLevel(int) {
    while (xp >= 100) {
        xp -= 100;
        level++;
        std::cout << "Niveau augmenté ! Vous êtes maintenant niveau " << level << std::endl;
    }
}

void Mafieu::subInfluence(int amount) { influence -= amount; }
void Mafieu::addInfluence(int amount) { influence += amount; }
void Mafieu::setCar(int value) { car = value; }
void Mafieu::setMoney(int value) { money = value; }

void Mafieu::setPdc(int value) { pdc = value; }

int Mafieu::getXP() const { return xp; }
int Mafieu::getLevel() const { return level; }
int Mafieu::getCar() const { return car; }
int Mafieu::getInfluence() const { return influence; }

void Mafieu::equipWeapon(Weapon* w) { weapon = w; }

void Mafieu::addMoney(int amount)
{
	std::cout << "Rumanu a gagné " << amount << " euros !" << std::endl;
	money += amount;
}

void Mafieu::subMoney(int amount)
{
    std::cout << "Rumanu a perdu " << amount << " euros !" << std::endl;
    money -= amount;
}

int Mafieu::getAttack() const { return 0; }

int Mafieu::getMoney() const
{
    return money;
}

void Mafieu::MAttack(Character* target) {
    std::cout << "Rumanu attaque " << target->getName() << " !" << std::endl;
    target->takeDamage(getAttack());
}
