#include "Objects.h"
#include <cstddef>
#include <iostream>


Employee::Employee() {
	this->ID = 0;
	this->grade = 0;
}

Employee::Employee(int ID, std::string name, std::string email, int grade) {
	this->ID = ID;
	this->name = name;
	this->email = email;
	this->grade = grade;
}

Employee::Employee(const Employee& e) {
	this->ID = e.ID;
	this->name = e.name;
	this->email = e.email;
	this->grade = e.grade;
}

Employee::~Employee() {}

int Employee::getID() {
	return this->ID;
}

std::string Employee::getName() {
	return this->name;
}

std::string Employee::getEmail() {
	return this->email;
}

int Employee::getGrade() {
	return this->grade;
}

void Employee::setID(int ID) {
	this->ID = ID;
}

void Employee::setName(std::string name) {
	this->name = name;
}

void Employee::setEmail(std::string email) {
	this->email = email;
}

void Employee::setGrade(int grade) {
	this->grade = grade;
}

Employee& Employee::operator=(const Employee& e) {
	this->setID(e.ID);
	this->setName(e.name);
	this->setEmail(e.email);
	this->setGrade(e.grade);
	return *this;
}

bool Employee::operator==(const Employee& e) const {
	if (this->ID == e.ID && this->name == e.name && this->email == e.email && this->grade == e.grade)
		return true;
	return false;
}

bool Employee::operator!=(const Employee& e) const {
	if (this->ID == e.ID && this->name == e.name && this->email == e.email && this->grade == e.grade)
		return false;
	return true;
}

std::ostream& operator<<(std::ostream& os, const Employee& e) {
	os << e.ID << " " << e.name << " " << e.email << " " << e.grade;
	return os;
}



