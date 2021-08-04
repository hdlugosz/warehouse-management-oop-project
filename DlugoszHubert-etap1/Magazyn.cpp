#include "Magazyn.h"

void Magazyn::Insert(std::string name) {
	_arrTowar.push_back(Towar(_size, name));
	std::cout << "\nWstawiono nowy produkt do magazynu o nazwie: " << name << " (ID: " << _size << ")\n";
	_size++;
}

bool Magazyn::Add(int ID, int q) {
	bool result = false;
	if (ID >= _size || ID < 0)
		std::cout << "\nNiepoprawne ID. Operacja nieudana. \n";
	else if (q < 0) {
		std::cout << "\nLiczba musi byc nieujemna. Operacja nieudana. \n";
	}
	else {
		_arrTowar[ID] += q;
		std::cout << "\nDodano " << q << " sztuk produktu o ID: " << ID << "\n";
		result = true;
	}
	return result;
}

bool Magazyn::Remove(int ID, int q) {
	bool result = false;

	if (ID >= _size || ID < 0) {
		std::cout << "\nNiepoprawne ID. Operacja nieudana. \n";
	}
	else if (_arrTowar[ID].getQuantity() < q) {
		std::cout << "\nNie mozesz wydac wiecej towaru niz masz w magazynie. Operacja nieudana. \n";
	}
	else if (q < 0) {
		std::cout << "\nLiczba musi byc nieujemna. Operacja nieudana. \n";
	}
	else {
		_arrTowar[ID] -= q;
		std::cout << "\nOdjeto " << q << " sztuk produktu o ID: " << ID << "\n";
		result = true;
	}
	return result;
}

void Magazyn::Show() const {
	std::cout << "\nZawartosc magazynu: \n";
	if (_size == 0)
		std::cout << "Magazyn pusty. \n";
	else {
		for (int i = 0; i < _arrTowar.size(); i++) {
			std::cout << _arrTowar[i];
		}
	}
}

int Magazyn::getSize() const {
	return _size;
}