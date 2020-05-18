#include "Mancare.h"
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

Mancare::Mancare()
{
	this->nume = "";
	this->adresa = "";
	this->listaPrep = "";
	this->pret = 0;
}
Mancare::Mancare(string nume, string adresa, string lista, int pret): Comanda(nume,adresa,pret)
{
	listaPrep = lista;
}
Mancare::~Mancare()
{
}

Mancare::Mancare(string line, char delim) {
	vector<string> elements = splitLine(line, delim);
	this->nume = elements[0];
	this->adresa = elements[1];
	this->listaPrep= elements[2];
	this->pret = stoi(elements[3]);
}


string Mancare::toStringCSV() {

	string outstring;

	outstring = Comanda::toStringCSV();
	vector<string>lista = this->listaPrep;
	outstring += ",";
	for (unsigned int i = 0; i < lista.size(); i++)
	{
		outstring += lista[i];

		if (i < lista.size() - 1)
		{
			outstring += " ";
		}
	}
	return outstring;
}

Mancare::Mancare(const Mancare& m): Comanda(m)
{
	this->listaPrep = m.listaPrep;
}
string Mancare::getListaPreparate() 
{
	return this->listaPrep;
}

Mancare& Mancare::operator=(const Mancare& m)
{
	this->nume = m.nume;
	this->adresa = m.adresa;
	this->listaPrep = m.listaPrep;
	this->pret = m.pret;
	return *this;
}


ostream& operator<<(ostream& os, const Mancare& m)
{
	os << "Numele: " << m.nume << endl;
	os << "Adresa: " << m.adresa << endl;
	os << "Lista: " << m.listaPrep << endl;
	os << "Pretul: " << m.pret << endl;
	os << endl;
	//os << "Numele: " << m.nume << " Adresa: " << m.adresa << " Pretul: " << m.pret;
	return os;
}