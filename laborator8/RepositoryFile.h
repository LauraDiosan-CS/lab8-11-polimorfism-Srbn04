#pragma once
#include<map>
#include<fstream>
#include<iostream>
#include<vector>
#include<string.h>
#include "Repo.h"
using namespace std;

template <class T>  class RepositoryFile : public Repo<T>
{
protected:
	 char* fisier;
public:
	RepositoryFile() {};
	RepositoryFile(const char* );
	virtual void loadFromFile() ;
	virtual void saveToFile() ;
	~RepositoryFile();
};

template<class T> RepositoryFile<T>::RepositoryFile(const char* fisier)
{
	this->fisier = new char[strlen(fisier) + 1];
	strcpy_s(this->fisier, strlen(fisier) + 1, fisier);
}


template<class T> RepositoryFile<T>::~RepositoryFile()
{

}


template <class T>void  RepositoryFile<T>::saveToFile()
{

}

template<class T> void RepositoryFile<T>::loadFromFile()
{

}


