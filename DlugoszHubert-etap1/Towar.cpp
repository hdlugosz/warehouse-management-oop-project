#include "Towar.h"

Towar& Towar::operator+=(int n) {
	_quantity += n;

	return *this;
}

Towar& Towar::operator-=(int n) {
	_quantity -= n;

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Towar& t) {
	os << "ID: " << t._ID << ", ";
	os << "Nazwa: " << t._name << ", ";
	os << "Ilosc: " << t._quantity << "\n";

	return os;
}

int Towar::getQuantity() const {
	return _quantity;
}