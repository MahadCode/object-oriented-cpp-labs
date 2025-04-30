#pragma once
#include "Employee.h"
class Speaker :
    public Employee
{
    char* sessionTopic;
    int sessionDuration;
public:
    Speaker();
    Speaker(int,char*,  char*,char*, int);
    void performRoleTask() override;
    void displaySpeaker();
    void displayAll();
    ~Speaker();
};

