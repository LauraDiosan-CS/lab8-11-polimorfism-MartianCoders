#include "ControllerEmployee.h"

ControllerEmployee::ControllerEmployee() {}

ControllerEmployee::ControllerEmployee(const RepositoryEmployee& repo) {
	this->storageEmployee = repo;
}

ControllerEmployee::~ControllerEmployee() {}

void ControllerEmployee::add(int ID, std::string name, std::string email, int grade) {
	std::vector<Employee> employee = this->storageEmployee.getAll();
	bool exists = false;

	for (int i = 0; i < employee.size(); i++)
		if (ID == employee[i].getID())
			exists = true;
	if (exists == false) {
		Employee e(ID, name, email, grade);
		this->storageEmployee.addElement(e);
	}
}

void ControllerEmployee::update(int ID, std::string name, std::string email, int grade) {
	Employee e(ID, name, email, grade);
	this->storageEmployee.updateElement(e);
}

void ControllerEmployee::dell(int ID) {
	std::vector<Employee> employee = this->storageEmployee.getAll();

	for (int i = 0; i < employee.size(); i++)
		if (ID == employee[i].getID())
			this->storageEmployee.deleteElement(employee[i]);
}

std::vector<Employee> ControllerEmployee::getAll() {
	return this->storageEmployee.getAll();
}

int ControllerEmployee::getSize() {
	return this->storageEmployee.getSize();
}

bool ControllerEmployee::changeGrade(int ID, int newGrade, int userGrade) {
	std::vector<Employee> employee = this->storageEmployee.getAll();

	for (int i = 0; i < employee.size(); i++)
		if (ID == employee[i].getID()) {
			if (userGrade > employee[i].getGrade()) {
				this->storageEmployee.updateElement(Employee(employee[i].getID(), employee[i].getName(), employee[i].getEmail(), newGrade));
				return true;
			}
		}
	return false;
}

Employee ControllerEmployee::checkDataLogin(std::string user, std::string pass)
{
	std::vector<Employee> storageEmployee = this->storageEmployee.getAll();
	std::string token;
	std::string sep = "@";

	for (int i = 0; i < storageEmployee.size(); i++)
		if (storageEmployee[i].getEmail() == user) {
			size_t pos = user.find(sep);
			token = user.substr(0, pos);
			user = token;
			if (user == pass) {
				return storageEmployee[i];
			}
		}	
	return Employee();
}
