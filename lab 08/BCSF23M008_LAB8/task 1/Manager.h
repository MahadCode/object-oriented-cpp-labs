#ifndef MANAGER_H
#define MANAGER_H
#include"Employee.h"

    class Manager : public Employee {
    private:
        int teamSize;
    public:
        Manager();
        Manager(int, const string& , double , int , int );
        double calculateSalary() const override;
        void displayDetails() const override;
        void saveToFile(ofstream&) const override;
        void loadFromFile(ifstream&) override;

        int getTeamSize() const;
        void setTeamSize(int teamSize);
    };


#endif

