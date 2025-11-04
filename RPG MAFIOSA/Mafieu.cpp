#include "Mafieu.h"

void Mafieu::addXP(int amount) { xp += amount; }
void Mafieu::addInfluence(int amount) { influence += amount; }
int Mafieu::getXP() const { return xp; }
int Mafieu::getInfluence() const { return influence; }
int Mafieu::getCar() const { return getCar; }
