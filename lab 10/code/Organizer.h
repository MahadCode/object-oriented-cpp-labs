#pragma once
#include "Employee.h"
class Organizer :
    public Employee
{
    char* role;
    char** eventDetails;
    int noEvents;
public:
    Organizer();
    Organizer(int,  char*, char*, char*, int);
    void setEvents();
    void performRoleTask() override;
    void displayOrganizer();
    void displayAll();
    ~Organizer();
};

