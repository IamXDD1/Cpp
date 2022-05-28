#pragma once
#include "Gem.h"

class SupportGem : public Gem
{
public:
	SupportGem();
	~SupportGem();
	DamageTerms& Affect(DamageTerms& _terms);

private:
	int bonusDamage;
};
