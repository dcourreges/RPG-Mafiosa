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
    void Init();
    void pve(Enemy* ennemi);
};


