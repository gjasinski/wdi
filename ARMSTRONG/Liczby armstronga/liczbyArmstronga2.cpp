#include <iostream>
#include <fstream>

/*
Kodowanie liczb(10)
tablica[0] - bit o najwiekszej wartosci
tablica[n-1] bit o najmniejszej wartości
*/

using namespace std;

const int tsize=39;
fstream plik( "liczbyArmstronga.txt", ios::out );

void generujLiczby(int tab[tsize]);
void generujLiczbyZZerami(int tab[tsize]);

int main()
{
    int tablica[tsize];
    for (int i=0;i<tsize;i++) tablica[i]=0;
    tablica[tsize-1]=1;
    //generujLiczby(tablica);
    generujLiczbyZZerami(tablica);
}

void wypisz(int tab[tsize])
{
    int i=0;
    while(tab[i]==0)i++;
    for (i;i<tsize;i++) plik<<tab[i];
    plik<<endl;
}
/*
{
    int i=0;
    while(tab[i]==0)i++;
    for  (i;i<tsize;i++) cout<<tab[i];
    cout<<endl;
}*/

//dodawanie 2 liczb
//wynik w w[tsize]
//zwraca false w przypadku przekroczenia zakresu
void dodawanie(int w[tsize], int t2[tsize])
{
    int j=tsize-1;
    while(t2[j]==0)j--;
    for (j;j>=0;j--) w[j]+=t2[j];
}

bool sprzatajLiczbe(int l[tsize], int rozmiar)
{
    int i=tsize-1;
    int tmp=0;
    do
    {
        tmp+=l[i];
        l[i]=tmp%10;
        tmp/=10;
        i--;
    } while (i>=0);
    i=0;
    while(l[i]==0)i++;
    if((tsize-i)!=rozmiar)return false;
    return tmp==0;
}
//mnozenie liczby o rozmiarze do 60 i 1
//zwraca false w przypadku przeroczenia zakresu
bool mnozenie(int t1[tsize], int m)
{
    int tmp=0;
    for (int i=tsize-1;i>=0;i--)
    {
        t1[i]*=m;
        tmp+=t1[i];
        t1[i]=tmp%10;
        if(i==0 and tmp>9)return false;
        tmp/=10;
    }
    return true;
}

//funkcja uzupelnia tablice poteg
void uzupelnijTablicePoteg(int t[10][tsize])
{
    for (int i=2;i<10;i++)
    {
        if(!mnozenie(t[i],i)){cout<<"Funkcja uzupelnijTablicePoteg - PRZEKROCZENIE ZAKRESU TABLICY INDEKS: "<<i<<endl;}
    }
}

//Zwraca true gdy liczby są takie same, false gdy są różne
//Liczby uzanjemy za takie same gdy mają taką sama ilość takich samuch cyfr
//Ponieważ nie generujemy wszystkich liczb, a jedynie kombinacje liczb
//np: 12, 13, 14, 23, 24, 34
//Dwie takie same liczby:
//556211==155126
bool takieSameLiczby(int t1[tsize],int t2[tsize], int stopien)
{
    int s1, s2;
    s1=tsize-1;
    while (s1>0 and t1[s1]==0 and t2[s1]==0) s1--;

    if(t1[s1]==0 or t2[s1]==0) return false;
    s2=s1;

    int tab[10][2];
    for (int i=1;i<10;i++) tab[i][0]=tab[i][1]=0;
    while (s1>=0)
    {
        tab[t1[s1]][0]++;
        tab[t2[s1]][1]++;
        s1--;
    }

    for (int i=1;i<10;i++) if (tab[i][0]!=tab[i][1]) return false;
    wypisz(t2);
    if (t2[tsize-1]==1)
    {
        t2[tsize-1]=0;
        wypisz(t2);
    }
    return true;
}

//true - liczba jest liczba armstronga
//false - liczba nie jest liczba armstroga
bool sprawdzajWarunki(int tab[tsize], int t[10][tsize], int stopien)
{
    int liczba[tsize];
    for(int i=0;i<tsize;i++)liczba[i]=0;
    for (int i=tsize-1; i>=0; i--)
    {
        if(tab[i]>1) dodawanie(liczba,t[tab[i]]);
        else if(tab[i]==1) liczba[tsize-1]++;
    }
    if(!sprzatajLiczbe(liczba,stopien)) return false;
    return takieSameLiczby(tab,liczba,stopien);
}

void gen(int tab[tsize], int t[10][tsize], int x, int stopien)
{
    int i=tsize-1;
    int tmp,tmpi, rozmiar,w;
    rozmiar=1;
    while (tab[x]!=9)
    {
        tab[i]++;
        if(tab[i]>9)
        {
            tmpi=i-1;
            while(tab[tmpi]==9 and tmpi>=0) tmpi--;
            tab[tmpi]++;
            tmp=tab[tmpi];

            for (tmpi;tmpi<tsize;tmpi++)
            {
                tab[tmpi]=tmp;
            }

        }
        sprawdzajWarunki(tab,t,stopien);
    }
}
void gen2(int tab[tsize], int t[10][tsize], int d[10][tsize], int x, int stopien)
{
    int i=tsize-1;
    int tmp,tmpi, rozmiar,w;
    rozmiar=1;
    while (tab[x]!=9)
    {
        tab[i]++;
        if(tab[i]>9)
        {
            tmpi=i-1;
            while(tab[tmpi]==9 and tmpi>=0) tmpi--;
            tab[tmpi]++;
            tmp=tab[tmpi];

            for (tmpi;tmpi<tsize;tmpi++)
            {
                tab[tmpi]=tmp;
            }

        }
        sprawdzajWarunki(tab,t, stopien);
        sprawdzajWarunki(tab,d, stopien-1);
    }
}
void generujLiczbyZZerami(int tab[tsize])
{
    int t[10][tsize];
    int d[10][tsize];
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<tsize-1;j++) t[i][j]=d[i][j]=0;
        t[i][tsize-1]=d[i][tsize-1]=1;
    }
    t[0][tsize-1]=0;
    uzupelnijTablicePoteg(t);
    uzupelnijTablicePoteg(t);
    uzupelnijTablicePoteg(d);
    for (int stopien=3;stopien<=tsize;stopien++)
    {
        uzupelnijTablicePoteg(t);
        uzupelnijTablicePoteg(d);
        tab[tsize-stopien]=0;
        for(int i=stopien-1;i>=0;i--) tab[tsize-i]=1;
        tab[tsize-1]=0;
        gen2(tab, t, d, tsize-stopien+1,stopien);

        for (int j=stopien-1;j>2;j--)
        {
            tab[tsize-j]=0;
            for(int i=j-1;i>=0;i--) tab[tsize-i]=1;
            tab[tsize-1]=0;
            gen(tab, t, tsize-j+1,stopien);
        }
    }
}
