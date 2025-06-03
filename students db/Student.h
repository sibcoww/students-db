#pragma once
#include <string>

using namespace std;

class Student {
private:
	//atributs
	int id = -1;
	string name = "Unknown";
	string dateOfBirth = "01.01.2000";
	double gpa = 0.0;
	//private methods
	bool isValidDate(string DOB);
	bool isValidGpa(double GPA);
public:
	//construcors
	Student();
	Student(int id, string name, string dateOfBirth, double gpa);
	//methods
	void printStudent() const;
	//getters
	int getID() const;
	string getName() const;
	string getDOB() const;
	double getGpa() const;
	//setters
	void  setID(int ID);
	void  setName(string Name);
	void  setDOB(string DOB);
	void  setGpa(double Gpa);
};