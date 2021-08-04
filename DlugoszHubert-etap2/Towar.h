#ifndef TOWAR_H_
#define TOWAR_H_

#include <iostream>
#include "Produkt.h"

class Towar : public Produkt 												// dziedziczy po Produkt
{
protected:
	std::string _name;														// nazwa towaru
	int _quantity;															// ilosc towaru
	int product_type;														// typ produktu
	
public:
	Towar(std::string name) : Produkt::Produkt(), _name(name), _quantity(0), product_type(1) {}				// konstruktor
	Towar(int ID, std::string name) : Produkt::Produkt(ID), _name(name), _quantity(0), product_type(1) {}	// 2gi konstruktor
	
	std::string GetName() const;
	float GetQuantity() const;
	Towar& operator+=(double n);
	Towar& operator-=(double n);
	void Print(std::ostream& os) const;
	Towar* Split(double q);
	void Merge(Produkt* p);
	int GetProductType() const;
};

#endif
