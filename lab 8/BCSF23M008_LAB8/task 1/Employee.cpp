#include "Employee.h"

Employee::Employee() :Entity() {
    baseSalary = 0;
    skillLevel = 0;
}

Employee::Employee(int ID, string n, double bSal, int skill) : Entity(ID, n) {
	baseSalary = bSal;
	skillLevel = skill;
}

double Employee::getBaseSalary() const {
    return baseSalary;
}

void Employee::setBaseSalary(double baseSalary) {
    this->baseSalary = baseSalary;
}

int Employee::getSkillLevel() const {
    return skillLevel;
}

void Employee::setSkillLevel(int skillLevel) {
    this->skillLevel = skillLevel;
}

double Employee::calculateSalary() const {
    const double skillMultiplier = 0.2;
    return baseSalary + (baseSalary * skillLevel * skillMultiplier);
}

void Employee::displayDetails() const {
    cout << "Employee ID: " << getId() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Base Salary: $" << baseSalary << endl;
    cout << "Skill Level: " << skillLevel << endl;
    cout << "Total Salary: $" << calculateSalary() << endl << endl;
}

void Employee::saveToFile(ofstream& out) const {
    if (out.is_open()) {
        out << getId() << " " << getName() << " " << baseSalary << " " << skillLevel << endl;
    } else {
        cerr << "Error: File is not open for writing!" << endl;
    }
}

void Employee::loadFromFile(ifstream& in) {
    if (in.is_open()) {
        int id;
        string name;
        double salary;
        int level;

        in >> id >> name >> salary >> level;

        setId(id);
        setName(name);
        baseSalary = salary;
        skillLevel = level;
    } else {
        cerr << "Error: File is not open for reading!" << endl;
    }
}