#pragma once
#include<string>
#include<iostream>
#include "Functions.h"
using namespace std;

class User {
protected:
	string username;
	string password;
public:
	User() {};
	~User() {};
	User(string u, string p) :username(u), password(p) {};
	string getUsername() {return this->username;}
	string getPassword() { return this->password; };
	void logout();
	void setUsername(string u)
	{
		username = u;
	};
	void setPassword(string p)
	{
		password = p;
	};
	bool operator==(const User& u);
	friend ostream& operator<<(ostream& os, const User& user) {
		os << user.username << "," << user.password;
		return os;
	}
	User(string line, char delim) {
		vector<string> elements = splitLine(line, delim);
		this->username = elements[0];
		this->password = elements[1];
	}
};