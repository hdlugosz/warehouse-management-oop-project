#ifndef TOWAR_H_
#define TOWAR_H_

#include <iostream>

class Towar
{
private:
	int _ID;																//id towaru
	std::string _name;														//nazwa towaru
	int _quantity;															//ilosc towaru
public:
	Towar(int ID, std::string name) : _ID(ID), _name(name), _quantity(0) {}	//konstruktor
	
	Towar& operator+=(int n);												//dodaje n do ilosci towaru
	Towar& operator-=(int n);												//odejmuje n od ilosci towaru
	friend std::ostream& operator<<(std::ostream& os, const Towar& t);		//wypisuje dane dot. towaru
	int getQuantity() const;												//zwraca ilosc

};

#endif
