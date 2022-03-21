#include <string>
#include "Diary.h"

int Diary::date_index = 0;
std::string Diary::date;
std::vector<std::string> Diary::full_date;

void Diary::NewDay(std::string day) {
	date_index++;
	date = day;
	full_date.push_back(day);
}
