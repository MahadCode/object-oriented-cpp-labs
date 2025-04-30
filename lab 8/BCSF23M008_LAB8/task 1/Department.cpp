#include "Department.h"

Department::Department()
    : Entity(), projectCount(0), projectCapacity(2) {
    projects = new Project * [projectCapacity];
}

Department::Department(int id, const string& name)
    : Entity(id, name), projectCount(0), projectCapacity(2) {
    projects = new Project * [projectCapacity];
}

Department::~Department(){
    for (int i = 0; i < projectCount; i++) {
        delete[] projects[i];
    }
    delete[] projects;
}

double Department::calculateEfficiency() const {
    double totalProgress = 0;
    for (int i = 0; i < projectCount; i++) {
        totalProgress += projects[i]->calculateProgress();
    }
    return (totalProgress / projectCount);
}

void Department::addProject(Project* project) {
    if (projectCount == projectCapacity) {
        expandCapacity();
    }
    projects[projectCount] = project;
    projectCount++;
}

void Department::removeProject(int projectId) {
    for (int i = 0; i < projectCount; i++) {
        if (projects[i]->getId() == projectId) {
            delete projects[i];
            for (int j = i; j < projectCount - 1; j++) {
                projects[j] = projects[j + 1];
            }
            projectCount--;
            break;
        }
    }
}

void Department::expandCapacity() {
    projectCapacity *= 2;
    Project** newProjects = new Project * [projectCapacity];
    for (int i = 0; i < projectCount; i++) {
        newProjects[i] = projects[i];
    }
    delete[] projects;
    projects = newProjects;
}

void Department::displayDetails() const {
    cout << "Department ID: " << getId() << ", Name: " << getName() << endl;
    cout << "Department Efficiency: " << calculateEfficiency() << endl;
    cout << "Projects in Department: " << projectCount << endl << endl;
    for (int i = 0; i < projectCount; i++) {
        projects[i]->displayDetails();
    }
}

void Department::saveToFile(ofstream& out) const {
    out << getId() << " " << getName() << " " << projectCount << endl;
    cout << "Saving Department: " << getName() << endl;
    for (int i = 0; i < projectCount; i++) {
        cout << "Saving project " << i + 1 << " of " << projectCount << endl;
        projects[i]->saveToFile(out);
    }
    cout << "Department has Saved" << endl << endl;
}

void Department::loadFromFile(ifstream& in) {
    reset();
    int id;
    string name;
    in >> id >> name;
    setId(id);
    setName(name);
    int tempProjectCount;
    in >> tempProjectCount;
    cout << "Loading Department: " << getName() << endl;
    for (int i = 0; i < tempProjectCount; i++) {
        cout << "Loading project " << i + 1 << " of " << tempProjectCount << endl;
        Project* project = new Project;
        project->loadFromFile(in);
        addProject(project);
    }
}

void Department::reset() {
    projectCount = 0;
    projectCapacity = 0;
    delete[] projects;
    projects = new Project * [projectCapacity];
}