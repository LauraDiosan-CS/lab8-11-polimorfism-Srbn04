#include "UserInterface.h"
#include "User.h"
#include<iostream>
using namespace std;

void UI::showMenu()
{
	cout << "1. Afisarea tuturor comenzilor ";
	cout << endl;
	cout << "2. Adaugarea unei comenzi";
	cout << endl;
	cout << "3.Logout";
	cout << endl;

}

void UI::menu()
{
	while (true)
	{
		cout << endl;
		showMenu();
		int opt;
		cin >> opt;
		if (opt == 1)
			comenzi_dupa_nume();
		if (opt == 2)
			addOrder();
		if (opt == 3)
		{
			logout();
			break;
		}
		if(opt!=1 && opt!=2 && opt!=3)
			cout << "Optiunea selectata nu exista " << endl;
}
}

int UI::login()
{
	string username, password;
	cout << "Username: ";
	cin >> username;
	cout << "Password ";
	cin >> password;
	u.setUsername(username);
	u.setPassword(password);
	if (s.login(username, password) == true)
		return 1;
}

void UI::showMenuOrder()
{
	cout << endl;
	cout << "1. ---Mancare---";
	cout << "2. ---Shooping---";
	cout << endl;
}

void UI::logout()
{
	u.setPassword("");
	u.setUsername("");
}

void  UI::addMancare()
{
	string  adresa, preparate;
	vector<string>listaPrep;
	int  price;
	cout << "Adresa: ";
	cin >> adresa;
	cout << " Ce doriti sa adaugati? ";
	cin >> preparate;
	cout << "Care este pretul total?:";
	cin >> price;
	s.add_mancare(u.getUsername(), adresa, preparate, price);
}

void  UI::addShopping()
{
	string  adresa, preparate, magazin;
	vector<string>listaPrep;
	int  price;
	cout << "Adresa: ";
	cin >> adresa;
	cout << " Ce doriti sa adaugati? ";
	cin >> preparate;
	cout << "Care este pretul total?:";
	cin >> price;
	cout << "De la ce magazin comandati? ";
	cin >> magazin;
	s.add_shopping(u.getUsername(), adresa, preparate, price,magazin);
}

void UI::addOrder()
{
	showMenuOrder();
	int option;
	cout << "Alegeti optiunea: ";
	cin >> option;
	if (option == 1)
		addMancare();
	if (option == 2)
		addShopping();
}

UI::UI( Service& service) {
	this->s = service;
}



void UI:: comenzi_dupa_nume()
{
	map<int, Mancare> comenziMancare = this->s.mancareDupaNume(this->u.getUsername());
	map<int, Shopping> comenziShopping = this->s.ShoppingDupaNume(this->u.getUsername());
	map<int, Mancare>::iterator it;
	cout << "Comenzi tip <Mancare>: \n";
	for (it = comenziMancare.begin(); it != comenziMancare.end(); it++)
		cout << it->second << "\n";
	cout << "Comenzi tip <Shopping>: \n";
	map<int, Shopping>::iterator itr;
	for (itr = comenziShopping.begin(); itr != comenziShopping.end(); itr++)
		cout << itr->second << "\n";
	cout << "\n";

}

void UI::run()
{
	while (true)
	{
		cout << "1. Intrati in aplicatie";
		cout << endl;
		cout << "2. Iesiti din aplicatie";
		cout << endl;
		int option;
		cin>> option;
		if (option == 1)
		{
			if (login() == 1)
			{
				cout << "Ati intrat in contul dvs. ";
				menu();
			}
			else
				cout << "Username/parola nu este corecta sau contul nu exista ";
		}
		if (option == 2)
			break;
	}
}