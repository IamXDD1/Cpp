#include "Recorder.h"
int main()
{
	Student a = Student();
	Student b = Student("John");
	Student c = Student("John");
	Student d = Student("Student77");
	a.addGrade("OOP", 50);
	a.addGrade("OOP", 60);
	a.printGrade();

	b.addGrade("OOP", 60);
	b.deleteGrade();
	b.deleteGrade("OOP");
	b.addGrade("Chinese", 70);
	b.addGrade("OOP", 64);
	b.printGrade();

	c.addGrade("OOP", 70);
	c.addGrade("English", 60);
	c.printGrade();

	d.addGrade("OOP", 100);

	Class cls;
	cls.addStudent(a);
	cls.addStudent(b);
	cls.addStudent(c);
	cls.addStudent(d);
	cls.addStudent(d);

	cls.deleteStudent(a);
	cls.deleteStudent("Student2");
	cls.deleteStudent("Student22");

	cls.printNumOfStudent();
	cls.printNumOfStudent("oop");
	cls.printNumOfStudent("OOP");
	cls.printAvgScore();
	cls.printAvgScore("eng");
	cls.printAvgScore("English");
	
	cls.printSubjectInformation();
	cls.printSubjectInformation("chin");
	cls.printSubjectInformation("Chinese");
	
	return 0;
}