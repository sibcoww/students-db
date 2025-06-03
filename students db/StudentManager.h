#pragma once
#include <vector>
#include "Student.h"
using namespace std;

class StudentManager {
private:
	//atributs
	vector<Student> students;
	int nextId = 1;
public:
	//methods
	void addStudent(string name, string DOB, double gpa);
	void printAll();
	void delStudent(int id);
	void searchStudent(int id);
	void sortStudents(int Type);
	void saveToTxt();
	void readFromTxt();
};