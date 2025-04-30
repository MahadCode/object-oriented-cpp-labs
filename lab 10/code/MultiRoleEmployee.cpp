#include "MultiRoleEmployee.h"
MultiRoleEmployee::MultiRoleEmployee() :Speaker(), Organizer(), Attendee() {

}

MultiRoleEmployee::MultiRoleEmployee(int id, char* n, char* e, char* st, int sd, char* r, int ne, int ns) :
	Speaker(id, n, e, st, sd), Organizer(id, n, e, r, ne), Attendee(id, n, e, ns) {

}
   
void MultiRoleEmployee::displayAll() {
	Speaker::displayEmp();
	Speaker::performRoleTask();
	Attendee::performRoleTask();
	Organizer::performRoleTask();
}

template <typename T> void MultiRoleEmployee::assignRoleTask(const T& assign) {
	cout << "Assigning Task: " << assign << endl;
}