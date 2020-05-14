#pragma once
#include "RepositoryDrug.h"

class MedicineService {
private:
	RepositoryDrug storageDrug;
public:
	/* Constructor & Destructor */
	MedicineService(); // Default
	MedicineService(const RepositoryDrug&); // Given Repository
	~MedicineService(); // Destructor

	/* CRUD's */
	void add(Medicament); // Add element (In: ID, name, recipe, stock, producer)
	void update(Medicament, Medicament); // Update element by ID (In: ID, name, recipe, stock, producer)
	void dell(int); // Delete element by ID (In: ID)

	/* Get's */
	std::vector<Medicament> getAll();
	int getSize();
	std::string getFile();

	/* Operations */
	std::vector<Medicament> search(std::string);
};