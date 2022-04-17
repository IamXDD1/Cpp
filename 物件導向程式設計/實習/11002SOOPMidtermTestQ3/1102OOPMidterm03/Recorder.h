#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Student {
public:
	string name;
	vector<pair<string, float>> grade;
	int selfID;
	static int ID;
	static int default_count;
	static vector<string> existName;

	Student();
	Student(string name);
	void addGrade(std::string subject, int point);
	void deleteGrade(std::string subject);
	void deleteGrade();
	void printGrade();
};  

class Class {
	vector<Student> students;
	unordered_map<string, vector<pair<string, float>>> subjects;
public:
	Class();
	void addStudent(Student student);
	void deleteStudent(Student student);
	void deleteStudent(std::string studentName);
	void printNumOfStudent(std::string subjectName);
	void printNumOfStudent();
	void printAvgScore(std::string subjectName);
	void printAvgScore();
	void printSubjectInformation(std::string subjectName);
	void printSubjectInformation();
};