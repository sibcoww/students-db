#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

//construcors
Student::Student() = default;
Student::Student(int id, string name, string dateOfBirth, double gpa) : name(name), id(id) {
	if (!isValidDate(dateOfBirth))
	{
		throw invalid_argument("Incorrect argument. Date must be dd.mm.yyyy");
	}
	else {
		this->dateOfBirth = dateOfBirth;
	}
	if (!isValidGpa(gpa))
	{
		throw invalid_argument("Incorrect argument. GPA must be beween 0.1 and 4.0");
	}
	else {
		this->gpa = gpa;
	}
}
//methods
void Student::printStudent() const {
	cout << "----------------------------------" << endl;
	cout << "ID:\t\t" << id << endl;
	cout << "Name:\t\t" << name << endl;
	cout << "DOB:\t\t" << dateOfBirth << endl;
	cout << "GPA:\t\t" << gpa << endl;
	cout << "----------------------------------" << endl;
}

bool Student::isValidDate(string DOB)
{
	if (DOB.length() != 10) { return false; }
	if (DOB[2] != '.' || DOB[5] != '.') { return false; }
	for (int i = 0; i < 10; i++) {
		if (i == 2 || i == 5) { continue; }
		if (!isdigit(DOB[i])) { return false; }
	}

	int day = stoi(DOB.substr(0, 2));
	int month = stoi(DOB.substr(3, 2));
	int year = stoi(DOB.substr(6, 4));

	if (day < 1 || day > 31) return false;
	if (month < 1 || month > 12) return false;
	if (year < 1900 || year > 2100) return false;

	return true;
}
bool Student::isValidGpa(double gpa) {

	return gpa >= 0.1 && gpa <= 4.0;
}
//getters
int Student::getID() const { return id; }
string Student::getName() const { return name; }
string Student::getDOB() const { return dateOfBirth; }
double Student::getGpa() const { return gpa; }
//setters
void Student::setID(int ID) { id = ID; }
void Student::setName(string Name) { name = Name; }
void Student::setDOB(string DOB) { dateOfBirth = DOB; }
void Student::setGpa(double Gpa) { gpa = Gpa; }