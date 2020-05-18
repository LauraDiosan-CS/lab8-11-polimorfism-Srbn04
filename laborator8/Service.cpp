#include "Service.h"
#include "User.h"
#include "Repo.h"
#include "RepositoryFile.h"
#include<iostream>
using namespace std;


Service::Service(Repo<Mancare>* m, Repo<Shopping>* s, Repo<User>* u)
{
	this->repoMancare = m;
	this->repoShopping = s;
	this->repoUser = u;
}

bool Service::login(string username, string password)
{
	User u(username, password);
	return repoUser->get_position(u) != -1;
}

void Service::add_user(string username, string password) {
	User u(username, password);
	this->repoUser->addElement(u);
	((RepositoryFile<User>*)repoUser)->saveToFile();
}

void Service::add_mancare(string nume, string adresa,string lista, int pret) {
	Mancare m(nume, adresa, lista, pret);
	this->repoMancare->addElement(m);
	((RepositoryFile<Mancare>*)repoMancare)->saveToFile();
}

void Service::add_shopping(string nume, string adresa, string lista, int pret, string mag)
{
	Shopping s(nume, adresa, lista, pret, mag);
	this->repoShopping->addElement(s);
	((RepositoryFile<Shopping>*)repoShopping)->saveToFile();
}

map<int, Mancare> Service::mancareDupaNume(string nume) {
	map<int, Mancare> elements = this->repoMancare->getAll();
	map<int, Mancare> comenzi;
	typename map<int, Mancare>::iterator it;
	for (it = elements.begin(); it != elements.end(); it++)
		if (it->second.getNume().compare(nume) == 0)
			comenzi.insert(pair<int, Mancare>(it->first, it->second));
	return comenzi;
}


map<int, Shopping> Service::ShoppingDupaNume(string nume) {
	map<int, Shopping> elements = this->repoShopping->getAll(), comenzi;
	typename map<int, Shopping>::iterator it;
	for (it = elements.begin(); it != elements.end(); it++)
		if (it->second.getNume().compare(nume) == 0)
			comenzi.insert(pair<int, Shopping>(it->first, it->second));
	return comenzi;
}

map<int, Mancare>Service::all_foods()
{
	return repoMancare->getAll();
}

map<int, Shopping>Service::all_shopping()
{
	return repoShopping->getAll();
}


map<int, User>Service::all_users()
{
	return repoUser->getAll();
}