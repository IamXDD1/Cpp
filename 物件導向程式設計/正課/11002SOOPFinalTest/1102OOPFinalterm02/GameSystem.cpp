#include "GameSystem.h"
#include <sstream>

GameSystem::GameSystem()
{
	//	initialize weapon
	weapon = new Weapon();
	//	initialize gems
	size_t gemsSize;
	std::cin >> gemsSize;
	for (size_t g = 0; g < gemsSize; g++)
	{
		std::string gemType;
		std::cin >> gemType;
		Gem* newGem = NULL;
		if (gemType == "SkillGem")
		{
			newGem = new SkillGem();
		}
		else if (gemType == "SupportGem")
		{
			newGem = new SupportGem();
		}
		gems[newGem->GetName()] = newGem;
	}
}

GameSystem::~GameSystem()
{
	delete weapon;
	for (const auto& gem : gems)
	{
		delete gem.second;
	}
}

void GameSystem::StartGame()
{
	std::stringstream outputBuffer;

	//	Game loop. Handle user inputs until EOF is met
	std::string userInput;
	while (std::cin >> userInput)
	{
		if (userInput == "MOVE")
		{
			std::string targetGemName;
			char targetSocket;
			std::cin >> targetGemName >> targetSocket;

			if (targetSocket == '-')
				weapon->EquipGem(-1, gems[targetGemName]);
			else
				weapon->EquipGem(targetSocket - 'A', gems[targetGemName]);
		}
		else if (userInput == "CAST")
		{
			std::string targetGemName;
			std::cin >> targetGemName;
			outputBuffer << "[" << targetGemName << "] ";
			try
			{
				outputBuffer << weapon->CastSkill(targetGemName) << std::endl;
			}
			catch (std::exception& e)
			{
				outputBuffer << e.what() << std::endl;
			}
		}
	}

	//	print all stuff when the EOF is met
	std::cout << outputBuffer.str();
}
