#include <assert.h>
#include <sstream>
#include <iostream>

#include "tests.h"
#include "Objects.h"
#include "Repository.h"
#include "RepositoryDrug.h"
#include "RepositoryEmployee.h"
#include "ControllerDrug.h"
#include "ControllerEmployee.h"
#include "UI.h"

void test_employee() {
	Employee e;
	Employee ee(e);
	Employee e1(1, "Teodor", "info.teodor@gmail.com", 5);
	assert(e1.getID() == 1);
	assert(e1.getName() == "Teodor");
	assert(e1.getEmail() == "info.teodor@gmail.com");
	assert(e1.getGrade() == 5);
	Employee e2(2, "Andrei", "andrei@gmail.com", 2);
	assert(e1 == e2 == false);
	assert(e1 != e2 == true);
	e1 = e2;
	assert(e1 == e2 == true);
	assert(e1 != e2 == false);
	std::stringstream string;
	string << e1;
	assert(string.str() == "2 Andrei andrei@gmail.com 2");
}

void test_Medicament() {
	Medicament d;
	Medicament dd(d);
	Medicament d1(1, "Paracetamol", false, 50, "RoFarm");
	assert(d1.getID() == 1);
	assert(d1.getName() == "Paracetamol");
	assert(d1.getRecipe() == false);
	assert(d1.getStock() == 50);
	assert(d1.getProducer() == "RoFarm");
	Medicament d2(2, "Ospen", true, 25, "Bayer");
	assert(d1 == d2 == false);
	assert(d1 != d2 == true);
	d1 = d2;
	assert(d1 == d2 == true);
	assert(d1 != d2 == false);
	std::stringstream string;
	string << d1;
	assert(string.str() == "2 Ospen true 25 Bayer");
}

void test_repoMedicament() {
	RepositoryDrug storageMedicaments("tests.txt");
	Medicament d1(1, "Paracetamol", false, 50, "RoFarm");
	storageMedicaments.addElement(d1);
	assert(storageMedicaments.getSize() == 1);
	assert(storageMedicaments.getAll()[0] == d1);
	storageMedicaments.deleteElement(d1);
	assert(storageMedicaments.getSize() == 0);
}

void test_repoEmployee() {
	RepositoryEmployee storageEmployee("tests.txt");
	Employee e1(1, "Teodor", "info.teodor@gmail.com", 5);
	storageEmployee.addElement(e1);
	assert(storageEmployee.getSize() == 1);
	assert(storageEmployee.getAll()[0] == e1);
	storageEmployee.deleteElement(e1);
	assert(storageEmployee.getSize() == 0);
}

void test_contMedicament() {
	MedicineService controllerMedicamentTest;
	RepositoryDrug storageMedicaments("tests.txt");
	MedicineService controllerMedicament(storageMedicaments);
	Medicament d1(1, "Paracetamol", false, 50, "RoFarm");
	Medicament d2(1, "Nurofen", true, 25, "Ro");
	controllerMedicament.add(d1);
	controllerMedicament.add(d2);
	assert(controllerMedicament.getSize() == 1);
	assert(controllerMedicament.getAll()[0] == d1);
	controllerMedicament.update(d1, d2);
	assert(controllerMedicament.getAll()[0] == d2);
	
	std::string medicament = "nuro";
	std::vector<Medicament> result = controllerMedicament.search(medicament);
	for (int i = 0; i < result.size(); i++)
		assert(result[i].getName() == "Nurofen");
	controllerMedicament.dell(1);
	assert(controllerMedicament.getSize() == 0);
}

void test_contEmployee() {
	ControllerEmployee controllerEmployeeTest;
	RepositoryEmployee storageEmployee("tests.txt");
	ControllerEmployee controllerEmployee(storageEmployee);
	Employee e1(1, "Teodor", "info.teodor@gmail.com", 5);
	Employee e2(1, "Andrei", "andrei@gmail.com", 3);
	controllerEmployee.add(1, "Teodor", "info.teodor@gmail.com", 5);
	controllerEmployee.add(1, "Andrei", "andrei@gmail.com", 3);
	assert(controllerEmployee.getSize() == 1);
	assert(controllerEmployee.getAll()[0] == e1);
	controllerEmployee.update(1, "Andrei", "andrei@gmail.com", 3);
	assert(controllerEmployee.getAll()[0] == e2);
	assert(controllerEmployee.changeGrade(1, 2, 6) == true);
	assert(controllerEmployee.changeGrade(1, 6, 1) == false);
	controllerEmployee.dell(1);
	assert(controllerEmployee.getSize() == 0);
}

void test_login() {
	RepositoryEmployee testStorageEmpl("tests.txt");
	RepositoryDrug testStorageMedicament("tests.txt");
	MedicineService contrMedicament(testStorageMedicament);
	ControllerEmployee contrEmp(testStorageEmpl);
	UI ui(contrMedicament, contrEmp);
	Employee e1(1, "Teodor", "info.teodor@gmail.com", 10);
	Employee e2(0, "", "", 0);
	contrEmp.add(1, "Teodor", "info.teodor@gmail.com", 10);
	assert(contrEmp.checkDataLogin("info.teodor@gmail.com", "info.teodor") == e1);
	assert(contrEmp.checkDataLogin("info.teodor@gmail.com", "da") == e2);
	contrEmp.dell(1);
}

void test_lab() {
	RepositoryDrug repoMedicament;
	MedicineService service(repoMedicament);
	Medicament m1(100, "parasinus", false, 10, "p1");
	Medicament m2(200, "ketonal", false, 90, "p2");
	Medicament m3(300, "antibiotic", true, 70, "p3");

	service.add(m1);
	service.add(m2);
	assert(service.getAll().size() == 2);
	assert(service.getAll()[0] == m1);
	assert(service.getAll()[1] == m2);
	service.add(m3);
	assert(service.getAll()[2] == m3);

	assert(service.search("ic").size() == 1);
	assert(service.search("a").size() == 3);

	Medicament m1_new(100, "altceva", false, 50, "p1");
	service.update(m1, m1_new);
	assert(service.search("al").size() == 2);
	assert(service.search("al")[0] == m1_new);
	assert(service.search("al")[1] == m2);
	service.dell(200);
	assert(service.search("al").size() == 1);
	assert(service.search("al")[0] == m1_new);
}

void test_all() {
	test_employee();
	test_Medicament();
	test_repoMedicament();
	test_repoEmployee();
	test_contMedicament();
	test_contEmployee();
	test_login();
	test_lab();
}