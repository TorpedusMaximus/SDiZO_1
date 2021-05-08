#pragma once
class tablica
{
public:
	int* struktura;
	int dlugosc = 0;

	void dodajElement(int n, int index);
	void usunElement(int index);
	void wyswietl();
	int wyszukaj(int x);
	void dekontruktor();
	~tablica();

};

