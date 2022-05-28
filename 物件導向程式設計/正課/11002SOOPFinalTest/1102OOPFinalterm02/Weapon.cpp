#include "Weapon.h"
#include <algorithm>
Weapon::Weapon()
{
	//  initialize base attributes
	std::cin >> baseDamage >> elementalDamage;
	//  setting the connections of sockets
	int connectionCount;
	std::cin >> connectionCount;
	for (int c = 0; c < connectionCount; c++)
	{
		char node1, node2;
		std::cin >> node1 >> node2;

		socketConnections[node1 - 'A'][node2 - 'A'] = true;
		socketConnections[node2 - 'A'][node1 - 'A'] = true;
	}
}

Weapon::~Weapon()
{
}

int Weapon::FindGemOnWeapon(const std::string& _GemName)
{
	for (int s = 0; s < 26; s++)
	{
		if (sockets[s] != NULL && sockets[s]->GetName() == _GemName)
		{
			return s;
		}
	}
	//	return -1 if the gem is not found
	return -1;
}

void Weapon::EquipGem(int _socketIdx, Gem* _gem)
{
	int idx_gem = this->FindGemOnWeapon(_gem->GetName());
	if (_socketIdx == -1 && idx_gem != -1) this->sockets[idx_gem] = nullptr;
	if (_socketIdx != -1) {
		if (!this->sockets[_socketIdx]) { //this socket doesn't have thing
			if (idx_gem == -1) this->sockets[_socketIdx] = _gem; // fireball not in other socket
			else {
				this->sockets[idx_gem] = nullptr;
				this->sockets[_socketIdx] = _gem;
			}
		}
		else {
			if (idx_gem != -1)
				std::swap(this->sockets[_socketIdx], this->sockets[idx_gem]);
			else {
				this->sockets[_socketIdx] = _gem;
			}
		}
	}
}

void Weapon::relation(DamageTerms& dmg, int idx, bool*& temp) {

	for (int i = 0; i < 26; i++) {
		if (this->socketConnections[idx][i] && temp[i] == false) {// connect
			temp[i] = true;
			relation(dmg, i, temp);
			if (this->sockets[i]) {
				this->sockets[i]->Affect(dmg); //unemplace
			}
		}
	}
}

int Weapon::CastSkill(const std::string& _skillGemName)
{
	int idx = this->FindGemOnWeapon(_skillGemName);
	if(idx == -1) throw std::exception("Gem is not placed in any socket");
	else {
		//calculate dmg
		DamageTerms dmg;
		dmg.skillName = _skillGemName;
		dmg.baseDamage = this->baseDamage;
		dmg.skillDamage = sockets[idx]->getSkillDmg();
		dmg.elementalDamage += this->elementalDamage;
		//sockets[idx]->Affect(dmg); //skill self
		dmg.bonusDamage = 0;

		bool* temp = new bool[26]{};
		relation(dmg, idx, temp);
		delete[] temp;
		return CalculateDamage(dmg);
	}
}

int Weapon::CalculateDamage(const DamageTerms& _terms)
{
	return (_terms.baseDamage + _terms.elementalDamage) * _terms.skillDamage * (1 + _terms.bonusDamage);
}
