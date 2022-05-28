/*
Copyright (c) 2022 Yen-Chen Chiu.
All rights reserved.
Use of this source code is governed by a BSD-style license that can be
found in the LICENSE file.
*/
#include "Person.h"
using namespace std;

namespace vip_list
{
	Person::Person(const std::string person_name, const PersonType person_type)
	{
		name = person_name;
		type = person_type;
		is_vip = false;
		priority = -1;
		limit = 3;
	}

	Person::Person(const std::string person_name, const PersonType person_type, const bool person_is_vip, const int person_priority)
	{
		name = person_name;
		type = person_type;
		is_vip = person_is_vip;
		priority = is_vip ? 0 : person_priority;
		limit = 3;
	}

	Person::~Person()
	{
		// delete all child nodes (invitees)
		for (int i = invitees.size() - 1; i >= 0; i--)
		{
			delete invitees[i];
			invitees.pop_back();
		}
	}

	Person* Person::FindInviteeByName(const std::string name)
	{
		// Search the current list first.
		for (int invitee_index = 0; invitee_index < invitees.size(); invitee_index++)
		{
			if (invitees[invitee_index]->name == name)
				return invitees[invitee_index];
		}

		// Search the child nodes then.
		for (int invitee_index = 0; invitee_index < invitees.size(); invitee_index++)
		{
			Person* finding = invitees[invitee_index]->FindInviteeByName(name);
			if (finding != nullptr)
				return finding;
		}

		// Not found any.
		return nullptr;
	}

	void Person::AddInvitee(Person* guest)
	{
		if (priority >= 2 && !guest->IsVIP())
			throw exception("ERROR: The inviter with priority >= 2, can't invite the guest.");
		
		if (!guest->IsVIP()) {
			if (type == PersonType::Guest && !is_vip && invitees.size() >= limit)
				throw exception("ERROR: The inviter can't invite more guests.");
		}
		
		if (guest->IsVIP()) limit++;

		invitees.push_back(guest);
	}

	vector<Person*> Person::GetAllChildInvitees()
	{
		vector<Person*> all_invitees = vector<Person*>();
		for (int invitee_index = 0; invitee_index < invitees.size(); invitee_index++)
		{
			// add the direct invitee
			all_invitees.push_back(invitees[invitee_index]);

			// add all of indirect invitees (guest's guests)
			vector<Person*> child_invitees = invitees[invitee_index]->GetAllChildInvitees();
			for (int child_index = 0; child_index < child_invitees.size(); child_index++)
			{
				all_invitees.push_back(child_invitees[child_index]);
			}
		}
		return all_invitees;
	}

	string Person::GetName()
	{
		return name;
	}

	int Person::GetPriority()
	{
		return priority;
	}

	bool Person::IsVIP()
	{
		return is_vip;
	}
} // namespace vip_list
