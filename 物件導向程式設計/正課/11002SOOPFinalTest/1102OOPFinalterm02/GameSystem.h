#pragma once
#include <iostream>
#include <map>
#include "Weapon.h"
#include "Gem.h"
#include "SkillGem.h"
#include "SupportGem.h"

//	GameSystem Initialize a weapon and gems.
//	It also handle player's inputs and the game loop.
class GameSystem
{
public:
	GameSystem();
	~GameSystem();
	void StartGame();
	GameSystem(const GameSystem&) = delete;
	GameSystem& operator=(const GameSystem&) = delete;
private:
	Weapon* weapon;
	std::map<std::string, Gem*> gems;
};

