#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include "Project.h"

class Department : public Entity {
private:
    Project** projects;
    int projectCount;
    int projectCapacity;
    void expandCapacity();
public:
    Department();
    Department(int,const string&);
    ~Department();
    double calculateEfficiency() const;
    void addProject(Project* project);
    void removeProject(int projectId);
    void displayDetails() const override;
    void saveToFile(ofstream&) const override;
    void loadFromFile(ifstream&) override;
    void reset();
};

#endif

