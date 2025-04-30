#pragma once
#include"Attendee.h"
#include"Speaker.h"
#include"Organizer.h"
class MultiRoleEmployee:  public Speaker,  public Organizer,  public Attendee
{
public:
	MultiRoleEmployee();
	MultiRoleEmployee(int, char*, char*, char*, int, char*, int, int);
	void displayAll();
	template <typename T> void assignRoleTask(const T& );
};

