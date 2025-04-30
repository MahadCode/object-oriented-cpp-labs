#include<iostream>
#include <fstream>
#include <string>
#include "Employee.h"
#include "Manager.h"
#include "Project.h"
#include "Department.h"
using namespace std;

int main() {
    int numEmployees;
    cout << "Enter the number of employees to create: ";
    do {
        cin >> numEmployees;
    } while (numEmployees <= 0);


    for (int i = 0; i < numEmployees; ++i) {
        int id;
        string name;
        double baseSalary;
        int skillLevel;

        cout << "Enter details for employee " << i + 1 << endl;

        do {
            cout << "ID (must be > 0): ";
            cin >> id;
            if (id <= 0) {
                cout << "Invalid input. Please enter an ID greater than 0." << endl;
            }
        } while (id <= 0);

        cout << "Name: ";
        cin >> name;

        do {
            cout << "Base Salary (must be > 0): ";
            cin >> baseSalary;
            if (baseSalary <= 0) {
                cout << "Invalid input. Please enter a base salary greater than 0." << endl;
            }
        } while (baseSalary <= 0);

        do {
            cout << "Skill Level (must be > 0): ";
            cin >> skillLevel;
            if (skillLevel <= 0) {
                cout << "Invalid input. Please enter a skill level greater than 0." << endl;
            }
        } while (skillLevel <= 0);



        Employee tempEmployee(id, name, baseSalary, skillLevel);
        string fileName = "employee" + to_string(i + 1) + ".txt";
        ofstream outFile(fileName);
        if (outFile.is_open()) {
            tempEmployee.saveToFile(outFile);
            outFile.close();
        }
    }

    Employee** employees = new Employee * [numEmployees];
    for (int i = 0; i < numEmployees; ++i) {
        employees[i] = new Employee();

        string fileName = "employee" + to_string(i + 1) + ".txt";
        ifstream inFile(fileName);
        if (inFile.is_open()) {
            employees[i]->loadFromFile(inFile);
            inFile.close();
        }
    }

    int numProjects;
    cout << "Enter the number of projects to create: ";
    do{
        cin >> numProjects;
    } while (numProjects <= 0);
    

    for (int i = 0; i < numProjects; ++i) {
        int id;
        string name;
        double budget;
        int deadlineDays;

        do {
            cout << "Project ID (must be > 0): ";
            cin >> id;
        } while (id <= 0);

        cout << "Project Name: ";
        cin >> name;

        do {
            cout << "Project Budget (must be > 10000): ";
            cin >> budget;
        } while (budget <= 10000);

        do {
            cout << "Project Deadline Days (must be > 7): ";
            cin >> deadlineDays;
        } while (deadlineDays <= 7);

        Project tempProject(id, name, budget, deadlineDays);

        int choice;
        do {
            cout << "\nMenu for Project " << id << ":\n";
            cout << "1. Add Employee\n";
            cout << "2. Remove Employee\n";
            cout << "3. Save Project and Exit Menu\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                cout << "Enter Employee ID to add: ";
                int empId;
                cin >> empId;
                Employee* emp = nullptr;
                for (int j = 0; j < numEmployees; ++j) {
                    if (employees[j]->getId() == empId) {
                        emp = employees[j];
                        break;
                    }
                }
                if (emp) {
                    tempProject.addEmployee(emp);
                    cout << "Employee added successfully.\n";
                }
                else {
                    cout << "Employee not found.\n";
                }
            }
            else if (choice == 2) {
                cout << "Enter Employee ID to remove: ";
                int empId;
                cin >> empId;
                tempProject.removeEmployee(empId);
                cout << "Either Employee not existed or Employee removed successfully.\n";

            }
        } while (choice != 3);

        string fileName = "project" + to_string(i + 1) + ".txt";
        ofstream outFile(fileName);
        if (outFile.is_open()) {
            tempProject.saveToFile(outFile);
            outFile.close();
        }
    }

    Project** projects = new Project * [numProjects];
    for (int i = 0; i < numProjects; ++i) {
        projects[i] = new Project();
        string fileName = "project" + to_string(i + 1) + ".txt";
        ifstream inFile(fileName);
        if (inFile.is_open()) {
            projects[i]->loadFromFile(inFile);
            inFile.close();
        }
    }

    int numDepartments;
    cout << "Enter the number of departments to create: ";
    do {
        cin >> numDepartments;
    } while (numDepartments <= 0);

    for (int i = 0; i < numDepartments; i++) {
        int id;
        string name;

        do {
            cout << "Department ID (must be > 1): ";
            cin >> id;
        } while (id <= 1);

        cout << "Department Name: ";
        cin >> name;

        Department tempDepartment(id, name);

        int choice;
        do {
            cout << "\nMenu for Department " << id << ":\n";
            cout << "1. Add Project\n";
            cout << "2. Remove Project\n";
            cout << "3. Save Department and Exit Menu\n";
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == 1) {
                cout << "Enter Project ID to add: ";
                int projectId;
                cin >> projectId;
                Project* proj = nullptr;
                for (int j = 0; j < numProjects; ++j) {
                    if (projects[j]->getId() == projectId) {
                        proj = projects[j];
                        break;
                    }
                }
                if (proj) {
                    tempDepartment.addProject(proj);
                    cout << "Project added successfully.\n";
                }
                else {
                    cout << "Project not found.\n";
                }
            }
            else if (choice == 2) {
                cout << "Enter Project ID to remove: ";
                int projectId;
                cin >> projectId;
                tempDepartment.removeProject(projectId);
                cout << "Either Project was not existed or Project removed successfully.\n";
            }
        } while (choice != 3);

        string fileName = "department" + to_string(i + 1) + ".txt";
        ofstream outFile(fileName);
        if (outFile.is_open()) {
            tempDepartment.saveToFile(outFile);
            outFile.close();
        }
    };

    Department** departments = new Department*[numDepartments];
    for(int i = 0; i < numDepartments; i++) {
        departments[i] = new Department();
        string fileName = "department" + to_string(i + 1) + ".txt";
        ifstream inFile(fileName);
        if (inFile.is_open()) {
            departments[i]->loadFromFile(inFile);
            inFile.close();
        }
    }

    cout << "\nLoaded Department Details:\n";
    for (int i = 0; i < numDepartments; ++i) {
        departments[i]->displayDetails();
        delete departments[i];
    }

    for (int i = 0; i < numProjects; ++i) {
        delete projects[i];
    }
    for (int i = 0; i < numEmployees; ++i) {
        delete employees[i];
    }
    delete[] employees;
    delete[] projects;
    delete[] departments;

    return 0;
}
