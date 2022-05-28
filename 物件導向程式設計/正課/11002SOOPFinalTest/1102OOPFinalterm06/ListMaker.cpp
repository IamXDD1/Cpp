/*
Copyright (c) 2022 Yen-Chen Chiu.
All rights reserved.
Use of this source code is governed by a BSD-style license that can be
found in the LICENSE file.
 */
#include "ListMaker.h"
using namespace std;

namespace vip_list
{
	ListMaker::ListMaker()
	{
		hosts = vector<Person*>();
	}

	void ListMaker::StartInput()
	{
		EnterHosts();
		EnterGuests();
	}

	void ListMaker::PrintList()
	{
		cout << "==============================" << endl;
		cout << "The Guest List:" << endl;

		// gets the vip list, and non-vip list, separately.
		vector<Person*> vips = vector<Person*>();
		vector<Person*> non_vips = vector<Person*>();
		for (int host_index = 0; host_index < hosts.size(); host_index++)
		{
			vector<Person*> all_child_invitees = hosts[host_index]->GetAllChildInvitees();
			for (int child_index = 0; child_index < all_child_invitees.size(); child_index++)
			{
				if (all_child_invitees[child_index]->IsVIP())
				{
					vips.push_back(all_child_invitees[child_index]);
				}
				else
				{
					non_vips.push_back(all_child_invitees[child_index]);
				}
			}
		}

		// sorts each list
		vips = SortListByName(vips);
		non_vips = SortListByName(non_vips);

		// prints all
		for (int vip_index = 0; vip_index < vips.size(); vip_index++)
		{
			cout << "VIP: " << vips[vip_index]->GetName() << endl;
		}
		for (int nonvip_index = 0; nonvip_index < non_vips.size(); nonvip_index++)
		{
			cout << non_vips[nonvip_index]->GetName() << endl;
		}
	}

	Person* ListMaker::FindPersonByName(const std::string name)
	{
		// Search every host.
		for (int host_index = 0; host_index < hosts.size(); host_index++)
		{
			Person* host = hosts[host_index];
			// check if it's host's name.
			if (host->GetName() == name)
				return host;
			else
			{
				// check if it's one of host's invitees.
				Person* finding = host->FindInviteeByName(name);
				if (finding != nullptr)
					return finding;
			}
		}

		return nullptr;
	}

	void ListMaker::EnterHosts()
	{
		cout << "Please enter the names of the hosts." << endl;
		cout << "(Enter \"END\" when finished):" << endl;
		string text = "";
		while (getline(cin, text))
		{
			if (text == "END") break;
			if (FindPersonByName(text) == nullptr) {
				hosts.push_back(new Person(text, PersonType::Host));
				cout << "Host: " << text << " imported." << endl;
			}
			else cout << "ERROR: This is a duplicated name, cannot be imported.\n";
		}
	}

	void ListMaker::EnterGuests()
	{
		cout << "Please enter the names of the guests and their inviters." << endl;
		cout << "(Add # in front of the line if it's VIP. Separated with \";\". Enter \"END\" when finished):" << endl;
		string text = "";
		while (getline(cin, text))
		{
			if (text == "END") break;

			// split text to two names.
			string guest_name = "";
			string inviter_name = "";
			bool is_vip = false;
			for (unsigned long long i = 0; i < text.size(); i++)
			{
				if (i == 0 && text[0] == '#')
				{
					is_vip = true;
					continue;
				}

				int offset = is_vip ? 1 : 0;
				if (text[i] == ';')
				{
					guest_name = text.substr(offset, i - offset);
					inviter_name = text.substr(i + 1);
					break;
				}
			}

			// Add a Guest by name.
			try
			{
				AddGuest(guest_name, inviter_name, is_vip);
				if (!is_vip)
					cout << "Guest: " << guest_name << " (invited by " << inviter_name << ")" << " imported." << endl;
				else
					cout << "Guest(VIP): " << guest_name << " (invited by " << inviter_name << ")" << " imported." << endl;
			}
			catch (exception e)
			{
				cout << e.what() << endl;
			}
		}
	}

	void ListMaker::AddGuest(const std::string guest_name, const std::string inviter_name, bool is_vip)
	{
		// check if the inviter exists.
		Person* inviter = FindPersonByName(inviter_name);
		if (inviter == nullptr)
			throw exception("ERROR: The inviter doesn't exist.");

		// check if it's repeated guest name
		Person* find_name = FindPersonByName(guest_name);
		if(find_name != nullptr)
			throw exception("ERROR: This is a duplicated name, cannot be imported.");

		// Create new guest
		Person* guest = new Person(guest_name, PersonType::Guest, is_vip, inviter->GetPriority() + 1);

		// Add as the inviter's invitee.
		inviter->AddInvitee(guest);
	}

	vector<Person*> ListMaker::SortListByName(std::vector<Person*> unsorted)
	{
		vector<Person*> sorted = vector<Person*>();

		for (int unsorted_index = 0; unsorted_index < unsorted.size(); unsorted_index++)
		{
			Person* current_inserting = unsorted[unsorted_index];
			int insert_index = 0;

			
			while (insert_index < sorted.size())
			{
				if (current_inserting->GetPriority() == sorted[insert_index]->GetPriority()) {
					int compare_result = CompareNameAlphabetically(
						current_inserting->GetName(),
						sorted[insert_index]->GetName());
					// means this is the inserting index.
					if (compare_result > 0)
						break;

					insert_index++;
				}
				else if (current_inserting->GetPriority() > sorted[insert_index]->GetPriority()) {
					insert_index++;
				}
				else break;
			}
			sorted.insert(sorted.begin() + insert_index, current_inserting);
		}
		return sorted;
	}

	// Returns 1 if str1 is higher than str2 in alphabetical order.
	// Returns -1 if str1 is lower than str2 in alphabetical order.
	// Returns 0 if str1 is equal to str2 in alphabetical order.
	int ListMaker::CompareNameAlphabetically(string str1, string str2)
	{
		// compare length
		int length_compare = 0;
		if (str1.length() < str2.length())
			length_compare = 1;
		else if (str1.length() > str2.length())
			length_compare = -1;

		// use the shortest string.
		int length = length_compare > 0 ? str1.length() : str2.length();

		// compare character one by one.
		for(int index = 0; index < length; index++)
		{
			if (str1[index] < str2[index])
				return 1;
			else if (str1[index] > str2[index])
				return -1;
		}

		// In here, all characters in length are the same, so comepare the length.
		return length_compare;
	}
} //namespace vip_list
