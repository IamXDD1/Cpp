#pragma once
#include <string>
#include <set>
#include "Gem.h"

//	The collector of damage attributes from Weapon, SkillGems and SupportGems. 
//	This is for damage calculation.
struct DamageTerms
{
	std::string skillName = "";
	int baseDamage = 0;
	int skillDamage = 0;
	int elementalDamage = 0;
	int bonusDamage = 0;
};

//	Have 26 sockets(A~Z), deal with skill casting, moving gems and damage calculation.
class Weapon
{
public:
	Weapon();
	~Weapon();

	int FindGemOnWeapon(const std::string& _GemName);
	void EquipGem(int _socketIdx, Gem* _gem);
	int CastSkill(const std::string& _skillGemName);
	int CalculateDamage(const DamageTerms& _terms);
	void relation(DamageTerms& dmg, int idx, bool*& temp);
private:
	int baseDamage;
	int elementalDamage;
	Gem* sockets[26] = {};
	bool socketConnections[26][26] = {};

};
