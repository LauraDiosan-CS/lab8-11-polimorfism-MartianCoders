#include <iostream>
#include <crtdbg.h>

#include "tests.h"
#include "UI.h"
#include "ControllerDrug.h"
#include "RepositoryDrug.h"
#include "RepositoryEmployee.h"
#include "ControllerEmployee.h"
#include "Validator.h"
#include <filesystem>
namespace fs = std::filesystem;

void allFilesFolder() {
	std::cout << "Files in folder: " << '\n';
	std::string path = "D:/C++/lab8-11";
	for (auto& entry : fs::directory_iterator(path)) {
		std::string pat = entry.path().string();
		pat.erase(0, 15);
		if (pat != "tests.txt")
			if (pat.find(".txt") != std::string::npos || pat.find(".csv") != std::string::npos)
				std::cout << pat << std::endl;
	}
}

int main() {
	test_all();
	/*
	std::string employeeFile;
	std::string drugsFile;

	allFilesFolder();

	std::cout << '\n' << "Employee file: ";
	std::getline(std::cin, employeeFile);
	std::cout << "Drugs file: ";
	std::getline(std::cin, drugsFile);
	std::cout << '\n';

	Validator val;
	if (val.fileChecker(employeeFile, drugsFile) == true) {
		RepositoryDrug storageDrugs(drugsFile);
		RepositoryEmployee storageEmployee(employeeFile);
		ControllerDrug controllerDrug(storageDrugs);
		ControllerEmployee controllerEmployee(storageEmployee);

		UI ui(controllerDrug, controllerEmployee);
		ui.showLogin();
	}
	else
		std::cout << "Wrong file input, retryx";
		*/
	_CrtDumpMemoryLeaks();
}