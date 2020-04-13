#pragma once
#include "Comanda.h" 
#include "Mancare.h" 
#include <map>
using namespace std;

template <class T> class Repo
{
protected:
	map<int, T> elements;
	int c;
public:
	Repo();
	Repo(const Repo& r);
	~Repo();
	void addElement(T& t);
	map<int, T>getAll();
	void deleteElement(int pos);
	int getSize();
};

