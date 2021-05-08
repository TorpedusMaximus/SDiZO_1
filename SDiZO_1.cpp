#include <iostream>
#include "kopiec.h"
#include "lista.h"
#include "tablica.h"
#include <random>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include "SDiZO_1.h"

using namespace std;

fstream plik; //handlery do plikow 
fstream wyniki;
long long int czas, frequency, start, elapsed; //zmienne do przechowywania czasu i generacji losowych liczb
random_device rd;
mt19937 gen(rd());

long long int read_QPC() { // wartosc licznika czasu 
	LARGE_INTEGER count;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&count);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return((long long int)count.QuadPart);
}


void Tablica() {
	tablica struktura; //badana struktura
	int wybor = 1;
	long long int ilosc;//ilosc danychw sturkturze

	long long int temp; // rzutowanie na int błednych wynikow
	int tmp;

	int index;//zmienna uzywana przy usuwaniu z indexu

	int szukanie;//index poszukiwanej liczby
	int szukana;//szukana liczba

	int ile; // ilosc liczb do usuniecia
	int liczba;
	string nazwa;// nazwa pliku z danymi
	
	while (1) {// menu obslugi struktury
		system("cls");
		cout << "Wybierz funkcje. \n1.Wczytanie liczb \n2.Usuwanie liczb \n3.Wyszukanie liczby \n4.Wyswietl\n5.Dodaj liczbe \n6.Wyjdz" << endl;
		cin >> wybor;
		switch (wybor) {
		case 1:
			system("cls");
			if (struktura.dlugosc == 0) {

				cout << "Wpisz nazwe pliku." << endl;
				cin >> nazwa;  //plik z danymi
				plik.open(nazwa, fstream::in);
				cout << "Wpisz index do wstawienia elementow." << endl;
				cin >> index;//index do wstawienia liczb 
				//aby wstawic na ostatnie miejsce trzeba podac liczbe >=ilosci liczb w pliku
				plik >> ilosc;//ilosc danych
				start = read_QPC();
				for (int i = 0; i < ilosc; i++) {
					plik >> temp;
					tmp = temp % INT_MAX;
					struktura.dodajElement(tmp, index);
				}
				elapsed = read_QPC() - start; //policzenie minionego czasu
				czas = (1000000.0 * elapsed) / frequency;
				wyniki <<"TD "<< czas << " " << ilosc << " " << (czas / ilosc) << endl;//zapis wyniku do pliku
				cout << "Czas calkowity = " << czas << ", czas na element= " << (czas / ilosc) << endl;
				plik.close();
				_getch();
			}
			else {
				cout << "Struktura jest pelna. Najpierw ja oproznij." << endl;
				_getch();
			}
			break;
		case 2:
			system("cls");
			if (struktura.dlugosc == 0) {
				cout << "Strutkura jest pusta" << endl;
				_getch();
			}
			else {
				cout << "Ile elementow usunac (dlugosc = " << ilosc << " )." << endl;
				cin >> ile;//dlugosc usuwanego ciagu danych
				ilosc -= ile;
				cout << "Wpisz index do usuwania elementow." << endl;
				cin >> index;//poczatek ciagu
				start = read_QPC();
				for (int i = 0; i < ile; i++) {
					struktura.usunElement(index);
				}
				elapsed = read_QPC() - start; //policzenie minionego czasu
				czas = (1000000.0 * elapsed) / frequency;
				wyniki <<"TU "<< czas << " " << ile << " " << (czas / ile) << endl;//zapis wyniku
				cout << "Czas calkowity = " << czas << ", czas na element= " << (czas / ile) << endl;
				_getch();
			}
			break;
		case 3:
			system("cls");
			cout << "Podaj szukana liczbe." << endl;
			cin >> szukana;//szukana liczba
			start = read_QPC();
			szukanie = struktura.wyszukaj(szukana);//metoda zwraca index szukanej liczby
			elapsed = read_QPC() - start; //policzenie minionego czasu
			czas = (1000000.0 * elapsed) / frequency;
			wyniki <<"TS "<< czas << endl;//zapis do pliku

			if (szukanie >= 0) { 
				cout << "Liczba znajduje się na indexie= " << szukanie << endl; 
			}
			cout << "Czas szukania=" << czas << endl;
			_getch();
			break;
		case 4:
			system("cls");
			if (struktura.dlugosc == 0) {
				cout << "Struktura jest pusta" << endl;
				_getch();
			}
			else {
				struktura.wyswietl();
				_getch();
			}
			break;
		case 5:
			ilosc++;
			system("cls");
			cout << "Podaj liczbe" << endl;
			cin >> liczba;
			cout << "1.Na poczatek\n2.Na koniec\n3.Na index" << endl;
			cin >> wybor;
			switch (wybor)
			{
			case 1:
				index = 0;
				break;
			case 3:
				cout << "Podaj index" << endl;
				cin >> index;
				break;
			default:
				index = ilosc;
				break;
			}
			
			start = read_QPC();
			struktura.dodajElement(liczba, index);
			elapsed = read_QPC() - start; //policzenie minionego czasu
			czas = (1000000.0 * elapsed) / frequency;
			wyniki << "TD " << czas << endl;//zapis wyniku do pliku
			cout << "Czas calkowity = " << czas<< endl;
			_getch();
			break;
		case 6:
			struktura.dekontruktor();//usuwanie pozostalosci po strukturze
			return;
			break;
		}
	}
}



