
#include"RepositoryFile.h"
#include<iostream>
#include<fstream>
#include <cstddef>
#include<string>
template<class T>
RepositoryFile<T>::RepositoryFile() :Repo() {

};
template<class T>
RepositoryFile<T>::~RepositoryFile() {

};
template <class T>
RepositoryFile<T>::RepositoryFile(const char* fisier) {

	loadFromFile(fisier);
}




template<class T>
void RepositoryFile<T>::loadFromFile(const char* fisier) {

	elem.clear();
	ifstream f(fisier);
	char* nume = new char[100];
	int consumMemorieKb;
	char* status = new char[100];
	while ((f >> name >> consumMemorieKb >> status) {
		f >> nume >> consumMemorieKb >> status;
		if (strcmp(nume, "") != 0) {
			T a(nume, consumMemorieKb, status);
			elem.insert(pair<int, T>(key++, a));


		}
	}
	delete[] nume;
	delete[] status;
	f.close();

}
template<class T>
void RepositoryFile<T>::saveFile()
{
	ofstream f(fis);
	for (auto i = elem.begin(); i != elem.end(); i++)
		f << i->second << "\n";
	f.close();
}
template<class T>
void RepositoryFile<T>::clearFile() {

	std::ifstream File;
	std::string filepath = "Teste.txt";
	File.open(filepath.c_str(), std::ifstream::out | std::ifstream::trunc);
	if (!File.is_open() || File.fail())
	{
		File.close();
		printf("\nError : failed to erase file content !");
	}
	File.close();
}