#include <iostream>
#include "StudentManager.h"
using namespace std;

bool isCinError()
{
	if (cin.fail()) {
		cout << "Invalid input!" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		return true;
	}
	return false;
}
int main() {
	StudentManager manager;
	int answer;
	while (true) {
		cout << "1. Add new student\n";
		cout << "2. Delete student\n";
		cout << "3. Print all students\n";
		cout << "4. Sort student by ...\n";
		cout << "5. Load from file\n";
		cout << "6. Save to file\n";
		cout << "0. Exit\n";

		cout << "Input your choose: ";
		cin >> answer;

		if (isCinError()) answer = -1;

		switch (answer)
		{
		case 1: {
			string name, DOB;
			double gpa;
			cout << "Input student's name: ";
			cin >> name;
			cout << "Input student's DOB (dd.mm.yyyy): ";
			cin >> DOB;
			cout << "Input student's GPA: ";
			cin >> gpa;
			try {
				manager.addStudent(name, DOB, gpa);
			}
			catch (invalid_argument& ex)
			{
				cout << "Error to creating student: " << ex.what() << endl;
			}
			break;
		}
		case 2:
		{
			cout << "Input student's ID: ";
			int id;
			cin >> id;
			manager.delStudent(id);
			break;
		}
		case 3: {
			manager.printAll();
			break;
		}
		case 4: {
			int sortBy;
			cout << "Do ypu want to sort student by (id/name/DOB/gpa)? ";
			cin >> sortBy;
			manager.sortStudents(sortBy);
		}

		case 0: {
			cout << "Bye!" << endl;
			return 0;
		}
		case 5: {
			manager.readFromTxt();
			break;
		}
		case 6: {
			manager.saveToTxt();
			break;
		}
		case -1:
			cout << "Try again" << endl;
		default:
			break;
		}
		if (isCinError()) {}
	}
}