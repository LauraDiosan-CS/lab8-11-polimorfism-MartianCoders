#pragma once
#include "RepositoryEmployee.h"

class ControllerEmployee {
private:
	RepositoryEmployee storageEmployee;
public:
	/* Constructor & Destructor */
	ControllerEmployee(); // Default
	ControllerEmployee(const RepositoryEmployee&); // Given Repository
	~ControllerEmployee(); // Destructor

	/* CRUD's */
	void add(int, std::string, std::string, int); // Add element (In: ID, name, email, grade)
	void update(int, std::string, std::string, int); // Update element by ID (In: ID, name, email, grade)
	void dell(int); // Delete element by ID (In: ID)

	/* Get's */
	std::vector<Employee> getAll();
	int getSize();
	std::string getFile();

	/* Operations */
	bool changeGrade(int, int, int);
	Employee checkDataLogin(std::string, std::string);
};