void Lista() {
	lista struktura;//badana struktura
	int wybor = 1;
	long long int ilosc;//ilosc danychw sturkturze

	long long int temp; // rzutowanie na int błednych wynikow
	int tmp;

	int index;//zmienna uzywana przy usuwaniu z indexu

	int szukanie;//index poszukiwanej liczby
	int szukana;//szukana liczba

	int ile; // ilosc liczb do usuniecia
	int liczba;
	string nazwa;// nazwa pliku z danymi

	while (1) {// menu obslugi struktury
		system("cls");
		cout << "Wybierz funkcje. \n1.Wczytanie liczb \n2.Usuwanie liczb \n3.Wyszukanie liczby \n4.Wyswietl \n5.Dodaj liczbe \n6.Wyjdz" << endl;
		cin >> wybor;
		switch (wybor) {
		case 1:
			system("cls");
			if (struktura.dlugosc == 0) {

				cout << "Wpisz nazwe pliku." << endl;
				cin >> nazwa;  //plik z danymi
				plik.open(nazwa, fstream::in);
				cout << "Wpisz index do wstawienia elementow." << endl;
				cin >> index;//index do wstawienia liczb 
				//aby wstawic na ostatnie miejsce trzeba podac liczbe >=ilosci liczb w pliku
				plik >> ilosc;//ilosc danych
				start = read_QPC();
				for (int i = 0; i < ilosc; i++) {
					plik >> temp;
					tmp = temp % INT_MAX;
					struktura.dodajElement(tmp, index);
				}
				elapsed = read_QPC() - start; //policzenie minionego czasu
				czas = (1000000.0 * elapsed) / frequency;
				wyniki << "TD " << czas << " " << ilosc << " " << (czas / ilosc) << endl;//zapis wyniku do pliku
				cout << "Czas calkowity = " << czas << ", czas na element= " << (czas / ilosc) << endl;
				plik.close();
				_getch();
			}
			else {
				cout << "Struktura jest pelna. Najpierw ja oproznij." << endl;
				_getch();
			}
			break;
		case 2:
			system("cls");
			if (struktura.dlugosc == 0) {
				cout << "Strutkura jest pusta" << endl;
				_getch();
			}
			else {
				cout << "Ile elementow usunac (dlugosc = " << ilosc << " )." << endl;
				cin >> ile;//dlugosc usuwanego ciagu danych
				ilosc -= ile;
				cout << "Wpisz index do usuwania elementow." << endl;
				cin >> index;//poczatek ciagu
				start = read_QPC();
				for (int i = 0; i < ile; i++) {
					struktura.usunElement(index);
				}
				elapsed = read_QPC() - start; //policzenie minionego czasu
				czas = (1000000.0 * elapsed) / frequency;
				wyniki << "TU " << czas << " " << ile << " " << (czas / ile) << endl;//zapis wyniku
				cout << "Czas calkowity = " << czas << ", czas na element= " << (czas / ile) << endl;
				_getch();
			}
			break;
		case 3:
			system("cls");
			cout << "Podaj szukana liczbe." << endl;
			cin >> szukana;//szukana liczba
			start = read_QPC();
			szukanie = struktura.wyszukaj(szukana);//metoda zwraca index szukanej liczby
			elapsed = read_QPC() - start; //policzenie minionego czasu
			czas = (1000000.0 * elapsed) / frequency;
			wyniki << "TS " << czas << endl;//zapis do pliku

			if (szukanie >= 0) {
				cout << "Liczba znajduje się na indexie= " << szukanie << endl;
			}
			cout << "Czas szukania=" << czas << endl;
			_getch();
			break;
		case 4:
			system("cls");
			if (struktura.dlugosc == 0) {
				cout << "Struktura jest pusta" << endl;
				_getch();
			}
			else {
				struktura.wyswietl();
				_getch();
			}
			break;
		case 5:
			system("cls");
			cout << "Podaj liczbe" << endl;
			cin >> liczba;
			cout << "1.Na poczatek\n2.Na koniec\n3.Na index" << endl;
			cin >> wybor;
			ilosc++;
			switch (wybor)
			{
			case 1:
				index = 0;
				break;
			case 3:
				cout << "Podaj index" << endl;
				cin >> index;
				break;
			default:
				index = ilosc;
				break;
			}
			start = read_QPC();
			struktura.dodajElement(liczba, index);
			elapsed = read_QPC() - start; //policzenie minionego czasu
			czas = (1000000.0 * elapsed) / frequency;
			wyniki << "TD " << czas << endl;//zapis wyniku do pliku
			cout << "Czas calkowity = " << czas << endl;
			_getch();
			break;
		case 6:
			struktura.dekontruktor();//usuwanie pozostalosci po strukturze
			return;
			break;
		}
	}
}



