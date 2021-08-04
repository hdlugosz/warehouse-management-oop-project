#include "Paleciak.h"

void Paleciak::Show() {
	std::cout << "\nZawartosc paleciaka: \nWolne miejsce: " << _capacity << " (na 500)\n";
	if (_arrPaleciak.size() == 0)
		std::cout << "Paleciak pusty. \n";
	else {
		for (int i = 0; i < _arrPaleciak.size(); i++) {
			std::cout << "Pozycja " << i + 1 << ": ";
			_arrPaleciak[i]->Print(std::cout);
		}
	}
}