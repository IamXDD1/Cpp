#include "HotDogStand.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>

int HotDogStand::totalSellAmount = 0;

HotDogStand::HotDogStand()
{
	char temp[1] = { ' ' };
	this->standId = temp;
	this->hotDogSellAmount = 0;
}

HotDogStand::HotDogStand(const char * id)
{
	standId = new char[strlen(id)];
	strcpy(standId, id);
	this->hotDogSellAmount = 0;
}

HotDogStand::HotDogStand(const char * id, int amount)
{
	standId = new char[strlen(id)];
	strcpy(standId, id);
	this->hotDogSellAmount = amount;
	this->totalSellAmount += amount;
}


HotDogStand::~HotDogStand()
{
}

void HotDogStand::justSold()
{
	this->hotDogSellAmount++;
	this->totalSellAmount++;
}

void HotDogStand::print()
{
	std::cout << this->standId << ' ' << this->hotDogSellAmount << '\n';
}

int HotDogStand::thisStandSoldAmount()
{
	return this->hotDogSellAmount;
}

int HotDogStand::allStandSoldAmount()
{
	return totalSellAmount;
}
