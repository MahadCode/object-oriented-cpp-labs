#pragma once
#include "Employee.h"
class Attendee :
    public Employee
{
    char** sessionDetails;
    int noSession;
public:
    Attendee();
    Attendee(int, char*, char*, int);
    void setSessions();
    void performRoleTask() override;
    void displayAttendee();
    void displayAll();
    ~Attendee();
};

