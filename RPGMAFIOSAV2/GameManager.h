#pragma once
#include "Mafieu.h"
#include "Enemy.h"
#include <vector>

class GameManager {
private:
    Mafieu mafieu;
    std::vector<Enemy*> enemies;

public:
    GameManager();
    ~GameManager();
    void CombatPm();
    void CombatGn();
    void Init();
  /*  bool Rejouer();*/
    void EndingCheck(int end);
    void Credit();
    void Quest(int quest);
	void Menu();
	void Chargement();
};



