#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>



class Character
{
private:
	std::string name;
	int health;
	std::vector<Character*> characters;
	characters.push_back(new Mafieu("Ange"));
	characters.push_back(new Mafieu("Francois"));


public:

	Character(const std::string& n, int h)
		: name(n), health(h) {}


	void CharaDisplay() const {

		std::cout << name << " - PV: " << health << std::endl;
	}

	void Attack() const {

		std::cout << "Vous utilisez intimidation !" << std::endl;

	}

};

