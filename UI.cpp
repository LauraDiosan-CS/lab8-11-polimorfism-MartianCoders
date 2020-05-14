#include "UI.h"
#include "RepositoryDrug.h"
#include "RepositoryEmployee.h"
#include "ControllerDrug.h"
#include "ControllerEmployee.h"
#include "Validator.h"
#include "MyExceptions.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

UI::UI() {}

UI::UI(const MedicineService& cd, const ControllerEmployee& ce) {
	this->MedicineServices = cd;
	this->controllerEmployee = ce;
}

UI::~UI() {}

void UI::showMenu() {
	std::cout << "Type:" << '\n';
	std::cout << "--------------------------" << '\n';
	std::cout << "employee | Employee menu" << '\n';
	std::cout << "drugs    | Drugs menu"<< '\n';
	std::cout << "--------------------------" << '\n';
	std::cout << "find     | Search for drugs {drug}" << '\n';
	std::cout << "change   | Change employee grade {ID} {newGrade}" << '\n';
	std::cout << "users    | Show all users" << '\n';
}

void UI::showEmployeeMenu() {
	std::cout << "(Employee) Type:" << '\n';
	std::cout << "--------------------------" << '\n';
	std::cout << "show    | Show all employee" << '\n';
	std::cout << "add     | Add Employee ({ID} {name} {email} {grade})" << '\n';
	std::cout << "update  | Update Employee ({ID to change} {name} {email} {grade})" << '\n';
	std::cout << "delete  | Delete Employee" << '\n';
	std::cout << "--------------------------" << '\n';
}

void UI::showDrugsMenu() {
	std::cout << "(Drugs) Type:" << '\n';
	std::cout << "--------------------------" << '\n';
	std::cout << "show    | Show all drugs" << '\n';
	std::cout << "add     | Add Employee ({ID} {name} {recipe true/false} {stock} {producer})" << '\n';
	std::cout << "update  | Update Drugs ({ID to change} {name} {recipe true/false} {stock} {producer})" << '\n';
	std::cout << "delete  | Delete Drugs" << '\n';
	std::cout << "--------------------------" << '\n';
}

void UI::showLogin() {
	std::cout << "============================" << '\n';
	std::cout << "User: ";
	std::string userToCheck;
	std::getline(std::cin, userToCheck);
	if (userToCheck != "exit") {
		std::cout << "Password: ";
		std::string passwordToCheck;
		std::getline(std::cin, passwordToCheck);
		std::cout << "============================";
		this->login(userToCheck, passwordToCheck);
	}
}

void UI::login(std::string userToCheck, std::string passwordToCheck) {
	Employee e1 = this->controllerEmployee.checkDataLogin(userToCheck, passwordToCheck);
	if (e1 != Employee(0, "", "", 0)) {
		std::cout << '\n' << "Login successful!" << '\n' << '\n';
		this->userGrade = e1.getGrade();
		this->usersStorage.push_back(e1);
		this->menu();
	}
	else {
		std::cout << '\n' << "Wrong data input!" << '\n';
		this->showLogin();
	}
}

void UI::showAllE() {
	std::vector<Employee> elements = this->controllerEmployee.getAll();

	for (int i = 0; i < elements.size(); i++)
		std::cout << elements[i] << std::endl;
}

void UI::showAllD() {
	std::vector<Medicament> elements = this->MedicineServices.getAll();

	for (int i = 0; i < elements.size(); i++)
		std::cout << elements[i] << std::endl;
}

void UI::addE(std::string cmd) {
	std::vector<std::string> strings;

	std::string token;
	std::string sep = " ";
	size_t pos = cmd.find(sep);

	for (int i = 0; i < 4; i++) {
		cmd.erase(0, pos + sep.length());
		pos = cmd.find(sep);
		token = cmd.substr(0, pos);
		strings.push_back(token);
	}

	Validator val;
	try {
		val.employeeValidator(strings);

		int ID = stoi(strings[0]);
		int grade = stoi(strings[3]);

		this->controllerEmployee.add(ID, strings[1], strings[2], grade);
	}
	catch (MyExceptions exc) {
		std::cout << exc.getMessage() << '\n';
	}
}

void UI::addD(std::string cmd) {
	std::vector<std::string> strings;
	bool recipe = false;

	std::string token;
	std::string sep = " ";
	size_t pos = cmd.find(sep);

	for (int i = 0; i < 5; i++) {
		cmd.erase(0, pos + sep.length());
		pos = cmd.find(sep);
		token = cmd.substr(0, pos);
		strings.push_back(token);
	}

	Validator val;
	try {
		val.drugsValidator(strings);

		int ID = stoi(strings[0]);
		if (strings[2] == "true")
			recipe = true;
		int stock = stoi(strings[3]);

		Medicament med(ID, strings[1], recipe, stock, strings[4]);
		this->MedicineServices.add(med);
	}
	catch (MyExceptions exc) {
		std::cout << exc.getMessage() << '\n';
	}
}

