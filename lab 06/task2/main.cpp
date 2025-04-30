#include<iostream>
#include"Course.h"
#include"Department.h"
using namespace std;

int check(int n) {
	if (n > 0) {
		return n;
	}
	else {
		int temp;
		while (true) {
			cin >> temp;
			if (temp > 0) {
				break;
			}
		}
		return temp;
	}
}

int main() {
	int noCourses;
	cout << "Enter number of Courses:" << endl;
	cin >> noCourses;
	noCourses = check(noCourses);
	Course* courses = new Course[noCourses];

	for (int i = 0; i < noCourses; i++) {
		cin >> courses[i];
	}

	for (int i = 0; i < noCourses; i++) {
		cout << courses[i];
	}

	int noDept;
	cout << "Enter number of Department:" << endl;
	cin >> noDept;
	noDept = check(noDept);
	Department* depts = new Department[noDept];

	for (int i = 0; i < noDept; i++) {
		cout << "Department " << i + 1 << ":" << endl;
		string name;
		cout << "Enter Department's Name:" << endl;
		cin >> name ;
		int n;
		cout << "Enter Number of Courses you want to add to Department:" << endl;
		cin >> n;
		while (true) {
			if (n<1 || n>noCourses) {
				cin >> n;
			}
			else {
				break;
			}
		}
		depts[i].setDept(name, n);
		cout << endl;
	}

	cout << "List of Department: " << endl;
	for (int i = 0; i < noDept; i++) {
		cout << i + 1 << "-  " << depts[i].getDeptName() << endl;
	}
	cout << endl;
	while (true) {
		int deptChoice;
		cout << "Select a department(from given range)" << endl;
		cout << "In which you want to add a course" << endl;
		cin >> deptChoice;
		if (deptChoice > 0 && deptChoice <= noDept) {
			cout << "List of Courses: " << endl;
			for (int i = 0; i < noCourses; i++) {
				cout << i + 1 << "-  " << courses[i].getCourseName() << endl;
			}
			int k = 0;
			while (k < depts[deptChoice-1].getNumCourses()) {
				int noC;
				cout << "Select a Course(from given range)" << endl;
				cin >> noC;
				if (noC > 0 && noC <= noCourses) {
					depts[deptChoice-1].addCourse(courses[noC-1]);
					cout << endl;
					k++;
				}
				else {
					cout << "Invalid Course Number";
					break;
				}
					
			}
			cout << endl;
		}
		else {
			break;
		}
		cout << endl;
	}

	cout << "List of Department: " << endl;
	for (int i = 0; i < noDept; i++) {
		cout << i + 1 << "-  " << depts[i].getDeptName();
	}
	while (true) {
		int deptChoice;
		cout << "Select a department(from given range)" << endl;
		cout << "You want to display:" << endl;
		cin >> deptChoice;
		if (deptChoice > 0 && deptChoice <= noDept) {
			cout << depts[deptChoice - 1];
		}
		else {
			break;
		}
	}

	cout << "Performing relational operators with first deptment" << endl;

	for (int i = 1; i < noDept; i++) {
		cout << "With Deptartment " << i + 1 << endl;
		bool ans = depts[0] < depts[i];
		cout << "Result of <" << ans << endl;
		ans = depts[0] > depts[i];
		cout << "Result of >" << ans << endl;
	    ans = depts[0] == depts[i];
		cout << "Result of ==" << ans << endl;
		cout << endl;
	}
}