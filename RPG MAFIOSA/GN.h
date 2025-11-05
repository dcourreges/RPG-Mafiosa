#pragma once
#include "Enemy.h"
#include "Glock17.h"

class Gn : public Enemy {
private:
    Glock17* arme;

public:
    Gn() : Enemy("Gendarmerie Nationale", 25, 0), arme(new Glock17()) {
        attack = arme->getDamage();
    }

    ~Gn() {
        delete arme;
    }
};

