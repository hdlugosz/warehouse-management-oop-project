#ifndef MAGAZYN_H_
#define MAGAZYN_H_

#include <iostream>
#include <vector>
#include "Towar.h"
#include "Produkt.h"
#include "TowarSypki.h"
#include "TowarCiekly.h"
#include "Paleciak.h"

class Magazyn
{
private:
	static std::vector<std::string> _sharedProducts;		//vector przechowujacy nazwy wszystkich produktow we wszystkich magazynach
	static std::vector<int>  _sharedProductsID;				//vector przechowujacy ID wszystkich produktow we wszystkich magazynach
	std::vector<Produkt *> _arrTowar;						//vector elementow typu Produkt*
	int _size;												//rozmiar vectora

public:
	Magazyn() : _size(0) {};
	~Magazyn();												
	void Insert(std::string name, int type_of_product);		//wprowadza nowy produkt do magazynu
	bool Add(int pos, double q);							//dodaje ilosc produktu do stanu magazynowego
	bool Remove(int pos, double q);							//usuwa ilosc produkt ze stanu magazynowego
	void Show() const;										//wypisuje stany magazynowe kazdego produktu
	void Load(int pos, double q, Paleciak& pal);			//laduje produkt na paleciaka
	void Unload(Paleciak& pal);								//rozladowuje paleciaka
	int GetSize() const;									//zwraca rozmiar magazynu(vectora)

	void ShowSharedProducts() const;
	void ShowSharedProductsID() const;

};

#endif