#pragma once
#include "Repository.h"
#include "Objects.h"
#include <string>
#include <fstream>

class RepositoryDrug: public Repository<Medicament> {
public:
	RepositoryDrug() {};
	RepositoryDrug(std::string fileName) {
		this->fileName = fileName;
		this->loadFile();
	}
	~RepositoryDrug() {};

	/* Load file*/
	void loadFile() { // Load data
		if (this->fileName.size() > 0)
		{
			this->clear();
			std::ifstream f(this->fileName);
			int ID;
			std::string name;
			std::string producer;
			std::string boolean;
			bool recipe;
			int stock;
			while (!f.eof())
			{
				f >> ID >> name >> boolean >> stock >> producer;
				if (name.empty() == false)
				{
					if (boolean == "true")
						recipe = true;
					else
						recipe = false;
					this->addElement(Medicament(ID, name, recipe, stock, producer));
				}
			}

			f.close();
		}
	}
};