#include "Project.h"
#include "Project.h"
#include <iostream>
#include <fstream>

using namespace std;

Project::Project()
    : Entity(), teamCount(0), teamCapacity(5), budget(0), deadlineDays(0) {
    team = new Employee * [teamCapacity];
}

Project::Project(int id,string name,double budget, int deadlineDays) 
    : Entity(id,name), budget(budget), deadlineDays(deadlineDays), teamCount(0), teamCapacity(5) {
    team = new Employee * [teamCapacity];
}

Project::~Project() {
    delete[] team;
}

void Project::expandCapacity() {
    teamCapacity *= 2;
    Employee** newTeam = new Employee * [teamCapacity];
    for (int i = 0; i < teamCount; i++) {
        newTeam[i] = team[i];
    }
    delete[] team;
    team = newTeam;
}

void Project::addEmployee(Employee* emp) {
    if (teamCount == teamCapacity) {
        expandCapacity();
    }
    team[teamCount] = emp;
    teamCount++;
}

void Project::removeEmployee(int empId) {
    for (int i = 0; i < teamCount; i++) {
        if (team[i]->getId() == empId) {
            delete team[i];
            for (int j = i; j < teamCount - 1; j++) {
                team[j] = team[j + 1];
            }
            teamCount--;
            return;
        }
    }
}

double Project::calculateProgress() const {
    double totalSkill = 0;
    for (int i = 0; i < teamCount; i++) {
        totalSkill += team[i]->getSkillLevel(); 
    }
    return (totalSkill / teamCount);
}

void Project::displayDetails() const {
    cout << "Project ID: " << getId() << ", Name: " << getName() << endl;
    cout << "Project Budget: " << budget << ", Deadline: " << deadlineDays
        << ", Team Count: " << teamCount << endl;
    cout << "Project Progress: " << calculateProgress() << endl;
    cout << "Employees in Project: " << teamCount << endl << endl;
    for (int i = 0; i < teamCount; i++)
    {
        team[i]->displayDetails();
    }
    cout << endl;
}

void Project::saveToFile(ofstream& out) const {
    out << getId() << " " << getName() << " " << budget << " " << deadlineDays << " " << teamCount << endl;
    for (int i = 0; i < teamCount; i++) {
        cout << "Saving employee " << i + 1 << " of " << teamCount << endl;
        team[i]->saveToFile(out);
    }
    cout << "Project has Saved" << endl << endl;
}

void Project::loadFromFile(ifstream& in) {
    reset();
    int id;
    string name;
    int tempTeamCount;
    in >> id >> name >> budget >> deadlineDays >> tempTeamCount;
    setId(id);
    setName(name);
    for (int i = 0; i < tempTeamCount; i++) {
        cout << "Loading employee " << i + 1 << " of " << tempTeamCount << endl;
        Employee* emp = new Employee;
        emp->loadFromFile(in);
        addEmployee(emp);
    }
}

void Project::reset() {
    teamCount = 0;
    teamCapacity = 5;
    delete[] team;
    team = new Employee * [teamCapacity];
    budget = 0;
    deadlineDays = 0;
}