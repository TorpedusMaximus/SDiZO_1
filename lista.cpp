#include "lista.h"
#include <iostream>
using namespace std;

struct elementListy {  //definicja struktury elementu 
    int wartosc;
    elementListy* nastepnyElement;
    elementListy* poprzedniElement;
};


void lista::wyswietl() {
     if (koniec == NULL) {   //sprawdzenie istenienia struktury
        return;
    }

     struct elementListy* temp = poczatek;  //zmienna pomocnicza

    while (temp != NULL) {
        cout << temp->wartosc << " ";
        temp = temp->nastepnyElement;
    }
    cout << endl;

}

 void lista::usunElement(int n) {

     if (n < 0 ) {  //sprawdzenie poprawnosci wprowadzonego indexu 
         n = 0;
     }
     if (n >= dlugosc) {
         n = dlugosc - 1;
     }

     if (dlugosc <=1) {
         delete koniec;
         koniec = NULL;
         poczatek = NULL;
         dlugosc=0;
         return;
     }

    dlugosc--;  
    struct elementListy* temp = poczatek;  //zmienna pomocnicza

    for (long long int i = 0; i < n; i++) {  //wyszukanie elementu o podanym idexie
        if (temp->nastepnyElement == NULL) {
            break;
        }
        temp = temp->nastepnyElement;  
    }  

    if (temp == poczatek) {
        poczatek->nastepnyElement->poprzedniElement = NULL;
        poczatek = poczatek->nastepnyElement;
        delete[] temp;
        return;
    }

    if (temp == koniec) {
        koniec = koniec->poprzedniElement;
        koniec->nastepnyElement = NULL;
        delete[] temp;
        return;
    }

    temp->poprzedniElement->nastepnyElement = temp->nastepnyElement;
    temp->nastepnyElement->poprzedniElement = temp->poprzedniElement;

    delete temp;
}

 int lista::wyszukaj(int x)
 {
     struct elementListy* temp = poczatek;  // zmienna pomocnicza
     long long int i = 0;
     while (temp->nastepnyElement!=NULL) {
         if (temp->wartosc==x) {
             return i;  //zwraca index szukanej liczby
         }
         i++;
         temp = temp->nastepnyElement;
     }
     cout << "Brak elementu." << endl;
     return -1;  // brak elementu zwraca index -1
 }

 void lista::dekontruktor()
 {
     while (dlugosc > 0) {
         usunElement(0);
     }
 }

 lista::~lista()
 {
     while (dlugosc > 0) {
         usunElement(0);
     }
 }


void lista::dodajElement(int n,int index){
    struct elementListy* nowyElement = new elementListy;  // nowy element listy 
    dlugosc++;
    
    nowyElement->wartosc = n;
    nowyElement->poprzedniElement = NULL;
    nowyElement->nastepnyElement = NULL;

    if (koniec == NULL) { //wariant gdy dodany element jest pierwszy w liscie 
        koniec = nowyElement;
        poczatek = nowyElement;
        return;
    }
    if (index == 0) {
        poczatek->poprzedniElement = nowyElement;
        nowyElement->nastepnyElement = poczatek;
        poczatek = nowyElement;
        return;
    }

    index--;
    struct elementListy* temp = poczatek;  //zmienna pomocnicza
    for (int i = 0; i <= index; i++) {  //wyszukanie elementu o podanym idexie
        if (temp->nastepnyElement == NULL || i == index) {
            nowyElement->poprzedniElement = temp;

            if (temp->nastepnyElement != NULL) {
                temp->nastepnyElement->poprzedniElement = nowyElement;
                nowyElement->nastepnyElement = temp->nastepnyElement;
            }
            temp->nastepnyElement = nowyElement;

            if (koniec->nastepnyElement != NULL) {
                koniec = koniec->nastepnyElement;
            }
            break;
        }
        temp = temp->nastepnyElement;
    }

    
}

