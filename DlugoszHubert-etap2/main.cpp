// moznaby bylo przerzucic nazwe, typ produktu, getname, getproducttype itp do klasy Produkt(bazowej)

#include <iostream>
#include <string>
#include <fstream>

#include "Magazyn.h"
#include "Towar.h"      
#include "Produkt.h"
#include "TowarSypki.h"
#include "TowarCiekly.h"
#include "Paleciak.h"

using namespace std; //uznalem, ze w mainie skorzystam z calej przestrzeni nazw std;

//prototypy funkcji
int readInt(istream &in);
string readString(istream& in);
void magChoice(vector<Magazyn*> &MagVector, Magazyn* &mag, istream& in);
void menu();
void insert(Magazyn& mag, istream& in);
void add(Magazyn& mag, istream& in);
void remove(Magazyn& mag, istream& in);
void load(Magazyn& mag, Paleciak& pal, istream& in);
void unload(Magazyn& mag, Paleciak& pal);



//petla main
int main(int argc, char* argv[])
{

    //petla sprawdzajaca ilosc arugmentow -> jesli drugim argumentem jest nazwa pliku, otwiera plik i czyta z pliku, w przeciwnym razie z klawiatury
    ifstream f;
    if (argc >= 2) {
        f.open(argv[1]);
    }
    istream& in = (argc >= 2) ? f : cin;

    
    vector<Magazyn*> MagVector;
    Magazyn* mag = nullptr;
    Paleciak pal;
    int choice = -1;

    magChoice(MagVector, mag, in);

    do {
        
        menu();
        
        choice = readInt(in);

        switch (choice) {
        case 0:
            break;
        case 1:
            insert(*mag, in);
            break;
        case 2:
            add(*mag, in);
            break;
        case 3:
            remove(*mag, in);
            break;
        case 4:
            mag->Show();
            break;
        case 5:
            magChoice(MagVector, mag, in);
            break;
        case 6:
            load(*mag, pal, in);
            break;
        case 7:
            unload(*mag, pal);
            break;
        case 8:
            pal.Show();
            break;
        default:
			cout << "\nNiepoprawny wybór" << endl;
        }
    } while (choice != 0);
 
    while (!MagVector.empty()) {
        Magazyn* tmp_mag = MagVector.back();
        MagVector.pop_back();
        delete tmp_mag;
    }

    f.close();
    return 0;
}


//definicje

//pobranie inta
int readInt(istream& in) {
    string line;
    getline(in, line);
    return atoi(line.c_str());
}

//pobranie stringa
string readString(istream& in) {
    string line;
    getline(in, line);
    return line;
}

//wybor magazynu
void magChoice(vector<Magazyn*>& MagVector, Magazyn* &mag, istream& in) {
    int mag_choice;

    if (MagVector.size() == 0) {
        MagVector.push_back(new Magazyn);
    }
    do {
        cout << "\nWybierz magazyn: (0 - stworz nowy)\n";
        for (int i = 0; i < MagVector.size(); i++) {
            cout << i + 1 << ". Magazyn\n";
        }

        mag_choice = readInt(in);

        if (mag_choice == 0) {
            MagVector.push_back(new Magazyn);
        }
        else if (mag_choice > 0 && mag_choice <= MagVector.size()) {
            mag = MagVector[mag_choice - 1];
            cout << "\nMagazyn nr " << mag_choice << " zostal wybrany\n";
        }
    } while (mag_choice <= 0 || mag_choice > MagVector.size());
}

//wyswietla menu
void menu() {
    cout << "\n---====== MENU =====---\n"
        "1: Wstaw nowy produkt do magazynu.\n"
        "2: Przyjmij produkt.\n"
        "3: Wydaj produkt\n"
        "4: Pokaz zawartosc magazynu.\n"
        "5: Wybor magazynu.\n"
        "6: Zaladuj na paleciaka.\n"
        "7. Wyladuj paleciaka.\n"
        "8. Pokaz zawartosc paleciaka.\n\n"

        "Wybierz akcje: (0 - zakoncz)" << endl;
}

