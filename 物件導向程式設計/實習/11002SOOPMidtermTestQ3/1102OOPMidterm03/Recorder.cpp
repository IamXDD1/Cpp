#include "Recorder.h"

int Student::ID = 0;
int Student::default_count = 0;
vector<string> Student::existName;

Student::Student()
{
	name = "Student" + to_string(default_count);
	default_count++;

	selfID = ID;
	ID++;
}

Student::Student(string name)
{
	selfID = ID;
	bool find = false;
	for (int i = 0; i < existName.size(); i++) {
		if (existName[i] == name) {
			find = true;
			break;
		}
	}

	if (find) {
		this->name = "Student" + to_string(default_count);
		default_count++;
		cout << "Error: The name " + name + " exists. Use default name: " + this->name + ".\n";
	}
	else {
		if (name.substr(0, 7) == "Student") {
			this->name = "Student" + to_string(default_count);
			default_count++;
			cout << "Error: The name Student is reserved word. Use default name: " + this->name + ".\n";
		}
		else {
			this->name = name;
			existName.push_back(this->name);
		}
	}

	ID++;
}

void Student::addGrade(std::string subject, int point)
{
	bool find = false;
	for (int i = 0; i < grade.size(); i++) {
		if (grade[i].first == subject) {
			grade[i].second = point;
			find = true;
			break;
		}
	}
	if(!find) grade.push_back({ subject, point });
}

void Student::deleteGrade(std::string subject)
{
	bool find = false;
	for (int i = 0; i < grade.size(); i++) {
		if (grade[i].first == subject) {
			grade.erase(grade.begin() + i);
			find = true;
			break;
		}
	}
	if (!find) cout << "Error: Subject " + subject + " could not be found.\n";
}

void Student::deleteGrade()
{
	grade.clear();
}

void Student::printGrade()
{
	cout << "ID: " + to_string(selfID) + " Name: " + name << '\n';

	if (grade.empty()) cout << "Error: Grade could not be found.\n";
	else {
		for (int i = 0; i < grade.size(); i++) {
			cout << grade[i].first << ' ' << grade[i].second << '\n';
		}
	}
}


Class::Class()
{
}

void Class::addStudent(Student student)
{
	bool find = false;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].name == student.name) {
			find = true;
			break;
		}
	}
	if (find) {
		cout << "Error: The student " + student.name + " is already in the class.\n";
	}
	else {
		//for(int i=0; i<students.size(); i++)
		students.push_back(student);
		/*
		for (int i = 0; i < student.grade.size(); i++) {
			subjects[student.grade[i].first].push_back({ student.name, student.grade[i].second });
		}
		*/
	}
}

void Class::deleteStudent(Student student)
{
	bool find = false;
	for (int i = 0; i < students.size(); i++) { //找student
		if (students[i].name == student.name) {
			find = true;
			/*
			for (int j = 0; j < students[i].grade.size(); j++) { //刪除grade內部的student
				for (int x = 0; x < subjects[students[i].grade[j].first].size(); x++) { //尋訪
					if (subjects[students[i].grade[j].first][x].first == student.name) {
						subjects[students[i].grade[j].first].erase(subjects[students[i].grade[j].first].begin() + x);
						break;
					}
				}
			}
			*/
			students.erase(students.begin() + i);
			break;
		}
	}

	if (!find) cout << "Error: Student " + student.name + " could not be found.\n";
}
//https://blog.csdn.net/pzhw520hchy/article/details/77945713
//https://en.cppreference.com/w/cpp/container/map/find
//https://en.cppreference.com/w/cpp/container/map/count
void Class::deleteStudent(std::string studentName)
{
	bool find = false;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].name == studentName) {
			find = true;
			/*
			for (unordered_map<string, vector<pair<string, float>>>::iterator it = subjects.begin();
				it != subjects.end(); it++) { //刪除grade內部的student
				for (int j = 0, count = 0; j < it->second.size(); j++) {
					if (it->second[j].first == studentName) {
						it->second.erase(it->second.begin() + j);
						break;
					}
				}
			}
			*/
			students.erase(students.begin() + i);
			break;
		}
	}

	if (!find) cout << "Error: Student " + studentName + " could not be found.\n";
}

void Class::printNumOfStudent(std::string subjectName)
{
	int count = 0;
	for (auto it : students) {
		for (int i = 0; i < it.grade.size(); i++) {
			if (it.grade[i].first == subjectName) count++;
		}
	}

	if (count != 0) cout << subjectName << ' ' << count << '\n';
	else cout << "Error: Subject " + subjectName + " could not be found.\n";
}

void Class::printNumOfStudent()
{
	unordered_map<string, vector<pair<string, float>>> temp;
	for (auto it : students) {
		for (int i = 0; i < it.grade.size(); i++) {
			temp[it.grade[i].first].push_back({ it.name, it.grade[i].second });
		}
	}
	for(auto it : temp) cout << it.first << ' ' << it.second.size() << '\n';
}

void Class::printAvgScore(std::string subjectName)
{
	float avr = 0;
	int count = 0;
	for (auto it : students) {
		for (int i = 0; i < it.grade.size(); i++) {
			if (it.grade[i].first == subjectName) {
				avr += it.grade[i].second;
				count++;
			}
		}
	}

	if (count) cout << subjectName << ' ' << avr / count << '\n';
	else cout << "Error: Subject " + subjectName + " could not be found.\n";
}

void Class::printAvgScore()
{
	unordered_map<string, vector<pair<string, float>>> temp;
	for (auto it : students) {
		for (int i = 0; i < it.grade.size(); i++) {
			temp[it.grade[i].first].push_back({ it.name, it.grade[i].second });
		}
	}

	for (auto it : temp) {
		float avr = 0;
		for (auto vec_it : it.second)
			avr += vec_it.second;
		cout << it.first << ' ' << avr / it.second.size() << '\n';
	}
}

void Class::printSubjectInformation(std::string subjectName)
{
	vector<pair<string, float>> temp;
	for (auto it : students) {
		for (int i = 0; i < it.grade.size(); i++) {
			if (it.grade[i].first == subjectName) temp.push_back({ it.name, it.grade[i].second });
		}
	}

	if (temp.size() == 0) cout << "Error: Subject " + subjectName + " could not be found.\n";
	else {
		cout << "Subject name: " << subjectName << '\n';
		cout << "Num of students: " << temp.size() << '\n';
		for (auto it : temp) {
			cout << it.first << ' ' << it.second << '\n';
		}
	}
}

void Class::printSubjectInformation()
{
	unordered_map<string, vector<pair<string, float>>> temp;
	for (auto it : students) {
		for (int i = 0; i < it.grade.size(); i++) {
			temp[it.grade[i].first].push_back({ it.name, it.grade[i].second });
		}
	}

	for (auto it : temp) {
		cout << "Subject name: " << it.first << '\n';
		cout << "Num of students: " << it.second.size() << '\n';
		for (auto vec_it : it.second)
			cout << vec_it.first << ' ' << vec_it.second << '\n';
	}
}
