#include <iostream>
#include <string>
#include "Towar.h"
#include "Magazyn.h"

using namespace std; //uznalem, ze w mainie skorzystam z calej przestrzeni nazw std;

//prototypy funkcji
int readInt();
string readString();
void menu();
void insert(Magazyn& mag);
void add(Magazyn& mag);
void remove(Magazyn& mag);

//petla main
int main()
{
    Magazyn mag;
    int choice;

    do {
        menu();

        choice = readInt();

        switch (choice) {
        case 0:
            break;
        case 1:
            insert(mag);
            break;
        case 2:
            add(mag);
            break;
        case 3:
            remove(mag);
            break;
        case 4:
            mag.Show();
            break;
        default:
            cout << "\nNiepoprawny wybór" << endl;
        }
    } while (choice != 0);

    return 0;
}


//definicje

//pobranie inta
int readInt() {
    string line;
    getline(cin, line);
    return atoi(line.c_str());
}

//pobranie stringa
string readString() {
    string line;
    getline(cin, line);
    return line;
}

//wyswietla menu
void menu() {
    cout << "\n---====== MENU =====---\n"
        "1: Wstaw nowy produkt do magazynu.\n"
        "2: Przyjmij produkt.\n"
        "3: Wydaj produkt\n"
        "4: Pokaz zawartosc magazynu.\n"

        "Wybierz akcje: (0 - zakoncz)" << endl;
}

//pobiera nazwe produktu od uzytkownika i przekazuje do metody wstawiajacej nowy produkt do magazynu
void insert(Magazyn& mag) {
    cout << "\nWprowadz nazwe produktu: " << endl;
    string name = readString();
    mag.Insert(name);                                                                       //przekazanie do metody
}

//pobiera id oraz ilosc oraz przekazuje do metody dodajacej ilosc produktu do magazynu. Zapetlone do otrzymania prawidlowych danych
void add(Magazyn& mag) {
    if (mag.getSize() == 0)                                                                 //zabezpieczenie gdy magazyn jest pusty
        cout << "\nMagazyn pusty. Najpierw wstaw nowy produkt do magazynu. " << endl;
    else {
        bool result = false;
        do {
            mag.Show();
            cout << "\nWybierz ID produktu, ktorego ilosc chcesz dodac: " << endl;
            int ID = readInt();
            cout << "\nWprowadz ilosc (liczba calkowita): " << endl;
            int q = readInt();
            result = mag.Add(ID, q);                                                        //przekazanie do metody - metoda Add klasy magazyn zwraca true jesli dodanie powiodlo sie, false - jesli dodanie sie nie powiodlo
            if (!result) { cout << "\nPonawiam probe." << endl; }
        } while (!result);                                                                  //sprawdzenie czy metoda zwrocila true, jesli nie, petla sie powtarza, uzytkownik proszony jest o ponowne podanie danych
    }
}

//pobiera id oraz ilosc oraz przekazuje do metody odejmujacej ilosc produktu z magazynu. Zapetlone do otrzymania prawidlowych danych
void remove(Magazyn& mag) {
    if (mag.getSize() == 0)                                                                 //zabezpieczenie gdy magazyn jest pusty
        cout << "\nMagazyn pusty. Najpierw wstaw nowy produkt do magazynu. " << endl;
    else {
        bool result = false;
        do {
            mag.Show();
            cout << "\nWybierz ID produktu, ktorego ilosc chcesz odjac: " << endl;
            int ID = readInt();
            cout << "\nWprowadz ilosc (liczba calkowita): " << endl;
            int q = readInt();
            result = mag.Remove(ID, q);                                                     //przekazanie do metody - metoda Remove klasy magazyn zwraca true jesli odjecie ilosci produktu sie powiodlo, false - jesli sie nie powiodlo
            if (!result) { cout << "\nPonawiam probe." << endl; }
        } while (!result);                                                                  //sprawdzenie czy metoda zwrocila true, jesli nie, petla sie powtarza, uzytkownik proszony jest o ponowne podanie danych
    }
}