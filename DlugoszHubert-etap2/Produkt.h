#ifndef PRODUKT_H_
#define PRODUKT_H_

#include <iostream>

class Produkt
{
protected:
	int _id;																	// id towaru
	static int _ID;																// id towaru (static -> aby we wszystkich magazynach bylo wspolne)

public:
	Produkt() { _id = _ID++; }													// konstruktor
	Produkt(int ID) { _id = ID; }												// 2gi konstruktor

	int getID() const { return _id; }											// zwraca ID

	//czysto wirtualne metody, ktore w kazdej klasie pochodnej musza byc zdefiniowane
	virtual std::string GetName() const = 0;									// zwraca nazwe
	virtual float Produkt::GetQuantity() const = 0;								// zwraca ilosc
	virtual Produkt& Produkt::operator+=(double n) = 0;							// przeciazenie operatora +=
	virtual Produkt& Produkt::operator-=(double n) = 0;							// przeciazenie operatora -=
	virtual void Print(std::ostream& os) const = 0;								// wypisuje dane dot. produktu
	virtual Produkt* Split(double q) = 0;										// wydziela ilosc q z produktu i zwraca wskaznik na nowy produkt o ilosci q
	virtual void Merge(Produkt*) = 0;											// scala produkt z produktem bedacym argumentem metody
	virtual int GetProductType() const = 0;
};

#endif