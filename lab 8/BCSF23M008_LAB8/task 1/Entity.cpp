#include "Entity.h"

Entity::Entity() {
    id = 0;
    name = "null";
}

Entity::Entity(int i, string n){
	id = i;
	name = n;
}

int Entity::getId() const {
    return id;
}

void Entity::setId(int id) {
    this->id = id;
}

string Entity::getName() const {
    return name;
}

void Entity::setName(const string& name) {
    this->name = name;
}
