#pragma once
#include "Repo.h"

template <class T> 
class RepositoryFile : public Repository<T>
{
private:
	const char* fisier;
public:
	RepositoryFile();
	RepositoryFile(const char* Name);
	void loadFromFile(const char* Name);
	void saveFile();
	void clearFile();
	~RepositoryFile();
};