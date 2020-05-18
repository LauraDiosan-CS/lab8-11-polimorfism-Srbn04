
#include"Avion.h"

Avion::Avion() {

	this->x = "";
	this->y = 0;
	this->orientare = "";

}

Avion::Avion(string x, int y, string orientareCoada) {

	this->x = x;
	this->y = y;
	this->orientare = orientareCoada;
}
Avion::Avion(const Avion& a) {
	this->x = a.x;
	this->y = a.y;
	this->orientare = a.orientare;
}
Avion::~Avion() {

	this->x = "";
	this->y = 0;
	this->orientare = "";
}
string Avion::getX() {

	return this->x;
}
int Avion::getY() {

	return this->y;
}
string Avion::getOrientare() {

	return this->orientare;
}
void Avion::setX(string x) {

	this->x = x;
}
void Avion::setY(int y) {
	this->y = y;
}
void Avion::setOrientare(string orientare) {

	this->orientare = orientare;
}

Avion& Avion::operator=(const Avion& a) {

	this->setX(a.x);
	this->setY(a.y);
	this->setOrientare(a.orientare);
	return *this;
}
bool Avion::operator==(const Avion& a) {

	return (this->x.compare(a.x) == 0) && (this->y == a.y) && (this->orientare.compare(a.orientare) == 0);
}
ostream& operator<<(ostream& os, const Avion& a) {

	os << "Coordonata X: " << a.x << "|" << " Coordonata Y: " << a.y << "|" << " Orientare coada:" << a.orientare;
	return os;
}

