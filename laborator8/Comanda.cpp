#include "Comanda.h"
#include "Functions.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
using namespace std;

Comanda::Comanda() {
	this->nume = "";
	this->adresa ="";
	this->pret = 0;
}

Comanda::Comanda(string nume, string adresa, int pret)
{
	this->nume = nume;
	this->adresa = adresa;
	this->pret = pret;
}

Comanda::Comanda(const Comanda& a) {
	this->nume = a.nume;
	this->adresa = a.adresa;
	this->pret = a.pret;
}


string Comanda::getNume() {
	return this->nume;
}


string Comanda::getAdresa() {
	return this->adresa;
}


int Comanda::getPret() {
	return this->pret;
}


void Comanda::setNume(string nume)
{
	this->nume = nume;
}

void Comanda::setAdresa(string adresa)
{
	this->adresa = adresa;
}

void Comanda::setPret(int pret)
{
	this->pret = pret;
}

string Comanda::toStringCSV()
{
	string array = this->nume;
	float pret = this->pret;
	string adresaS = this->adresa;
	std::string numeClientS(array); // CONVERT CHAR* TO STRING
	std::string pretS = std::to_string(pret);
	vector<string> atr;
	atr.push_back(numeClientS);
	atr.push_back(adresaS);
	atr.push_back(pretS);
	string outstring;
	for (unsigned int i = 0; i < atr.size(); i++) {

		outstring += atr[i];
		if (i < atr.size() - 1) {

			outstring += ",";
		}
	}
	return outstring;

}

