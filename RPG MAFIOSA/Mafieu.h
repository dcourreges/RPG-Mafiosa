#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include "Character.h"


class Mafieu : public Character
{
public :

	void Attack() { std::cout << "Vous utilisez intimidation"; }


};

