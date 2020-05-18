#pragma once
#include <ostream>
#include "Functions.h"
using namespace std;

class Comanda {
protected:
	string nume;
	string adresa;
	int pret;
public:
	Comanda();
	Comanda(string nume, string adresa, int pret);
	Comanda(const Comanda& c);
	~Comanda() {};
	virtual string getNume();
	virtual string  getAdresa();
	virtual int getPret();
	void setNume(string nume);
	void setAdresa(string adresa);
	void setPret(int  pret);
	string toStringCSV();
};