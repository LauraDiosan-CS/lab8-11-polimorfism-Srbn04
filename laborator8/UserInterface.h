#pragma once
#include <string>
#include "Service.h"
using namespace std;

class UI {

private:
	Service s;
	User u;
public:
	UI() {};
	~UI() {};
	UI( Service& s);
	int login();
	void addMancare();
	void addShopping();
	void addOrder();
	void logout();
	void showMenu();
	void showMenuOrder();
	void run();
	void comenzi_dupa_nume();
	void menu();
};