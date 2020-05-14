#pragma once
#include "ControllerDrug.h"
#include "ControllerEmployee.h"

class UI {
private:
	ControllerDrug controllerDrugs;
	ControllerEmployee controllerEmployee;
	std::vector<Employee> usersStorage;
	std::string user;
	int userGrade;
public:
	UI();
	UI(const ControllerDrug&, const ControllerEmployee&);
	~UI();

	/* Login */
	void showLogin();
	void login(std::string, std::string);
	bool checkData(std::string, std::string);

	/* Menu's*/
	void menu();
	void showMenu();
	void showEmployeeMenu();
	void showDrugsMenu();
	void employeeMenu();
	void drugsMenu();

	/* Commands | Employee */
	void showAllE();
	void addE(std::string);
	void updateE(std::string);
	void delE(std::string);

	/* Commands | Drugs */
	void showAllD();
	void addD(std::string);
	void updateD(std::string);
	void delD(std::string);

	/* Operations */
	void find(std::string);
	void change(std::string);
	void users();
};