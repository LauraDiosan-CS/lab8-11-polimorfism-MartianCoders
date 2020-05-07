#include "Objects.h"

Medicament::Medicament() {
	this->ID = 0;
	this->recipe = false;
	this->stock = 0;
}

Medicament::Medicament(int ID, std::string name, bool recipe, int stock, std::string producer) {
	this->ID = ID;
	this->name = name;
	this->recipe = recipe;
	this->stock = stock;
	this->producer = producer;
}

Medicament::Medicament(const Medicament& d) {
	this->ID = d.ID;
	this->name = d.name;
	this->recipe = d.recipe;
	this->stock = d.stock;
	this->producer = d.producer;
}

Medicament::~Medicament() {}

int Medicament::getID() {
	return this->ID;
}

std::string Medicament::getName() {
	return this->name;
}

bool Medicament::getRecipe() {
	return this->recipe;
}

int Medicament::getStock() {
	return this->stock;
}

std::string Medicament::getProducer() {
	return this->producer;
}

void Medicament::setID(int ID) {
	this->ID = ID;
}

void Medicament::setName(std::string name) {
	this->name = name;
}

void Medicament::setRecipe(bool recipe) {
	this->recipe = recipe;
}

void Medicament::setStock(int stock) {
	this->stock = stock;
}

void Medicament::setProducer(std::string prod) {
	this->producer = prod;
}

Medicament& Medicament::operator=(const Medicament& d) {
	this->setID(d.ID);
	this->setName(d.name);
	this->setRecipe(d.recipe);
	this->setStock(d.stock);
	this->setProducer(d.producer);
	return *this;
}

Medicament* Medicament::clone()
{
	return new Medicament(this->ID, this->name, this->recipe, this->stock, this->producer);
}

bool Medicament::operator==(const Medicament& d) const {
	if (this->ID == d.ID && this->name == d.name && this->recipe == d.recipe && this->stock == d.stock && this->producer == d.producer)
		return true;
	return false;
}

bool Medicament::operator!=(const Medicament& d) const {
	if (this->ID == d.ID && this->name == d.name && this->recipe == d.recipe && this->stock == d.stock && this->producer == d.producer)
		return false;
	return true;
}

std::ostream& operator<<(std::ostream& os, const Medicament& d) {
	os << d.ID << " " << d.name << " " << std::boolalpha << d.recipe << " " << d.stock << " " << d.producer;
	return os;
}
