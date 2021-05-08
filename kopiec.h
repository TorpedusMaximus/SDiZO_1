

class kopiec
{
public:
	int* struktura;
	int dlugosc=0;
	void naprawa(int indeksNaprawy);
	void dodajElement(int n);
	void wyswietl();
	void usunElement(int index);
	int wyszukaj(int x);
	void dekontruktor();
	~kopiec();

};

