#include "Comanda.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
using namespace std;

Comanda::Comanda() {
	this->name = NULL;
	this->adresa = NULL;
	this->pret = NULL;
}

Comanda::Comanda(const char* name, const char* adresa, int pret)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, 1 + strlen(name), name);
	this->adresa = new char[strlen(adresa) + 1];
	strcpy_s(this->adresa, 1 + strlen(adresa), adresa);
	this->pret = pret;
}

Comanda::Comanda(const Comanda& a) {
	if (a.name) {
		this->name = new char[strlen(a.name) + 1];
		strcpy_s(this->name, 1 + strlen(a.name), a.name);
	}
	if (a.adresa) {
		this->adresa = new char[strlen(a.adresa) + 1];
		strcpy_s(this->adresa, 1 + strlen(a.adresa), a.adresa);
	}
	this->pret = a.pret;
}


char* Comanda::getName() {
	return this->name;
}


char* Comanda::getAdresa() {
	return this->adresa;
}


float Comanda::getPret() {
	return this->pret;
}


void Comanda::setName(const char* name)
{
	if (this->name) {
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Comanda::setAdresa(const char* adresa)
{
	if (this->adresa) {
		delete[] this->adresa;
	}
	this->adresa = new char[strlen(adresa) + 1];
	strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
}

void Comanda::setPret(int pret)
{
	this->pret = pret;
}

Comanda& Comanda::operator=(const Comanda& a) {
	if (this == &a) return *this; //self-assignment
	if (name) delete[] name;
	if (a.name) {
		this->name = new char[strlen(a.name) + 1];
		strcpy_s(name, strlen(a.name) + 1, a.name);
	}
	pret = a.pret;
	if (adresa) delete[] adresa;
	if (a.adresa) {
		this->adresa = new char[strlen(a.adresa) + 1];
		strcpy_s(adresa, strlen(a.adresa) + 1, a.adresa);
	}
	return *this;
}

bool Comanda:: operator==(const Comanda& a) {
	return strcmp(this->name, a.name) == 0 && strcmp(this->adresa, a.adresa) == 0 && this->pret == a.pret;
}

ostream& operator<<(ostream& os, const Comanda& a)
{
	os << "Numele: " << a.name << " Adresa: " << a.adresa << " Pretul: " << a.pret;
	return os;
}

Comanda::~Comanda() {
	if (name) delete[]name;
	name = NULL;
	adresa = NULL;
	pret = 0;
}