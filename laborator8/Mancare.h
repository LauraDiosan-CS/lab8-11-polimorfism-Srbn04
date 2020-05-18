#pragma once
#include <iostream>
#include "Comanda.h"
#include <cstring>
#include <string>
using namespace std;

class Mancare : public Comanda {
private:
	string listaPrep;
public:
	Mancare();
	Mancare(string nume, string adresa, string lista,int  pret);
	~Mancare();
	Mancare(string line, char delim);
	Mancare(const Mancare& m);
	string getListaPreparate();
	string toStringCSV();
	Mancare& operator=(const Mancare& m);
	friend ostream& operator<<(ostream& os, const Mancare& m);

};