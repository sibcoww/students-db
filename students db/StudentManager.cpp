#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "StudentManager.h"
#include <fstream>
using namespace std;

//methods
void StudentManager::addStudent(string name, string DOB, double gpa) {
	Student addedStud(nextId, name, DOB, gpa);
	students.push_back(addedStud);
	nextId++;
}
void StudentManager::printAll() {
	if (students.size() == 0)
	{
		cout << "No student" << endl;
		return;
	}
	for (Student& student : students) {
		student.printStudent();
	}
}
void StudentManager::delStudent(int id) {
	string Who;
	auto it = find_if(students.begin(), students.end(),
		[id](const Student& s) {return s.getID() == id; });

	if (it != students.end())
	{
		Who = it->getName();
		students.erase(it);
		nextId--;
		cout << "Student " << Who << " deleted" << endl;
	}
}
void StudentManager::searchStudent(int id) {
	auto it = find_if(students.begin(), students.end(),
		[id](const Student& s) {return s.getID() == id; });
	students[id].printStudent();
}
void StudentManager::sortStudents(int Type) {
	switch (Type)
	{
	case 1:
		//id
		for (int i = 0; i < students.size(); i++)
		{
			for (int j = i + 1; j < students.size(); j++)
			{
				if (students[i].getID() > students[j].getID())
				{
					Student temp = students[j];
					students[j] = students[i];
					students[i] = temp;
				}
			}
		}
	case 2:
		//gpa
		for (int i = 0; i < students.size(); i++)
		{
			for (int j = i + 1; j < students.size(); j++)
			{
				if (students[i].getGpa() > students[j].getGpa())
				{
					Student temp = students[j];
					students[j] = students[i];
					students[i] = temp;
				}
			}
		}
	case 3:
		//name
		for (int i = 0; i < students.size(); i++)
		{
			for (int j = i + 1; j < students.size(); j++)
			{
				if (students[i].getName() > students[j].getName())
				{
					Student temp = students[j];
					students[j] = students[i];
					students[i] = temp;
				}
			}
		}
	case 4:
		//DOB
		for (int i = 0; i < students.size(); i++)
		{
			for (int j = i + 1; j < students.size(); j++)
			{
				if (students[i].getDOB() > students[j].getDOB())
				{
					Student temp = students[j];
					students[j] = students[i];
					students[i] = temp;
				}
			}
		}
		break;
	default:
		break;
	}
}
void StudentManager::saveToTxt() {
	ofstream file("students.txt");
	if (file.is_open())
	{
		for (int i = 0; i < students.size(); i++)
		{
			file << students[i].getID() << " " <<
				students[i].getName() << " " <<
				students[i].getDOB() << " " <<
				students[i].getGpa() << " ";
		}
		cout << "Students saved to txt" << endl;
	}
	else {
		cout << "Error to open file" << endl;
	}

}
void StudentManager::readFromTxt() {
	ifstream file("students.txt");
	if (file.is_open())
	{
		int id;
		string name, DOB;
		double gpa;

		while (file >> id >> name >> DOB >> gpa)
		{
			Student addedStud(id, name, DOB, gpa);
			students.push_back(addedStud);
			nextId++;
		}
	}
	else {
		cout << "Error to open file" << endl;
	}
	cout << "Students loaded from txt. You can print all students to see" << endl;
}
