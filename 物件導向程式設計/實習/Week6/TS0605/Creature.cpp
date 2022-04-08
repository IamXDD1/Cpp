#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Creature.h"

std::vector<std::string> Diary::date;

Creature::Creature(std::string name) : name(name), index(Diary::date.size()-1)
{
	status.push_back(name + "'s status:\n");
	log.push_back(name+"'s log:\n");
	updatedate();
}

Creature::Creature(std::string name, Creature a) : name(name), body(a.body)
{
	a.updatedate();
	status.push_back(name + "'s status:\n");
	log.push_back(name + "'s log:\n");
	index = a.index - 1;
	updatedate();
}

void Creature::updatedate() 
{
	for (; index != Diary::date.size(); index++) {
		log.push_back("Day " + Diary::date[index] + "\n");
	}
}

void Creature::PrintStatus()
{
	updatedate();
	std::cout << status[0];
	for (auto const& a : body) {
		if(a.second != 0) std::cout << a.first << " * " << a.second<< '\n';
	}
	std::cout << '\n';
}

void Creature::PrintLog()
{
	updatedate();
	for (int i = 0; i < log.size(); i++) {
		std::cout << log[i];
	}
	std::cout << '\n';
}

Creature& Creature::operator[](std::string bodypart)
{
	updatedate();
	curr_body = bodypart;
	return *this;
}

Creature Creature::operator=(int num)
{
	updatedate();
	if (body[curr_body] != num) {
		if (body[curr_body] == 0) {
			log.push_back(name + "'s " + curr_body + " appeared (0 -> "
				+ std::to_string(num) + ").\n");
		}
		else if (num > body[curr_body]) {
			log.push_back(name+"'s "+curr_body+" increased ("+
			std::to_string(body[curr_body])+" -> "+std::to_string(num)+").\n");
		}
		else if (num < body[curr_body]) {
			log.push_back(name + "'s " + curr_body + " decreased ("+
				std::to_string(body[curr_body]) + " -> " + std::to_string(num) + ").\n");
		}
		body[curr_body] = num;
	}
	return *this;
}

Creature Creature::operator+=(int num)
{
	updatedate();
	if (num > 0) {
		if(body[curr_body] != 0)
			log.push_back(name + "'s " + curr_body + " increased (" +
				std::to_string(body[curr_body]) + " -> " + std::to_string(num + body[curr_body]) + ").\n");
		else
			log.push_back(name + "'s " + curr_body + " appeared (0 -> "
				+ std::to_string(num) + ").\n");
	}
	else if (num < 0) {
		log.push_back(name + "'s " + curr_body + " decreased (" +
			std::to_string(body[curr_body]) + " -> " + std::to_string(num + body[curr_body]) + ").\n");
	}
	body[curr_body] += num;
	return *this;
}

Creature Creature::operator-=(int num)
{
	updatedate();
	if (num < 0) {
		if(body[curr_body] != 0)
			log.push_back(name + "'s " + curr_body + " increased (" +
				std::to_string(body[curr_body]) + " -> " + std::to_string(body[curr_body] - num) + ").\n");
		else
			log.push_back(name + "'s " + curr_body + " appeared (0 -> "
				+ std::to_string(-num) + ").\n");
	}
	else if (num > 0) {
		log.push_back(name + "'s " + curr_body + " decreased (" +
			std::to_string(body[curr_body]) + " -> " + std::to_string(body[curr_body] - num) + ").\n");
	}
	body[curr_body] -= num;
	return *this;
}
