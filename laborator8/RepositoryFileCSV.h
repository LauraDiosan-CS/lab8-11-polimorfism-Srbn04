#pragma once
#include<string>
#include "RepositoryFile.h"

template <class T> class RepositoryCSV : public RepositoryFile<T>
{
public:
	RepositoryCSV(const char* fisier) :RepositoryFile<T>(fisier) {};
	~RepositoryCSV() {};
	void saveToFile();
	void loadFromFile();
};

template <class T> void RepositoryCSV<T> ::saveToFile()
{
	ofstream f(this->fisier);
	typename map<int, T>::iterator it;
	for (it = this ->elements.begin(); it != this->elements.end(); it++)
		f <<it->second << endl;
}


template <class T> void RepositoryCSV<T> ::loadFromFile()
{
	ifstream fileName(this->fisier);
	this->elements.clear();
	this->c = 0;
	string linie;
	while (getline(fileName, linie))
	{
		T object(linie, ',');
		this->elements.insert(pair<int, T>(this->c++, object));
	}
}
