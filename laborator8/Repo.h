#pragma once
#include <map>
#include<iostream>
using namespace std;


template <class T> class Repo
{
protected:
	map<int, T> elements;
	int c;
public:
	Repo();
	Repo(const Repo<T>& r);
	void addElement(const T& t);
	void deleteElement(int pos);
	map<int, T>get(int pos);
	int getSize();
	Repo<T>& operator=(const Repo<T>& r);
	int get_position(const T& t);
	map<int, T> getAll();
	~Repo() {};
};

template <class T>  Repo<T>::Repo()
{
	this->c = 0;
}

template <class T> Repo<T>::Repo(const Repo<T>& r) {
	this->elements = r.elements;
	this->c = r.c;
}


template <class T> void Repo<T>::addElement(const T& a) {
	elements.insert(pair<int, T>(c++, a));
}

template <class T> void Repo<T>::deleteElement(int position)
{
	this->elements.erase(position);
}

template <class T> map<int, T> Repo<T>::getAll() 
{
	return elements;
}

template <class T> map<int, T> Repo<T>::get(int pos) {
	return this->elements[pos];
}

template<class T> int Repo<T>::get_position(const T& t) {
	for (int i = 0; i < getSize(); i++)
		if (this->elements[i] == t)
			return i;
	return -1;
}

template <class T> int Repo<T>::getSize() {
	return this->elements.size();
}

template <class T>Repo<T>& Repo<T>::operator=(const Repo<T>& r) {
	this->elems = r.elements;
	this->n = r.c;
	return*this;
}
	
