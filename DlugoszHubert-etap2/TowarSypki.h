#ifndef TOWAR_SYPKI_H_
#define TOWAR_SYPKI_H_

#include <iostream>
#include "Produkt.h"

class TowarSypki : public Produkt											// dziedziczy po Produkt
{
protected:
	std::string _name;														// nazwa towaru
	double _weight;															// ilosc towaru
	int product_type;														// typ produktu
	

public:
	TowarSypki(std::string name) : Produkt::Produkt(), _name(name), _weight(0), product_type(2) {}				// konstruktor
	TowarSypki(int ID, std::string name) : Produkt::Produkt(ID), _name(name), _weight(0), product_type(2) {}	// 2gikonstruktor

	std::string GetName() const;
	float GetQuantity() const;
	TowarSypki& operator+=(double n);
	TowarSypki& operator-=(double n);
	void Print(std::ostream& os) const;
	TowarSypki* Split(double q);
	void Merge(Produkt* p);
	int GetProductType() const;
};

#endif
