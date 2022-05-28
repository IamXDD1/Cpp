/*
Copyright (c) 2022 Yen-Chen Chiu.
All rights reserved.
Use of this source code is governed by a BSD-style license that can be
found in the LICENSE file.
 */
#ifndef VIP_LIST_PERSON_H_
#define VIP_LIST_PERSON_H_
#include <string>
#include <vector>

namespace vip_list
{
	// This enum indicates if a person is a host or guest.
	enum class PersonType : int
	{
		Host = 0,
		Guest = 1
	};

	// A Person represents either a guest or a host with a name.
	// If it's a guest, it has priority number >= 0, and can be VIP or non-VIP.
	// Example:
	//		Person* host = new Person("Host A", PersonType::Host);
	//		Person* guest = new Person("Guest A", PersonType::Guest, false, 0);
	//		host->AddInvitee(guest);
	class Person
	{
	public:
		// constructor, assume it's a host
		Person(const std::string person_name, const PersonType person_type);
		// constructor, for a guest.
		Person(const std::string person_name, const PersonType person_type, const bool person_is_vip, const int person_priority);
		// destructor, which delete all the invitees.
		~Person();

		// Returns a person that is an invitee of this person or any of this person's invitees.
		// Returns nullptr if there's no invitee with the name.
		Person* FindInviteeByName(const std::string name);

		// Add a invitee.
		// But if this inviter doesn't match the conditions, an exception would be thrown.
		void AddInvitee(Person* invitee);

		// Get all the invitees from this person, and all of this person's invitees. (Recursive)
		std::vector<Person*> GetAllChildInvitees();

		std::string GetName();
		int GetPriority();
		bool IsVIP();

	private:
		std::string name;
		PersonType type;
		bool is_vip;
		int priority;

		std::vector<Person*> invitees;
		int limit;
	};
}  // namespace vip_list

#endif  // VIPLIST_GUEST_H_
