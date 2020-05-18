#pragma once
#include "User.h"
#include "Mancare.h"
#include "Shopping.h"
#include "Repo.h"

class Service {
protected:
	Repo<User>* repoUser;
	Repo<Mancare>* repoMancare;
	Repo<Shopping>* repoShopping;
public:
	Service() {
		this->repoMancare = NULL;
		this->repoUser = NULL;
		this->repoShopping = NULL;
	};
	Service(Repo<Mancare>*,Repo<Shopping>*, Repo<User>*);
	~Service() {};
	void add_user(string, string);
	void add_mancare(string, string, string, int);
	void add_shopping(string, string, string, int, string);
	map<int, Mancare>mancareDupaNume(string nume);
	map<int, Shopping>ShoppingDupaNume(string nume);
	map<int, User>all_users();
	map<int, Mancare>all_foods();
	map<int, Shopping>all_shopping();
	bool login(string, string);


};