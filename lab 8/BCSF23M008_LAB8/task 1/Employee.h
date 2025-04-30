#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include"Entity.h"

class Employee : public Entity
{
	double baseSalary;
	int skillLevel;
public:
	Employee();
	Employee(int, string,double, int);
	virtual double calculateSalary() const; //Compute total salary dynamically
	void displayDetails() const override;
	void saveToFile(ofstream&) const override;
	void loadFromFile(ifstream&) override;

	double getBaseSalary() const;
	void setBaseSalary(double baseSalary);

	int getSkillLevel() const;
	void setSkillLevel(int skillLevel);
};
#endif