void UI::updateE(std::string cmd) {
	std::vector<std::string> strings;

	std::string token;
	std::string sep = " ";
	size_t pos = cmd.find(sep);

	for (int i = 0; i < 4; i++) {
		cmd.erase(0, pos + sep.length());
		pos = cmd.find(sep);
		token = cmd.substr(0, pos);
		strings.push_back(token);
	}

	Validator val;
	try {
		val.employeeValidator(strings);

		int ID = stoi(strings[0]);
		int grade = stoi(strings[3]);

		this->controllerEmployee.update(ID, strings[1], strings[2], grade);
	}
	catch (MyExceptions exc) {
		std::cout << exc.getMessage() << '\n';
	}
}

void UI::updateD(std::string cmd) {
	std::vector<std::string> strings;
	bool recipe = false;

	std::string token;
	std::string sep = " ";
	size_t pos = cmd.find(sep);

	for (int i = 0; i < 5; i++) {
		cmd.erase(0, pos + sep.length());
		pos = cmd.find(sep);
		token = cmd.substr(0, pos);
		strings.push_back(token);
	}

	Validator val;
	try {
		val.drugsValidator(strings);

		int ID = stoi(strings[0]);
		if (strings[2] == "true")
			recipe = true;
		int stock = stoi(strings[3]);

		Medicament med1(ID, "", false, 0, "");
		Medicament med2(ID, strings[1], recipe, stock, strings[4]);

		this->MedicineServices.update(med1, med2);
	}
	catch (MyExceptions exc) {
		std::cout << exc.getMessage() << '\n';
	}
}

void UI::delE(std::string cmd) {
	std::string token;
	std::string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	
	Validator val;
	try {
		val.deleteValidator(token);

		int ID = stoi(token);
		this->controllerEmployee.dell(ID);
	}
	catch (MyExceptions exc) {
		std::cout << exc.getMessage() << '\n';
	}
}

void UI::delD(std::string cmd) {
	std::string token;
	std::string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);

	Validator val;
	try {
		val.deleteValidator(token);

		int ID = stoi(token);
		this->MedicineServices.dell(ID);
	}
	catch (MyExceptions exc) {
		std::cout << exc.getMessage() << '\n';
	}
}

void UI::find(std::string cmd) {
	std::string token;
	std::string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);

	Validator val;
	try {
		val.drugSearchValidator(token);

		std::vector<Medicament> result = this->MedicineServices.search(token);
		for (int i = 0; i < result.size(); i++)
			std::cout << result[i] << '\n';
	}
	catch (MyExceptions exc) {
		std::cout << exc.getMessage() << '\n';
	}
}

void UI::change(std::string cmd) {
	std::vector<std::string> strings;

	std::string token;
	std::string sep = " ";
	size_t pos = cmd.find(sep);

	for (int i = 0; i < 4; i++) {
		cmd.erase(0, pos + sep.length());
		pos = cmd.find(sep);
		token = cmd.substr(0, pos);
		strings.push_back(token);
	}

	Validator val;
	try {
		val.changeGradeValidator(strings);

		int ID = stoi(strings[0]);
		int newGrade = stoi(strings[1]);

		if (this->controllerEmployee.changeGrade(ID, newGrade, this->userGrade))
			std::cout << '\n' << "Change successful!" << '\n';
		else
			std::cout << '\n' << "User not found/Employee grade > user Grade" << '\n';
	}
	catch (MyExceptions exc) {
		std::cout << exc.getMessage() << '\n';
	}
}

void UI::users() {
	for (int i = 0; i < this->usersStorage.size(); i++)
		std::cout << usersStorage[i] << '\n';
}

void UI::employeeMenu() {
	bool exit = false;
	std::string cmd;

	while (exit == false) {
		this->showEmployeeMenu();
		std::getline(std::cin, cmd);
		if (cmd.find("show") != std::string::npos)
			this->showAllE();
		if (cmd.find("add") != std::string::npos)
			this->addE(cmd);
		if (cmd.find("update") != std::string::npos)
			this->updateE(cmd);
		if (cmd.find("delete") != std::string::npos)
			this->delE(cmd);
		if (cmd.find("exit") != std::string::npos) {
			break;
			this->menu();
		}
	}
}

void UI::drugsMenu() {
	bool exit = false;
	std::string cmd;

	while (exit == false) {
		this->showDrugsMenu();
		std::getline(std::cin, cmd);
		if (cmd.find("show") != std::string::npos)
			this->showAllD();
		if (cmd.find("add") != std::string::npos)
			this->addD(cmd);
		if (cmd.find("update") != std::string::npos)
			this->updateD(cmd);
		if (cmd.find("delete") != std::string::npos)
			this->delD(cmd);
		if (cmd.find("exit") != std::string::npos) {
			break;
			this->menu();
		}
	}
}

void UI::menu() {
	bool exit = false;
	std::string cmd;

	while (exit == false) {
		this->showMenu();
		std::getline(std::cin, cmd);
		if (cmd.find("employee") != std::string::npos)
			this->employeeMenu();
		if (cmd.find("drugs") != std::string::npos)
			this->drugsMenu();
		if (cmd.find("find") != std::string::npos)
			this->find(cmd);
		if (cmd.find("change") != std::string::npos)
			this->change(cmd);
		if (cmd.find("users") != std::string::npos)
			this->users();
		if (cmd.find("logout") != std::string::npos) {
			this->showLogin();
			break;
		}
			
	}
}