#include "TowarSypki.h"

std::string TowarSypki::GetName() const {
	return _name;
}

float TowarSypki::GetQuantity() const {
	return _weight;
}

TowarSypki& TowarSypki::operator+=(double n) {
	_weight += n;

	return *this;
}

TowarSypki& TowarSypki::operator-=(double n) {
	_weight -= n;

	return *this;
}

void TowarSypki::Print(std::ostream& os) const {
	os << "ID: " << _id << ", ";
	os << "Nazwa: " << _name << ", ";
	os << "Waga: " << _weight << " kg\n";
}

TowarSypki* TowarSypki::Split(double q) {
	TowarSypki* tmp = new TowarSypki(_id, _name);
	_weight -= q;
	tmp->_weight += q;

	return tmp;
}

void TowarSypki::Merge(Produkt* p) {
	this->_weight += p->GetQuantity();
}

int TowarSypki::GetProductType() const {
	return product_type;
}