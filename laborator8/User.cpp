#include "User.h"
using namespace std;

void User::logout()
{
	this->password = "";
	this->username = "";
}

bool User::operator==(const User& u)
{
	return (username == u.username) and (password == u.password);
}
