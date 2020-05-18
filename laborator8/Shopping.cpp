
#include "Shopping.h"
#include "Comanda.h"


Shopping::Shopping()
{
}


Shopping::Shopping(string name, string adresa, string lc, int pret, string mag) :Comanda(name,adresa,pret)
{
	listaCump = lc;
	magazin = mag;
}


Shopping::Shopping(const Shopping& s) :Comanda(s) {
	listaCump = s.listaCump;
	magazin = s.magazin;
}


Shopping::~Shopping() {
	
}

string Shopping::getMagazin() {
	return this->magazin;
}

string Shopping::getListaCumparaturi() {
	return this->listaCump;
}


Shopping& Shopping::operator=(const Shopping& a) {
	this->nume = a.nume;
	this->adresa = a.adresa;
	this->listaCump = a.listaCump;
	this->pret = a.pret;
	this->magazin = a.magazin;
	return *this;
}

bool Shopping:: operator==(const Shopping& a) {
	return this->nume == a.nume && this->adresa == a.adresa && this->pret == a.pret && this->listaCump == a.listaCump && this->magazin == a.magazin;
}


Shopping::Shopping(string line, char delim) {
	vector<string> elements = splitLine(line, delim);
	this->nume = elements[0];
	this->adresa = elements[1];
	this->listaCump = elements[2];
	this->pret = stoi(elements[3]);
	this->magazin = elements[4];
}


ostream& operator<<(ostream& os, const Shopping& a)
{
	os << "Numele: " << a.nume << endl;
	os << "Adresa: " << a.adresa << endl;
	os << "Lista: " << a.listaCump<< endl;
	os << "Pretul: " << a.pret << endl;
	os << "Magazin: " << a.magazin << endl;
	os << endl;
	return os;
}