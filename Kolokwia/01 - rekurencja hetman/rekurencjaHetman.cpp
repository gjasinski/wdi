#include <iostream>

using namespace std;
const int N=8;
int tab[N][N];
void wypisz();
bool czyMozliwe(int w, int k);
void ustawiajHetmana(int k);
int licz=0;
int main()
{
/*
    Program wyszukujący ustawienia hetmanów tak aby nie atakowały się nawzajem.
    Rozwiązanie rekurencyjne.
    Tablica hetmanów jest NxN typu bool.
*/
    ustawiajHetmana(0);
    cout<<licz;
}

//Sprawdzanie czy jest jakis herman kolejnow  wierszu, kolumnie, po skosach.
bool czyMozliwePoziomo(int w, int k)
{
    for(int i=0;i<N;i++)
    {
        if(tab[w][i]==true) return false;
    }
    return true;
}

bool czyMozliwePionowo(int w, int k)
{
    for(int i=0;i<N;i++)
    {
        if(tab[i][k]==true) return false;
    }
    return true;
}

bool czyMozliweUkos(int w, int k)
{
    for(int i=w, j=k;i>=0 and j>=0;i--, j--)
    {
        if(tab[i][j]==true)return false;
    }
    for(int i=w, j=k;i<N and j<N;i++, j++)
    {
        if(tab[i][j]==true)return false;
    }
    for(int i=w, j=k;i>=0 and j<N;i--, j++)
    {
        if(tab[i][j]==true)return false;
    }
    for(int i=w, j=k;i<N and j>=0;i++, j--)
    {
        if(tab[i][j]==true)return false;
    }
    return true;
}

bool czyMozliwe(int w, int k)
{
    //Połączenie sprawdzania obecności hetmanóœ
    //Spowodowane poprzez początkowe inna koncepcje rozwiazania.
    bool dasie=true;
    if(dasie) dasie=czyMozliwePionowo(w,k);
    if(dasie) dasie=czyMozliwePoziomo(w,k);
    if(dasie) dasie=czyMozliweUkos(w,k);
    return dasie;
}

void wypisz()
{
    //wypisanie na ekran szachownicy z ustawieniem
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(tab[i][j]) cout<<" H "; else cout<<" - ";
        }
        cout<<endl;
    }
    cout<<endl;
    licz++;
    //int t;
    //cin>>t;
}

void ustawiajHetmana(int k)
{
/*
    Rekurencyjne szukanie pozycji hetmanów.
    Przesuawamy się po kolumnach az do ostatniej.
    Gdy jest możliwe ustawienie hetmana wywołujemy rekurencje.
    Gdy rekurencja wraca usuwamy tego hetmana i próbujemy go ustawić dalej.
*/
    int stop;
    if(k<N){
        for(int i=0;i<N;i++)
        {
            if(czyMozliwe(i,k))
            {
                tab[i][k]=true;
                ustawiajHetmana(k+1);
                if(k==N-1)wypisz();
                tab[i][k]=false;
            }
        }
    }
}
