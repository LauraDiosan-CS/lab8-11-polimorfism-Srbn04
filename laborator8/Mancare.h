#pragma once
#include<iostream>
#include "Comanda.h"
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

class Mancare : public Comanda {
private:
	string lista;
	char* nume;
	char* adresa;
	int pret;

public:
	Mancare();
	Mancare(const char* nume, const char* adresa, string lista,int  pret);
	~Mancare();
	Mancare(const Mancare& m);
	string getListaPreparate();
	Mancare& operator=(const Mancare& m);
	friend ostream& operator<<(ostream& os, const Mancare& m);

};