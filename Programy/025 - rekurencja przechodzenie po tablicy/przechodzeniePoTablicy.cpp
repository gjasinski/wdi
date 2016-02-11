#include <iostream>
#include <stdlib.h>
using namespace std;
const int N=3;
int tab[N][N];

void losujTablice();
bool droga(int w, int k, int wk, int kk);
int main()
{
//Przykladowa tablica dla ktorej jest mozliwe przejscie
//Na 99% tablic randomowych sie nie da przejsc.
//    tab[0][0]=10;
//    tab[0][1]=5;
//    tab[0][2]=8;
//    tab[1][0]=3;
//    tab[1][1]=8;
//    tab[1][2]=1;
//    tab[2][0]=4;
//    tab[2][1]=2;
//    tab[2][2]=0;

    if(droga(0,0,N-1,N-1))cout<<"dasie"; else cout<<"niedasie";
}

void losujTablice()
{
    //Funkcja losująca randomowo liczby do tablicy
    srand(time(NULL));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            tab[i][j]=rand()%1000;
    }

}
bool droga(int w, int k, int wk, int kk)
{
/*
    Funkcja rekurencyjna szukajaca drogi przez tablice,
    mozna isc tylko w dol lub prawo, jeżeli wartość w tablicy tam gdzie chcemy iść jest mniejsza niż w elemencie tablicy w którym jesteśmy.
    Zwraca wartość logiczna t/f.
*/
    if(w==N-1 and k==N-1) return true;
    bool dol, prawo;
    dol=prawo=false;
    if(w<wk and tab[w][k]>tab[w+1][k]) dol=droga(w+1,k,wk,kk);
    if(k<kk and !dol and tab[w][k]>tab[w][k+1]) prawo=droga(w,k+1,wk,kk);
    return dol or prawo;
}
