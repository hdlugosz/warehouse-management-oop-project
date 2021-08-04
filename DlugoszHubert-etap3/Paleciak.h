#ifndef PALECIAK_H_
#define PALECIAK_H_

#include <iostream>
#include <vector>
#include "Produkt.h"

class Paleciak
{
private:
	std::vector<Produkt*> _arrPaleciak;			// vector elementow typu Produkt*
	float _capacity;							// udzwig
public:
	Paleciak() : _capacity(500) {};				//udzwig ustawiony domyslnie na 500
	void Show();								//wyswietla zawartosc paleciaka

	friend class Magazyn;
};

#endif
