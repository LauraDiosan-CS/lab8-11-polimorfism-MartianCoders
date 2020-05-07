#pragma once
#include "RepoFile.h"

template<class T>
class RepositoryFileTXT : public Repository<T> {
public:
	RepositoryFileTXT() : Repository<T>() {}
	RepositoryFileTXT(string fileName) : Repository<T>(fileName) {}
	~RepositoryFileTXT() {}
	void loadFromFile() {
		ifstream f(this->fileName);
		if (f.is_open())
		{
			this->emptyRepo();
			string linie;
			string delim = " ";
			while (getline(f, linie))
			{
					linie = linie.erase(0, 3);

					int pos = linie.find(delim);
					int ID = stoi(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					string name = linie.substr(0, pos);
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					string s = linie.substr(0, pos);
					bool recipe = false;
					if (s == "true")
						bool recipe = true;
					else
						bool recipe = false;
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					int stock = stoi(linie.substr(0, pos));
					linie = linie.erase(0, pos + 1);

					pos = linie.find(delim);
					string producer = linie.substr(0, pos);

					Medicament* pd = new Medicament(ID, name, recipe, stock, producer);
					this->produse.push_back(pd);
			}
			f.close();
		}
	}
	void saveToFile() {
		ofstream f(this->fileName);
		if (f.is_open())
		{
			for (Medicament* elem : this->produse)
			{
				f << elem << endl;
			}
		}
	}
};