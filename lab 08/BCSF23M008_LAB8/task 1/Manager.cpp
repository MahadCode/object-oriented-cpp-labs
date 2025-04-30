#include "Manager.h"

Manager::Manager() : Employee() {
    teamSize = 0;
}

Manager::Manager(int id, const string& name, double baseSalary, int skillLevel, int teamSize)
    : Employee(id,name,baseSalary,skillLevel), teamSize(teamSize) {
    
}

double Manager::calculateSalary() const {
    return getBaseSalary() + (getTeamSize() * 500);
}

void Manager::displayDetails() const {
    cout << "ID: " << getId() << ", Name: " << getName() << ", Base Salary: " << getBaseSalary()
        << ", Skill Level: " << getSkillLevel() << ", Team Size: " << getTeamSize() << endl;
}

void Manager::saveToFile(ofstream& out) const {
    if (out.is_open()) {
        out << getId() << " " << getName() << " " << getBaseSalary() << " " << getSkillLevel() << " " << getTeamSize() << " ";
    }
    else {
        cerr << "Error: File is not open for writing!" << endl;
    }
}

void Manager::loadFromFile(ifstream& in) {
    if (in.is_open()) {
        int id;
        string name;
        double baseSalary;
        int skillLevel;
        int teamSize;

        in >> id >> name >> baseSalary >> skillLevel >> teamSize;

        setId(id);
        setName(name);
        setBaseSalary(baseSalary);
        setSkillLevel(skillLevel);
        setTeamSize(teamSize);
    }
    else {
        cerr << "Error: File is not open for reading!" << endl;
    }
}


int Manager::getTeamSize() const {
    return teamSize;
}

void Manager::setTeamSize(int teamSize) {
    this->teamSize = teamSize;
}

