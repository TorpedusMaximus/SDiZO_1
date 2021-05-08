#include "kopiec.h"
#include <iostream>
using namespace std;


void kopiec::dodajElement(int n)
{
    dlugosc++;
    int* temp = new int[dlugosc];   //zmienna pomocnicza
    for (int i = 0; i < dlugosc-1; i++) {  //przekopiowanie zawartosci struktury do zmiennej pomocniczej 
        temp[i] = struktura[i];
    }
    delete[] struktura;
    struktura = temp;  //wyczyszczecnie danych pryzpisanie nowego wskaznika
    struktura[dlugosc - 1] = n;
    if (dlugosc > 1) { 
        naprawa(dlugosc-1);  //uruchowmienie naprawy po dodaniu
    }
}

void kopiec::wyswietl() {
    if (dlugosc == 0) {  //sprawdzenie czy struktura nie jest pusta

    }
    else {
        int nowaLinia = 0; //zmienna przejcia do nowej linii
        for (int i = 0; i < dlugosc; i++) {
            cout << struktura[i] << " ";
 
            if (i == nowaLinia) {  //przejscie do nowej linii i zmiana wartosci sprawdzanej 
                cout << endl;
                nowaLinia=nowaLinia*2+2;
            }
        }
        cout << endl;
    }
    
}

void kopiec::naprawa(int index) {
    int rodzic = (index - 1) / 2;  //wyszukanie rodzica
    while (rodzic >= 0) {  //droga wyszukiwan rodzicow az do pierwszego miejsca
        rodzic = (index - 1) / 2;  

        if (struktura[index ] > struktura[rodzic]) {
            int temp = struktura[rodzic];  //przekopiowanie zawartosci struktury do zmiennej pomocniczej 
            struktura[rodzic] = struktura[index];
            struktura[index ] = temp;
            index = rodzic;  //zamiana badanego elementu na rodzica
        }
        else{
            break;
        }
    }
}

void kopiec::usunElement(int x)
{
    if (x < 0 || x >= dlugosc) {  //badanie prawidlowej dlugosci
        x = 0;
    }
    struktura[x] = struktura[dlugosc - 1];  //przenisienie ostatniej liczby na miejsce 0
    
    int temp,lewy,prawy;
    while (x < dlugosc) { 

        if (2 * x + 1 < dlugosc) {  //wyszukanie lewego i prawego dziecka
           lewy = struktura[2 * x + 1];
        }
        else {
            lewy = INT_MIN;  //zabezpieczenie przed brakiem potomkow
        }
        if (2 * x + 2 < dlugosc) {
            prawy = struktura[2 * x + 2];
        }
        else {
            prawy = INT_MIN;
        }
        
       
        if (lewy > prawy) {

            if (struktura[x] < lewy) {  //jesli konieczna zamiana rodzica z dzieckiem 
                temp = struktura[x];
                struktura[x] = struktura[2 * x + 1];
                struktura[2 * x + 1] = temp;
                x = 2 * x + 1;
            }
            else {
                break;
            }
            
        }
        else {
            if (struktura[x] < prawy) {  //jesli konieczna zamiana rodzica z dzieckiem 
                temp = struktura[x];
                struktura[x] = struktura[2 * x + 2];
                struktura[2 * x + 2] = temp;
                x = 2 * x + 2;
            }
            else {
                break;
            }
            
        }
    }

    dlugosc--;
    if (dlugosc == 0) {
        delete[] struktura;
        return;
    }
    int* tmp = new int[dlugosc];  //przekopiowanie danych do nowej struktury i usuniecie starej
    for (int i = 0; i < dlugosc; i++) {
        tmp[i] = struktura[i];
    }
    delete[] struktura;
    struktura = tmp;

}

int kopiec::wyszukaj(int x)
{
    int i = 0;
    while (1) {  
        if (i >= dlugosc) {//brak szukanej liczby skutkuje wartoscia indexu -1
            cout << "Brak elemntu" << endl;
            return -1;
        }
        if (struktura[i] == x) {
            return i;
        }
        i++;
    }
}

kopiec::~kopiec()
{
    while (dlugosc > 0) {
        usunElement(0);
    }
}

void kopiec::dekontruktor()
{
    while (dlugosc > 0) {
        usunElement(0);
    }
}

