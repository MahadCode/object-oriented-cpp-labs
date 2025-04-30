#ifndef ENTITY_H
#define ENTITY_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

class Entity
{
	int id; // Unique ID.
	string name; // Name of the entity.
public:
	Entity();
	Entity(int,string);
	virtual void displayDetails() const = 0; //Display entity details.
	virtual void saveToFile(ofstream&) const = 0; //Save entity data to a file.
	virtual void loadFromFile(ifstream&) = 0; // Load entity data from a file.
	/*virtual ~Entity();*/

	int getId() const;
	void setId(int id);

	string getName() const;
	void setName(const string& name);
};

#endif


