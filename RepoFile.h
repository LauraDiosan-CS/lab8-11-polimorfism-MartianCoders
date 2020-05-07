#pragma once
#include "Objects.h"
#include <string>
#include <vector>

using namespace std;

template<class T>
class Repository {
protected:
	vector<T*> produse;
	string fileName;
public:
	Repository() {}
	Repository(string fileName) {
		this->setFileName = fileName;
	}
	~Repository() {}
	void setFileName(string fileName) {
		this->fileName = fileName;
	}

	vector<T*> getAll() {
		return this->produse; 
	}
	int getSize() {
		return this->produse.size();
	}
	T* getProdus(int pos) {
		if (pos >= 0 && pos < this->getSize())
		{
			return this->produse[pos]->clone();
		}
		return new T();
	}
	void add(T* p) {
		this->produse.push_back(p->clone());
		this->saveToFile();
	}

	void update(T* pVechi, T* pNou) {
		for (int i = 0; i < this->produse.size(); i++)
		{
			if (*(this->getProdus(i)) == *pVechi)
			{
				delete this->produse[i];
				this->produse[i] = pNou->clone();
				this->saveToFile();
				return;
			}
		}
	}
	void deleteP(T* p) {
		for (int i = 0; i < this->produse.size(); i++)
		{
			if (**(this->produse.begin() + i) == *p)
			{
				delete this->produse[i];
				this->produse.erase(this->produse.begin() + i);
				this->saveToFile();
				return;
			}
		}
	}

	void emptyRepo() {
		for (int i = 0; i < this->getSize(); i++)
		{
			delete this->produse[i];
		}
		this->produse.clear();
	}

	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
};


