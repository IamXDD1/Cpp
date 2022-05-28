#include "SupportGem.h"
#include "Weapon.h"

SupportGem::SupportGem() : Gem()
{
	std::cin >> bonusDamage;
}

SupportGem::~SupportGem()
{
}

DamageTerms& SupportGem::Affect(DamageTerms& _terms)
{
	_terms.elementalDamage += this->elementalDamage;
	_terms.bonusDamage += this->bonusDamage;
	return _terms;
}
