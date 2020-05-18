#pragma once
#include<string>
#include<iostream>
using namespace std;
class Avion {

private:
	string x;
	int y;
	string orientare;
public:
	Avion();
	Avion(string x, int y, string orientare);
	~Avion();
	Avion(const Avion& a);
	string getX();
	void setX(string );
	void setY(int );
	void setOrientare(string);
	int getY();
	string getOrientare();
	Avion& operator=(const Avion& a);
	bool operator==(const Avion&);
	friend ostream& operator<<(ostream& os, const Avion& c);
};