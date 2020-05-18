#include "Functions.h"
#include<iostream>
#include<sstream>
using namespace std;

vector<string> splitLine(string linie, char delim)
{

	std::stringstream ss(linie);
	std::string item;
	std::vector<std::string> elements;
	while (getline(ss, item, delim)) {
		elements.push_back(item);
	}
	return elements;
}