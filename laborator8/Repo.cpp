#include<iostream>
#include "Repo.h"

template <class T>  Repo<T>::Repo() {
}

template <class T> Repo<T>::Repo(const Repo& r) {
	this->elements = r.elements;
	this->c = r.c;
}

template <class T> Repo<T>::~Repo() {
}

template <class T> void Repo<T>::addElement(T& a) {
	elements.insert(pair<int, T>(contor++, a));
}

template <class T> map<int, T> Repo<T>::getAll() {
	return elemenst;
}

template <class T> void Repo<T>::deleteElement(int position)
{
	elements.erase(position);
}

template <class T> int Repo<T>::getSize() {
	return elements.size();
}
