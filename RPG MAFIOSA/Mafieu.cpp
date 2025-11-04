#include "Mafieu.h"

void Mafieu::addXP(int amount) { xp += amount; }
void Mafieu::addLevel(int amount){
	while (xp >= 100)
	{
		xp = xp - 100;
		level++;
		return;
	}


}
void Mafieu::addInfluence(int amount) { influence += amount; }
void Mafieu::setCar(int amount) { car = 1; }


int Mafieu::getLevel() const { return level; }
int Mafieu::getXP() const { return xp; }
int Mafieu::getInfluence() const { return influence; }
int Mafieu::getCar() const { return car;}
int Mafieu::dice() const { return rnumber;}


//int GenerateRandomNumber(int min, int max)
//{
//	return min + rand() % (max + 1 - min);
//}
