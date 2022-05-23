#pragma once
#include <string>
#include <iostream>

using namespace std;

class School {
protected:
	string schoolname;
	int studentAmount;
	int studentAmountNextYear;

public: 
	School() : schoolname(""), studentAmount(0), studentAmountNextYear(0) {};
	School(string name, int num) : schoolname(name), studentAmount(num), studentAmountNextYear(num) {};

	void admissions(float amount) {
		if(amount >= 0) studentAmount += amount;
	}
	virtual void dropouts(float amount) {
		if (amount >= 0 && amount <= studentAmount) {
			studentAmount -= amount;
		}
	}
	void transfer(float amount, School& toSchool) {
		if (amount >= 0 && amount <= studentAmount) {
			this->dropouts(amount);
			toSchool.admissions(amount);
		}
	}

	friend ostream& operator << (ostream& out, School& sch) {
		out << sch.schoolname << '\t' << sch.studentAmount << '\t' << sch.studentAmountNextYear;
		return out;
	}
};

class PrivateSchool : public School {
protected:
	string schoolname;
	int countDropout;
public:
	PrivateSchool() : School(), schoolname(""), countDropout(0){};
	PrivateSchool(string name, int num) : School(name, num), schoolname(name), countDropout(0) {};

	void dropouts(float amount) {
		studentAmount -= amount;
		if (countDropout >= 1) {
			studentAmountNextYear -= 100;
		}
		countDropout++;
	}
	friend ostream& operator << (ostream& out, PrivateSchool& sch) {
		out << sch.schoolname << '\t' << sch.studentAmount << '\t' << sch.studentAmountNextYear;
		return out;
	}
};

class PublicSchool : public School {
	string schoolname;
	double growing_rate;
public:
	PublicSchool() :School(), schoolname(""), growing_rate(0.05) {};
	PublicSchool(string name, int num) :School(name, num), schoolname(name), growing_rate(0.05) {};
	
	void apply_growth() {
		this->studentAmountNextYear += growing_rate * studentAmountNextYear;
	}
	void dropouts(float amount) {
		bool inRange = false;
		if (amount >= 0 && amount <= studentAmount) {
			studentAmount -= amount;
			inRange = true;
		}
		if (amount > 100 && inRange) studentAmountNextYear = static_cast<int>(static_cast<double>(studentAmountNextYear) * 0.95);
	}
	friend ostream& operator << (ostream& out, PublicSchool& sch) {
		out << sch.schoolname << '\t' << sch.studentAmount << '\t' << sch.studentAmountNextYear;
		return out;
	}
};