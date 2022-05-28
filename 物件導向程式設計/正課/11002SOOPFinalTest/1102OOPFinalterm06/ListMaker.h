/*
Copyright (c) 2022 Yen-Chen Chiu.
All rights reserved.
Use of this source code is governed by a BSD-style license that can be
found in the LICENSE file.
 */
#ifndef VIP_LIST_Maker_H_
#define VIP_LIST_Maker_H_
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "Person.h"

namespace vip_list
{
	// This class controls the program to interact with the user.
	// User can input the names of hosts and guests, then this class can output the list.
	// Example:
	//		ListMaker list_maker = ListMaker();
	//		list_maker.StartInput();
	//		list_maker.PrintList();
	class ListMaker
	{
	public:
		// constructor
		ListMaker();
		
		// Controls the program to let user inputs names of hosts, then inputs names of guests.
		void StartInput();
		// Outputs the list of the guests, by a specific order.
		void PrintList();

	private:
		std::vector<Person*> hosts;

		// Finds a person of the name, including hosts'.
		Person* FindPersonByName(const std::string name);
		// Controls the program to let user inputs names of hosts. With corresponding interactive outputs.
		void EnterHosts();
		// Controls the program to let user inputs names of guests. With corresponding interactive outputs.
		void EnterGuests();
		// Tries to add a guest by its name and its inviter's name.
		// Would return exception when this operation failed.
		void AddGuest(const std::string guest_name, const std::string inviter_name, bool is_vip);
		// Returns a vector sorted by alphabetical order of every person's name.
		std::vector<Person*> SortListByName(std::vector<Person*> unsorted);
		// Compares two strings in alphabetical order.
		int CompareNameAlphabetically(std::string str1, std::string str2);
	};
}

#endif // VIP_LIST_Maker_H_