//pobiera nazwe produktu od uzytkownika i przekazuje do metody wstawiajacej nowy produkt do magazynu
void insert(Magazyn& mag, istream& in) {
    cout << "\nWprowadz nazwe produktu: " << endl;
    string name = readString(in);
    cout << "\nWprowadz typ produktu produktu: (1 - towar na sztuki, 2 - towar sypki, 3 - towar ciekly)" << endl;
    int type_of_product = readInt(in);

    mag.Insert(name, type_of_product);                                                                        //przekazanie do metody
}

//pobiera pozycje oraz ilosc oraz przekazuje do metody dodajacej ilosc produktu do magazynu. Zapetlone do otrzymania prawidlowych danych
void add(Magazyn& mag, istream& in) {
    if (mag.GetSize() == 0)                                                                                  //zabezpieczenie gdy magazyn jest pusty
        cout << "\nMagazyn pusty. Najpierw wstaw nowy produkt do magazynu. " << endl;
    else {
        bool result = false;
        do {
            mag.Show();
            cout << "\nWybierz pozycje produktu, ktorego ilosc chcesz dodac: " << endl;
            int pos = readInt(in);
            cout << "\nWprowadz ilosc: " << endl;
            double q;
            in >> q;
            in.ignore();
            result = mag.Add(pos-1, q);                                                                       //przekazanie do metody - metoda Add klasy magazyn zwraca true jesli dodanie powiodlo sie, false - jesli dodanie sie nie powiodlo
            if (!result) { cout << "\nPonawiam probe." << endl; }
        } while (!result);                                                                                    //sprawdzenie czy metoda zwrocila true, jesli nie, petla sie powtarza, uzytkownik proszony jest o ponowne podanie danych
    }
}

//pobiera pozycje oraz ilosc oraz przekazuje do metody odejmujacej ilosc produktu z magazynu. Zapetlone do otrzymania prawidlowych danych
void remove(Magazyn& mag, istream& in) {
    if (mag.GetSize() == 0)                                                                                   //zabezpieczenie gdy magazyn jest pusty
        cout << "\nMagazyn pusty. Najpierw wstaw nowy produkt do magazynu. " << endl;
    else {
        bool result = false;
        do {
            mag.Show();
            cout << "\nWybierz pozycje produktu, ktorego ilosc chcesz odjac: " << endl;
            int pos = readInt(in);
            cout << "\nWprowadz ilosc: " << endl;
            double q;
            in >> q;
            in.ignore();
            result = mag.Remove(pos-1, q);                                                                    //przekazanie do metody - metoda Remove klasy magazyn zwraca true jesli odjecie ilosci produktu sie powiodlo, false - jesli sie nie powiodlo
            if (!result) { cout << "\nPonawiam probe." << endl; }
        } while (!result);                                                                                    //sprawdzenie czy metoda zwrocila true, jesli nie, petla sie powtarza, uzytkownik proszony jest o ponowne podanie danych
    }
}


//zaladowanie produktu na paleciaka -> pobiera pozycje oraz ilosc i przekazuje do metody ladujacej paleciaka
void load(Magazyn& mag, Paleciak& pal, istream& in) {
    if (mag.GetSize() == 0)                                                                                   //zabezpieczenie gdy magazyn jest pusty
        cout << "\nMagazyn pusty. Najpierw wstaw nowy produkt do magazynu. " << endl;
    else {
        mag.Show();
        cout << "\nWybierz pozycje produktu, ktorego chcesz przerzucic na paleciaka: " << endl;
        int pos = readInt(in);
        cout << "\nWprowadz ilosc: " << endl;
        double q;
        in >> q;
        in.ignore();
        mag.Load(pos - 1, q, pal);                                                                            //przekazanie do metody 
    }
    
}

//wyladowanie produktow z paleciaka do magazynu
void unload(Magazyn& mag, Paleciak& pal) {
    mag.Unload(pal);
}