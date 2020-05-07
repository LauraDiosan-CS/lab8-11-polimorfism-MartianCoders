#include "RepoFileTXT.h"
#include <fstream>
#include "ProdusDulce.h"
#include "ProdusSarat.h"

RepoFileTXT::RepoFileTXT() : RepoFile()
{
}

RepoFileTXT::RepoFileTXT(string fileName) : RepoFile(fileName)
{
}

RepoFileTXT::~RepoFileTXT()
{
}

void RepoFileTXT::loadFromFile()
{
	ifstream f(this->fileName);
	if (f.is_open())
	{
		this->emptyRepo();
		string linie;
		string delim = " ";
		while (getline(f, linie))
		{
			if (linie.substr(0, 2) == "PD")
			{
				linie = linie.erase(0, 3);

				int pos = linie.find(delim);
				string nume = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				double pret = stod(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				string glazura = linie.substr(0, pos);

				ProdusDulce* pd = new ProdusDulce(nume, pret, glazura);
				this->produse.push_back(pd);
			}
			else if (linie.substr(0, 2) == "PS")
			{
				linie = linie.erase(0, 3);

				int pos = linie.find(delim);
				string nume = linie.substr(0, pos);
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				double pret = stod(linie.substr(0, pos));
				linie = linie.erase(0, pos + 1);

				pos = linie.find(delim);
				double cantitateSare = stod(linie.substr(0, pos));

				ProdusSarat* ps = new ProdusSarat(nume, pret, cantitateSare);
				this->produse.push_back(ps);
			}
		}
		f.close();
	}
}

void RepoFileTXT::saveToFile()
{
	ofstream f(this->fileName);
	if (f.is_open())
	{
		for (Produs* elem : this->produse)
		{
			f << elem->toString(" ") << endl;
		}
	}
}
