#ifndef TOWAR_CIEKLY_H_
#define TOWAR_CIEKLY_H_

#include <iostream>
#include "Produkt.h"

class TowarCiekly : public Produkt											// dziedziczy po Produkt
{
protected:
	std::string _name;														// nazwa towaru
	double _volume;															// ilosc towaru
	int product_type;														// typ produktu
	

public:
	TowarCiekly(std::string name) : Produkt::Produkt(), _name(name), _volume(0), product_type(3) {}				// konstruktor
	TowarCiekly(int ID, std::string name) : Produkt::Produkt(ID), _name(name), _volume(0), product_type(3) {}	// 2gi konstruktor
	
	std::string GetName() const;
	float GetQuantity() const;
	TowarCiekly& operator+=(double n);
	TowarCiekly& operator-=(double n);
	void Print(std::ostream& os) const;
	TowarCiekly* Split(double q);
	void Merge(Produkt* p);
	int GetProductType() const;
};

#endif
