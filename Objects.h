#pragma once

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <fstream>

class Employee {
private:
	int ID;
	std::string name;
	std::string email;
	int grade;
public:
	/* Constructors & Destructor */
	Employee(); // Default
	Employee(int, std::string, std::string, int); // Given data
	Employee(const Employee&); // Copy
	~Employee(); // Destructor

	/* Get's */
	int getID(); // Return ID (Out: ID)
	std::string getName(); // Return name (Out: name)
	std::string getEmail(); // Return email (Out: email)
	int getGrade(); // Return grade (Out: grade)

	/* Set's */
	void setID(int); // Set ID (In: ID)
	void setName(std::string); // Set Name (In: name)
	void setEmail(std::string); // Set Email (In: email)
	void setGrade(int); // Set grade (In: grade)

	/* Operator's */
	Employee& operator=(const Employee&);
	bool operator==(const Employee&) const;
	bool operator!=(const Employee&) const;
	friend std::ostream& operator<<(std::ostream&, const Employee&);
	friend std::istream& operator>>(std::istream& is, Employee&);


};

#endif // !EMPLOYEE_H

#ifndef DRUG_H
#define DRUG_H
#include <string>
#include <fstream>

class Medicament {
private:
	int ID;
	std::string name;
	bool recipe;
	int stock;
	std::string producer;
public:
	/* Constructor && Destructor */
	Medicament(); // Default
	Medicament(const Medicament&); // Copy
	Medicament(int, std::string, bool, int, std::string); // Given data (In: ID, name, recipe, stock, producer)
	~Medicament(); // Destructor

	/* Get's */
	int getID(); // Returns ID (Out: ID)
	std::string getName(); // Returns Name (Out: name)
	bool getRecipe(); // Returns recipe (Out: recipe)
	int getStock(); // Returns stock (Out: stock)
	std::string getProducer(); // Returns producer (Out: producer)

	/* Set's */
	void setID(int); // Set ID (In: ID)
	void setName(std::string); // Set name (In: name)
	void setRecipe(bool); // Set recipe (In: recipe)
	void setStock(int); // Set stock (In: stock)
	void setProducer(std::string); // Set producer (In: producer)

	/* Operator's */
	Medicament& operator=(const Medicament&);
	bool operator==(const Medicament&) const;
	bool operator!=(const Medicament&) const;
	friend std::ostream& operator<<(std::ostream&, const Medicament&);

};

#endif // !DRUG_H


