#include <assert.h>
#include <sstream>
#include <iostream>

#include "tests.h"
#include "Objects.h"
#include "RepoFile.h"
#include "RepoFileTXT.h"

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

void test_lab() {
	Repository<Medicament>* repo = new RepositoryFileTXT<Medicament>();
	Medicament* m1 = new Medicament(100, "parasinus", false, 10, "p1");
	Medicament* m2 = new Medicament(200, "ketonal", false, 90, "p2");
	Medicament* m3 = new Medicament(300, "antibiotic", true, 70, "p3");

	repo->add(m1);
	repo->add(m2);
	assert(repo->getAll().size() == 2);
	assert(*repo->getAll()[0] == *m1);
	assert(*repo->getAll()[1] == *m2);
	repo->add(m3);
	assert(*repo->getAll()[2] == *m3);

	Medicament m1_new(100, "paracetamol", false, 50, "p1");
	repo->update(m1, &m1_new);
	assert(*repo->getAll()[0] != *m1);
	assert(*repo->getAll()[0] == m1_new);

	repo->deleteP(m2);
	assert(repo->getAll().size() == 2);

}

void test_all() {
	test_employee();
	test_Medicament();
	test_lab();
}