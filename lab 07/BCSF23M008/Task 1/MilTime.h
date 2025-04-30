#pragma once
#include "Time.h"
class MilTime : protected Time
{
    int milHours;
    int milSeconds;
public:
    MilTime(int, int);
    void setTime(int, int);
    void displayTime();
    int getHour();
    int getStandHr();
};

