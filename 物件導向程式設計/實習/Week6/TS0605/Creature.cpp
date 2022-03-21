#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "Creature.h"
#include "Diary.h"

Creature::Creature(std::string name) : cname(name) {
	log.push_back(name + "'s log:\n");
	status = name + "'s status:\n";
	day_index = Diary::date_index-1;
	updateDay();
}
Creature::Creature(std::string name, Creature base) : cname(name), bodyPart(base.bodyPart), curr_body(base.curr_body){
	base.updateDay();
	log.push_back(name + "'s log:\n");
	status = name + "'s status:\n";
	day_index = base.day_index-1;
	updateDay();
}

void Creature::updateDay() {
	for (;day_index != Diary::full_date.size(); day_index++) {
		log.push_back("Day " + Diary::full_date[day_index] + "\n");
	}
}
void Creature::PrintStatus() {
	std::cout << status;
	for (auto const& body : bodyPart) {
		if (bodyPart[body.first] != 0) std::cout << body.first << " * " << body.second << '\n';
	}
	std::cout << '\n';
	return;
}
void Creature::PrintLog() {
	updateDay();
	for (auto const& record : log) std::cout << record;
	std::cout << '\n';
	return;
}

Creature& Creature::operator[](std::string body) {
	curr_body = body;
	return *this;
}
Creature& Creature::operator=(int num) {
	updateDay();
	
	if (bodyPart[curr_body] != num) {
		if (bodyPart[curr_body] == 0) {
			if (num != 0) {
				log.push_back(cname + "'s " + curr_body + " appeared (0 -> " + std::to_string(num) + ").\n");
			}
		}
		else if (bodyPart[curr_body] > num) {
			log.push_back(cname + "'s " + curr_body +
				" decreased (" + std::to_string(bodyPart[curr_body]) + " -> " + std::to_string(num) + ").\n");
		}
		else {
			log.push_back(cname + "'s " + curr_body +
				" increased (" + std::to_string(bodyPart[curr_body]) + " -> " + std::to_string(num) + ").\n");
		}
		bodyPart[curr_body] = num;
	}
	return *this;
}
Creature& Creature::operator+=(int num) {
	updateDay();
	if (num != 0) {
		if (num > 0) {
			if (bodyPart[curr_body] == 0) {
				log.push_back(cname + "'s " + curr_body + " appeared (0 -> " + std::to_string(num) + ").\n");
			}
			else {
				log.push_back(cname + "'s " + curr_body +
					" increased (" + std::to_string(bodyPart[curr_body]) + " -> "
					+ std::to_string(bodyPart[curr_body] + num) + ").\n");
			}
		}
		else {
			log.push_back(cname + "'s " + curr_body +
				" decreased (" + std::to_string(bodyPart[curr_body]) + " -> "
				+ std::to_string(bodyPart[curr_body] + num) + ").\n");
		}
		bodyPart[curr_body] += num;
	}
	return *this;
}
Creature& Creature::operator-=(int num) {
	updateDay();
	if (num != 0) {
		if (num < 0) {
			if (bodyPart[curr_body] == 0) {
				log.push_back(cname + "'s " + curr_body + " appeared (0 -> " + std::to_string(-num) + ").\n");
			}
			else {
				log.push_back(cname + "'s " + curr_body +
					" increased (" + std::to_string(bodyPart[curr_body]) + " -> "
					+ std::to_string(bodyPart[curr_body] - num) + ").\n");
			}
		}
		else {
			log.push_back(cname + "'s " + curr_body +
				" decreased (" + std::to_string(bodyPart[curr_body]) + " -> "
				+ std::to_string(bodyPart[curr_body] - num) + ").\n");
		}
		bodyPart[curr_body] -= num;
	}
	return *this;
}