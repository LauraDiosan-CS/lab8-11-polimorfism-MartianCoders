#include "ControllerDrug.h"

#include <algorithm>

MedicineService::MedicineService() {}

MedicineService::MedicineService(const RepositoryDrug& repo) {
	this->storageDrug = repo;
}

MedicineService::~MedicineService() {}

void MedicineService::add(Medicament medic) {
	std::vector<Medicament> drugs = this->storageDrug.getAll();
	bool exists = false;

	for (int i = 0; i < drugs.size(); i++)
		if (medic.getID() == drugs[i].getID())
			exists = true;
	if (exists == false) {
		this->storageDrug.addElement(medic);
	}
}

void MedicineService::update(Medicament m1, Medicament m2) {
	std::vector<Medicament> drugs = this->storageDrug.getAll();
	for(int i = 0; i < drugs.size(); i++)
		if(m1.getID() == drugs[i].getID())
			this->storageDrug.updateElement(m2);
}

void MedicineService::dell(int ID) {
	std::vector<Medicament> drugs = this->storageDrug.getAll();

	for(int i = 0; i < drugs.size(); i++)
		if(ID == drugs[i].getID())
			this->storageDrug.deleteElement(drugs[i]);
}

std::vector<Medicament> MedicineService::getAll() {
	return this->storageDrug.getAll();
}

int MedicineService::getSize() {
	return this->storageDrug.getSize();
}

std::vector<Medicament> MedicineService::search(std::string medic) {
	std::vector<Medicament> storageDrugs = this->storageDrug.getAll();
	std::vector<Medicament> result;
	for (int i = 0; i < storageDrugs.size(); i++) {
		std::string name = storageDrugs[i].getName();
		std::transform(name.begin(), name.end(), name.begin(), ::tolower);
		if (name.find(medic) != std::string::npos)
			result.push_back(storageDrugs[i]);
	}
	return result;
}