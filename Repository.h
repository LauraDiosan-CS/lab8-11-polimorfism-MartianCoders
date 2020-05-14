#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>


template <class T>
class Repository {
private:
	std::vector<T> storage;
protected:
	std::string fileName;
public:
	/* Constructor & Destructor */
	Repository() {} // Default
	~Repository() {} // Destructor

	/* CRUD's */
	void addElement(T t) {
		this->storage.push_back(t);
		this->saveFile();
	}

	void updateElement(T t) { // Update old element with a new one by obejct ID (In: object)
			for (unsigned int i = 0; i < this->storage.size(); i++)
				if (this->storage[i].getID() == t.getID()) {
					this->storage[i] = t;
					this->saveFile();
				}
	}

	void deleteElement(T t) { // Delete a Cookie element from storage (In: object COokie do delete)
		for (unsigned int i = 0; i < this->storage.size(); i++)
			if (this->storage[i] == t){
				this->storage[i] = this->storage[this->storage.size() - 1];
				this->storage.pop_back();
				this->saveFile();

			}
	}

	/* Save file*/
	void saveFile() { // Save datax
		if (this->fileName.size() > 0)
		{
			std::ofstream f(this->fileName);
			
			for (int i = 0; i < this->storage.size(); i++)
			{
				if (i == this->storage.size() - 1)
					f << this->storage[i];
				else
					f << this->storage[i] << std::endl;
			}
			f.close();
		}
	}

	/* Operations */
	void clear() {
		this->storage.clear();
	}

	int getSize() {
		return this->storage.size();
	}
	std::string getFile() {
		return this->fileName;
	}

	std::vector<T> getAll() {
		return this->storage;
	}

	virtual void loadFile() = 0;
};