#include <iostream>
#include <string>
#include <vector>

typedef struct {
	char firstName[25];
	char lastName[30];
	char phone[15];
} StRec;

bool check_phone_error(std::string& phone) {
	for (int i = 0; i < phone.length(); i++) {
		if (!(phone[i] >= '0' && phone[i] <= '9')) return true;
	}
	return false;
}

int check_student_exist(std::string& Fname, std::string& Sname,
	std::string& Phone, std::vector<StRec>& student) {
	for (int i = 0; i < student.size(); i++) {
		if (student[i].firstName == Fname && student[i].lastName == Sname
			&& student[i].phone == Phone) return i + 1;
	}
	return 0;
}

class Commands {
	std::vector<StRec> student;
public:
	void fn_insert() {
		std::string Fname, Sname, Phone;
		std::cin >> Fname >> Sname >> Phone;
		if (Fname.length() > 25 || Sname.length() > 30 || Phone.length() > 15
			|| check_phone_error(Phone)) {
			std::cout << "Input Error\n";
			return;
		}

		if (student.size() == 10 || check_student_exist(Fname, Sname, Phone, student)) {
			std::cout << "Insert Error\n";
			return;
		}

		StRec* temp = new StRec;

		char* str_start = &Fname[0];
		strcpy(temp->firstName, str_start);
		str_start = &Sname[0];
		strcpy(temp->lastName, str_start);
		str_start = &Phone[0];
		strcpy(temp->phone, str_start);

		student.push_back(*temp);

		return;
	}
	void fn_delete() {
		std::string Fname, Sname, Phone;
		std::cin >> Fname >> Sname >> Phone;
		if (Fname.length() > 25 || Sname.length() > 30 || Phone.length() > 15
			|| check_phone_error(Phone)) {
			std::cout << "Input Error\n";
			return;
		}

		int student_delete = check_student_exist(Fname, Sname, Phone, student);
		if (student_delete) {
			student.erase(student.begin() + student_delete - 1);
		}
		else std::cout << "Delete Error\n";

		return;
	}
	void fn_search() {
		std::string Fname, Sname, Phone;
		std::cin >> Fname >> Sname >> Phone;
		if (Fname.length() > 25 || Sname.length() > 30 || Phone.length() > 15
			|| check_phone_error(Phone)) {
			std::cout << "Input Error\n";
			return;
		}

		int student_search = check_student_exist(Fname, Sname, Phone, student);
		if (student_search) {
			std::cout << student_search - 1 << '\n';
		}
		else std::cout << "Search Error\n";

		return;
	}
	void fn_print() {
		if (student.empty()) std::cout << "Print Error\n";
		else {
			for (int i = 0; i < student.size(); i++) {
				std::cout << student[i].firstName << ' '
					<< student[i].lastName << ' ' << student[i].phone << '\n';
			}
		}
	}
};


int main() {
	Commands cmd;
	std::string str_cmd = "";

	for (; std::cin >> str_cmd;) {
		if (str_cmd == "insert") cmd.fn_insert();
		else if (str_cmd == "delete") cmd.fn_delete();
		else if (str_cmd == "search") cmd.fn_search();
		else if (str_cmd == "print") cmd.fn_print();
		else std::cout << "Input Error\n";
	}

	return 0;
}