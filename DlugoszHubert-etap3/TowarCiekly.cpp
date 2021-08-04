#include "TowarCiekly.h"

std::string TowarCiekly::GetName() const {
	return _name;
}

float TowarCiekly::GetQuantity() const {
	return _volume;
}

TowarCiekly& TowarCiekly::operator+=(double n) {
	_volume += n;

	return *this;
}

TowarCiekly& TowarCiekly::operator-=(double n) {
	_volume -= n;

	return *this;
}

void TowarCiekly::Print(std::ostream& os) const {
	os << "ID: " << _id << ", ";
	os << "Nazwa: " << _name << ", ";
	os << "Objetosc: " << _volume << " litr(y/ow)\n";
}

TowarCiekly* TowarCiekly::Split(double q) {
	TowarCiekly* tmp = new TowarCiekly(_id, _name);
	_volume -= q;
	tmp->_volume += q;

	return tmp;
}

void TowarCiekly::Merge(Produkt* p) {
	this->_volume += p->GetQuantity();
}

int TowarCiekly::GetProductType() const {
	return product_type;
}