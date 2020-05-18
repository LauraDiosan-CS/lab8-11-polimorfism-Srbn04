#pragma once
#include<string>
#include "RepositoryFile.h"

template <class T> class RepositoryHTML :public RepositoryFile<T>
{
public:
	RepositoryHTML(const char* fisier) :RepositoryFile<T>(fisier) {} ;
	~RepositoryHTML() {};
	void saveToFile();
	void loadFromFile();

};

template <class T> void RepositoryHTML<T>::saveToFile()
{
	ofstream g(this->fisier);
	g << "<html>" << endl;
	g << "<head> <title> RepoHTML </title> </head>" << endl;
	g << "<body>" << endl;
	typename map<int, T>::iterator it;
	for (it = this->elements.begin(); it != this->elements.end(); it++)
		g << "<p>" << it->first << "," << it->second << "</p>" << endl;
	g << "</body>" << endl << "</html>";
}


template <class T> void RepositoryHTML<T>::loadFromFile() {
	ifstream f(this->fisier);
	string line;
	this->c = 0;
	this->elements.clear();
	while (getline(f, line)) {
		if (line[1] == 'p') {
			line.erase(line.end() - 4, line.end());
			T ob(line, ',');
			this->elements.insert(pair<int, T>(this->c++, ob));
		}
	}
}