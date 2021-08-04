#ifndef MAGAZYN_H_
#define MAGAZYN_H_

#include <iostream>
#include <vector>
#include "Towar.h"

class Magazyn
{
private:
	std::vector<Towar> _arrTowar;				//vector elementow typu Towar
	int _size;									//rozmiar vectora
public:
	Magazyn() : _size(0) {};					//konstruktor
	void Insert(std::string name);				//wprowadza nowy produkt do magazynu
	bool Add(int ID, int q);					//dodaje ilosc produktu do stanu magazynowego
	bool Remove(int ID, int q);					//usuwa ilosc produkt ze stanu magazynowego
	void Show() const;							//wypisuje stany magazynowe kazdego produktu
	int getSize() const;						//zwraca rozmiar magazynu(vectora)
};

#endif