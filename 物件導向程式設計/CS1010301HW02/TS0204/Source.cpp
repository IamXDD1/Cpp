#include <iostream>
#include <string>
#include <iomanip>

struct People {
	std::string name;
	std::string salary;
	std::string bonus;
};

int main() {

	int n = 0;
	for (; std::cin >> n;) {
		People* employees = new People[n];
		int name_len(0), salary_len(0), bonus_len(0);

		for (int i = 0; i < n; i++) {
			std::cin >> employees[i].name >> employees[i].salary >> employees[i].bonus;

			if (employees[i].name.length() > name_len) {
				name_len = employees[i].name.length();
			}
			if (employees[i].salary.length() > salary_len) {
				salary_len = employees[i].salary.length();
			}
			if (employees[i].bonus.length() > bonus_len) {
				bonus_len = employees[i].bonus.length();
			}
		}

		for (int i = 0; i < n; i++) {
			std::cout << std::setw(name_len) << employees[i].name << "|"
				<< std::setw(salary_len + 2) << employees[i].salary << "|"
				<< std::setw(bonus_len + 2) << employees[i].bonus<<"\n";
		}

		delete[] employees;
	}

	return 0;
}