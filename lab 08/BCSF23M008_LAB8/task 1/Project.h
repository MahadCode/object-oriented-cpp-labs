#ifndef PROJECT_H
#define PROJECT_H

#include "Employee.h"
#include "Entity.h"

class Project : public Entity {
private:
    double budget;
    int deadlineDays;
    Employee** team;
    int teamCount;
    int teamCapacity;
    void expandCapacity();
public:
    Project();
    Project(int,string,double,int);
    ~Project();
    void addEmployee(Employee* emp);
    void removeEmployee(int empId);
    double calculateProgress() const;
    void displayDetails() const override;
    void saveToFile(ofstream&) const override;
    void loadFromFile(ifstream&) override;
    void reset();
};
#endif