void Kopiec() {

	kopiec struktura;//badana struktura
	int wybor = 1;
	long long int ilosc;//ilosc danychw sturkturze

	long long int temp; // rzutowanie na int błednych wynikow
	int tmp;

	int index;//zmienna uzywana przy usuwaniu z indexu

	int szukanie;//index poszukiwanej liczby
	int szukana;//szukana liczba

	int ile; // ilosc liczb do usuniecia
	int liczba;
	string nazwa;// nazwa pliku z danymi


	while (1) {
		system("cls");
		cout << "Wybierz funkcje. \n1.Wczytanie liczb \n2.Usuwanie liczb \n3.Wyszukanie liczby \n4.Wyswietl  \n5.Dodaj liczbe \n6.Wyjdz" << endl;
		cin >> wybor;
		switch (wybor) {
		case 1:
			system("cls");
			if (struktura.dlugosc == 0) {

				cout << "Wpisz nazwe pliku." << endl;
				cin >> nazwa;//wcztanie pliku z danymi
				plik.open(nazwa, fstream::in);
				plik >> ilosc;
				start = read_QPC();
				for (int i = 0; i < ilosc; i++) {
					plik >> temp;
					tmp = temp % INT_MAX;
					struktura.dodajElement(tmp);
				}
				elapsed = read_QPC() - start; //policzenie minionego czasu
				czas = (1000000.0 * elapsed) / frequency;
				wyniki <<"KD "<< czas << " " << ilosc << " " << (czas / ilosc) << endl;//zapis do pliku
				cout << "Czas calkowity = " << czas << ", czas na element= " << (czas / ilosc) << endl;
				plik.close();
				_getch();
			}
			else {
				cout << "Struktura jest pelna. Najpierw ja oproznij." << endl;
				_getch();
			}
			break;
		case 2:
			system("cls");
			if (struktura.dlugosc == 0) {
				cout << "Strutkura jest pusta" << endl;
				_getch();
			}
			else {
				cout << "Ile elementow usunac (dlugosc = " << ilosc << " )." << endl;//ilosc powtorzen 
				cin >> ile;//po usunieciu elemtnu nastpeuje naprawa drzewa a podana ile jest ilosci apowtorzen takiego cyklu
				ilosc -= ile;
				start = read_QPC();
				for (int i = 0; i < ile; i++) {
					struktura.usunElement(0);
				}
				elapsed = read_QPC() - start; //policzenie minionego czasu
				czas = (1000000.0 * elapsed) / frequency;
				wyniki <<"KU " << czas << " " << ile << " " << (czas / ile) << endl;//zapis do pliku
				cout << "Czas calkowity = " << czas << ", czas na element= " << (czas / ile) << endl;
				_getch();
			}
			break;
		case 3:
			system("cls");
			cout << "Podaj szukana liczbe." << endl;
			cin >> szukana;
			start = read_QPC();
			szukanie = struktura.wyszukaj(szukana);
			elapsed = read_QPC() - start; //policzenie minionego czasu
			czas = (1000000.0 * elapsed) / frequency;
			wyniki <<"KS "<< czas << endl;
			if (szukanie >= 0)cout << "Liczba znjaduje się na indexie= " << szukanie << endl;
			cout << "Czas szukania=" << czas << endl;
			_getch();
			break;
		case 4:
			system("cls");
			if (struktura.dlugosc == 0) {
				cout << "Strutkura jest pusta" << endl;
				_getch();
			}
			else {
				struktura.wyswietl();
				_getch();
			}
			break;
		case 5:
			ilosc++;
			system("cls");
			cout << "Podaj liczbe" << endl;
			cin >> liczba;
			start = read_QPC();
			struktura.dodajElement(liczba);
			elapsed = read_QPC() - start; //policzenie minionego czasu
			czas = (1000000.0 * elapsed) / frequency;
			wyniki << "TD " << czas << endl;//zapis wyniku do pliku
			cout << "Czas calkowity = " << czas << endl;
			_getch();
			break;
		case 6:
			struktura.dekontruktor();//usuwanie pozostalosci po strukturze
			return;
			break;
		}
	}
}






int main() {
	QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
	wyniki.open("wyniki.txt", fstream::out);  //wyniki testow sa zapisywane w tym pliku (z wyjatkami) 
	//format wyniku 
	// T L K - struktura (tablica, lista, kopiec)
	// D U S - akcja (dodawanie, usuwanie, szukanie)
	// calkowity czas
	// ilosc elemntow
	// czas dla jednego elementu

	int wybor = 1;

	while(1) {  //menu glowne 
		system("cls");
		cout << "Wybierz sturture do testow. \n1.Tablica \n2.Lista \n3.Kopiec \n4.Wyjdz" << endl;
		cin >> wybor;
		switch (wybor) {
		case 1:
			Tablica();  //testowanie tablicy 
			break;
		case 2:
			Lista();//testowanie listy 
			break;
		case 3:
			Kopiec();//testowanie kopca 
			break;
		case 4:
			return 0;
			break;
		}
	}
	wyniki.close();  
	return 0;
}
