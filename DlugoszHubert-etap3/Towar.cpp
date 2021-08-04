#include "Towar.h"

std::string Towar::GetName() const {
	return _name;
}

float Towar::GetQuantity() const {
	return static_cast<float>(_quantity);
}

Towar& Towar::operator+=(double n) {
	_quantity += static_cast<int>(n);

	return *this;
}

Towar& Towar::operator-=(double n) {
	_quantity -= static_cast<int>(n);

	return *this;
}

void Towar::Print(std::ostream& os) const {
	std::cout << "ID: " << _id << ", ";
	std::cout << "Nazwa: " << _name << ", ";
	std::cout << "Ilosc: " << _quantity << " sztuk(a/i)\n";
}

Towar* Towar::Split(double q) {
	Towar* tmp = new Towar(_id, _name);
	_quantity -= static_cast<int>(q);
	tmp->_quantity += static_cast<int>(q);

	return tmp;
}

void Towar::Merge(Produkt* p) {
	this->_quantity += p->GetQuantity();
}

int Towar::GetProductType() const {
	return product_type;
}
