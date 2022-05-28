#include "SkillGem.h"
#include "Weapon.h"

SkillGem::SkillGem() : Gem()
{
	std::cin >> skillDamage;
}

SkillGem::~SkillGem()
{
}

DamageTerms& SkillGem::Affect(DamageTerms& _terms)
{
	_terms.elementalDamage += this->elementalDamage;
	return _terms;
}
