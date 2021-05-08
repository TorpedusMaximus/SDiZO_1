#include<IOSTREAM>
class lista
{
public:
	long long int dlugosc=0;
	struct elementListy* koniec=NULL; //poczatek listy 
	struct elementListy* poczatek=NULL;  //ostaatni elemnt listy 
	void dodajElement(int n,int index);
	void wyswietl();
	void usunElement(int n);
	int wyszukaj(int x);
	void dekontruktor();
	~lista();
};

