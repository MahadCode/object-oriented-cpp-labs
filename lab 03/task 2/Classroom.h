#pragma once
#include<iostream>
#include<string>
using namespace std;

class Classroom
{
	int roomNumber;
	int capacity;
	static int classroomCount;
    public:
		Classroom();
		Classroom(int,int);
		void display();
		void setRoomNumber(int);
		void setCapacity(int);
		int getRoomNumber();
		int getCapacity();
		
		static void showClassroomCount();
};

