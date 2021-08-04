#include "Magazyn.h"

std::vector<std::string> Magazyn::_sharedProducts;
std::vector<int>  Magazyn::_sharedProductsID;


Magazyn::~Magazyn() {
	while (!_arrTowar.empty()) {
		Produkt* pr = _arrTowar.back();
		_arrTowar.pop_back();
		delete pr;
	}
}

void Magazyn::Insert(std::string name, int type_of_product) {
	// sprawdzenie czy produkt znajduje sie juz w magazynie - jesli tak - nie zostaje dopisany
	bool isAlready = false;
	for (int i = 0; i < _arrTowar.size(); i++) {
		if (name == _arrTowar[i]->GetName()) {
			std::cout << "Ten produkt znajduje sie juz w magazynie.\n";
			isAlready = true;
		}
	}
	// sprawdzenie typu produktu
	if (!isAlready) {
		if (type_of_product != 1 && type_of_product != 2 && type_of_product != 3) {
			std::cout << "Nieprawidlowy typ produktu.\n";
			return;
		}
		// czy w innym magazynie jest produkt o takiej samej nazwie. Jesli tak -> ustawia takie samo ID 
		bool exists = false;
		int ID = -1;

		for (int i = 0; i < _sharedProducts.size(); i++) {
			if (_sharedProducts[i] == name) {
				exists = true;
				ID = _sharedProductsID[i];
				break;
			}
		}

		if (exists == true) {
			if (type_of_product == 1)
				_arrTowar.push_back(new Towar(ID, name));
			else if (type_of_product == 2) {
				_arrTowar.push_back(new TowarSypki(ID, name));
			}

			else if (type_of_product == 3)
				_arrTowar.push_back(new TowarCiekly(ID, name));
		}
		else {
			if (type_of_product == 1)
				_arrTowar.push_back(new Towar(name));
			else if (type_of_product == 2)
				_arrTowar.push_back(new TowarSypki(name));
			else if (type_of_product == 3)
				_arrTowar.push_back(new TowarCiekly(name));
			_sharedProducts.push_back(name);
			_sharedProductsID.push_back(_sharedProductsID.size());
		}

		std::cout << "\nWstawiono nowy produkt do magazynu o nazwie: " << name << "\n";
		_size++;
	}		

}

bool Magazyn::Add(int pos, double q) {
	bool result = false;
	if (pos >= _size || pos < 0)
		std::cout << "\nNiepoprawna pozycja. Operacja nieudana. \n";
	else if (q < 0) {
		std::cout << "\nLiczba musi byc nieujemna. Operacja nieudana. \n";
	}
	else {
		*(_arrTowar[pos]) += q;
		if (_arrTowar[pos]->GetProductType() == 1)
			q = static_cast<int>(q);
		std::cout << "\nDodano produkt o pozycji: " << pos + 1 << " w ilosci " << q << ".\n";
		result = true;
	}
	return result;
}

bool Magazyn::Remove(int pos, double q) {
	bool result = false;

	if (pos >= _size || pos < 0) {
		std::cout << "\nNiepoprawna pozycja. Operacja nieudana. \n";
	}
	else if (_arrTowar[pos]->GetQuantity() < q) {
		std::cout << "\nNie mozesz wydac wiecej towaru niz masz w magazynie. Operacja nieudana. \n";
	}
	else if (q < 0) {
		std::cout << "\nLiczba musi byc nieujemna. Operacja nieudana. \n";
	}
	else {
		*(_arrTowar[pos]) -= q;
		if (_arrTowar[pos]->GetProductType() == 1)
			q = static_cast<int>(q);
		std::cout << "\nOdjeto produkt o pozycji: " << pos + 1 << " w ilosci " << q << ".\n";
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
			std::cout << "Pozycja " << i+1 << ": ";
			_arrTowar[i]->Print(std::cout);
		}
	}
}

void Magazyn::Load(int pos, double q, Paleciak& pal) {
	if (pos >= _size || pos < 0) {														// czy podana pozycja jest poprawna
		std::cout << "\nNiepoprawna pozycja. Operacja nieudana. \n";
	}
	else if (q <= 0) {																	// czy liczba, ktora chcemy dodac jest dodatnia
		std::cout << "\nLiczba musi byc dodatnia\n";
	}
	else if (_arrTowar[pos]->GetQuantity() < q)											// czy nie probujemy wziac wiecej na paleciaka, niz jest w magazynie
		std::cout << "\nProbujesz wziac wiecej niz jest w magazynie.\n";
	else if (pal._capacity < q)															// czy jest wystarczajaco miejsca na paleciaku
		std::cout << "\nZa malo miejsca na paleciaku\n";
	else {
		pal._arrPaleciak.push_back(_arrTowar[pos]->Split(q));;
		if (_arrTowar[pos]->GetProductType() == 1)
			q = static_cast<int>(q);
		pal._capacity -= q;
		std::cout << "\nPozostalo " << pal._capacity << " miejsca w paleciaku. \n";
	}
}

void Magazyn::Unload(Paleciak& pal) {
	if (pal._arrPaleciak.size() == 0) {													// czy paleciak jest pusty
		std::cout << "\nPaleciak pusty. Nie ma czego wyladowywac.\n";
	}
	else {																				// jesli produkt juz znajduje sie w magazynie, wyladowuje z paleciaka zwiekszajac jego ilosc
		for (int i = 0; i < pal._arrPaleciak.size(); i++) {
			bool result = false;
			for (int j = 0; j < _arrTowar.size(); j++) {
				if (_arrTowar[j]->GetName() == pal._arrPaleciak[i]->GetName()) {
					_arrTowar[j]->Merge(pal._arrPaleciak[i]);
					//Add(j, pal._arrPaleciak[i]->getQuantity());
					std::cout << "\nWyladowano " << pal._arrPaleciak[i]->GetName() << "\n";
					result = true;
				}
			}

			if (!result) {																// jesli produkt nie znajduje sie w magazynie, wyladowuje z paleciaka automatycznie dodajac nowy produkt do magazynu
				_arrTowar.push_back(pal._arrPaleciak[i]);
				std::cout << "\nWyladowano " << pal._arrPaleciak[i]->GetName() << "\n";
				pal._arrPaleciak[i] = nullptr;
				_size++;
			}
		}

		while (!pal._arrPaleciak.empty()) {
			Produkt* pr = pal._arrPaleciak.back();
			pal._arrPaleciak.pop_back();
			delete pr;
		}
		pal._capacity = 500;
	}

}

int Magazyn::GetSize() const {
	return _size;
}

void Magazyn::ShowSharedProducts() const {
	for (int i = 0; i < _sharedProducts.size(); i++) {
		std::cout << _sharedProducts[i] << "\n";
	}

}

void Magazyn::ShowSharedProductsID() const {
	for (int i = 0; i < _sharedProductsID.size(); i++) {
		std::cout << _sharedProductsID[i] << "\n";
	}

}


