#include "tablica.h"
#include <malloc.h>
#include <iostream>

using namespace std;

void tablica::dodajElement(int n,int index)
{
	if (index < 0) {
		index = 0;
	}
	
	if (index > dlugosc) {
		index = dlugosc;
	}
	dlugosc++;

	int* temp = new int[dlugosc];  //zmienna pomocnicza
	int i = 0;
	while (i < index ) {  //przekopiowanie zawartosci struktury do zmiennej pomocniczej 
		temp[i] = struktura[i];
		i++;
	}
    temp[i] = n;
	i++;
	while (i<dlugosc) {  //przesuniecie w [prawo od wstawionej zmiennej 
		temp[i] = struktura[i-1];
		i++;
	}
	delete[] struktura;
	struktura = temp;
	
}

void tablica::usunElement(int index)
{
	if (dlugosc <= 0) {
		return;
	}
	if (index < 0 ) {  //ochrona przed blednymi danymi 
		index = 0;
	}
	if (index >= dlugosc) {
		index = dlugosc - 1;
	}

	dlugosc--;
	int* temp = new int[dlugosc];  //zmienna pomocnicza
	int i = 0;
	while (i < index) {  //przekopiowanie zawartosci struktury do zmiennej pomocniczej 
		temp[i] = struktura[i];
		i++;
	}
	while (i < dlugosc) {  //przesuniecie w [prawo od wstawionej zmiennej 
		temp[i] = struktura[i + 1];
		i++;
	}
	
	delete[] struktura;
	struktura = temp;

}

void tablica::wyswietl()
{
	for (int i = 0; i < dlugosc; i++) {  
		cout << struktura[i] << " ";
	}
	cout << endl;
}

int tablica::wyszukaj(int x)
{
	int i=0;
	while (1) {
		if (i >= dlugosc) {
			cout << "Brak elementu" << endl; //zwraca b³êdny informacje o braku indexu
			return -1;
		}
		if (struktura[i] == x) {
			return i;
		}
		i++;
	}
}

void tablica::dekontruktor()
{
	while (dlugosc > 0) {
		usunElement(0);
	}
}

tablica::~tablica()
{
	while (dlugosc > 0) {
		usunElement(0);
	}
}





