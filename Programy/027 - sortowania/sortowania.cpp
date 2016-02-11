#include <iostream>
const int N=10;

using namespace std;

bool wyszukiwanie_polowkowe(int tab[], int liczba);
void proste_wstawianie_wartownik(int tab[]);
void proste_wstawianie_wyszkiwanie_polowkowe(int tab[]);
void proste_wybieranie(int tab[]);
void proste_combsort(int tab[]);
void quick_sort(int tab[],int l, int p);
void wypisz(int tab[]){for(int i=0;i<N;i++)cout<<tab[i]<<endl;}
int main()
{
    int tablica[N]={5,11,56,32,6,1,99,34,1234,32};
    if(wyszukiwanie_polowkowe(tablica,6)) cout<<"OK";
    wypisz(tablica);
    cout<<endl;
    //sortowanieprzezwstawianieWartownik(tablica);
    //sortowanieprzezwstawianieWstawianiePolowkowe(tablica);
    //proste_wybieranie(tablica);
    //proste_combsort(tablica);
    quick_sort(tablica,0,N-1);

    wypisz(tablica);

}

//+/-1 poniewaz gdy l+p bedzie liczba nie parzysta to wskaznik nam przesunie sie nenaturalnie
bool wyszukiwanie_polowkowe(int tab[], int liczba)
{
    int l,p,s;
    l=0;
    p=N-1;
    while(l<=p)
    {
        s=(l+p)/2;
        if(tab[s]==liczba)return true;
        if(tab[s]<liczba) l=s+1;
        else p=s-1;
    }
    return tab[s]==liczba;
}
//sortujemy tablice od 1 don N-1, 0 to wartownik
//jest to sortwanie stabilne
void proste_wstawianie_wartownik(int tab[])
{
    int tmp,j;
    for(int i=1;i<N;i++)
    {
        tmp=tab[i];
        j=i-1;
        tab[0]=tmp;
        while(tmp<tab[j])
        {
            tab[j+1]=tab[j];
            j--;
        }
        tab[j+1]=tmp;
    }
}
//sortujemy tablice od 1 don N-1, 0 to wartownik
//jest to sortwanie stabilne
void proste_wstawianie_wyszkiwanie_polowkowe(int tab[])
{
    int tmp,l,p,s;
    for(int i=1;i<N;i++)
    {
        l=0;
        p=i-1;
        tmp=tab[i];
        while(l<=p)
        {
            s=(l+p)/2;
            if(tmp<tab[s]) p=s-1;
            else l=s+1;
        }
        for(int j=i-1;j>=l;j--) tab[j+1]=tab[j];
        tab[l]=tmp;
    }
}
void swap(int &a, int &b)
{
    int tmp =a;
    a=b;
    b=tmp;
}
//wyszukiwanie najmniejszego elementu w tablicy od i+1 do N
//zamiana elementu i z minimum
void proste_wybieranie(int tab[])
{
    int k;
    for(int i=0;i<N;i++)
    {
        k=i;
        for(int j=i+1;j<N;j++)
            if(tab[j]<tab[k]) k=j;
        swap(tab[k],tab[i]);
    }
}
/*
Sortowanie bombelkowe:
-standardowa wersja
-petla wew zaczyna sie od elementu o indeksie i
-sprawdzanie czy byla jakas zmiana dokonana
*/
void proste_combsort(int tab[])
{
    int wsp =N;
    while(wsp>1)
    {
        wsp=max(int(wsp/1.3),1);
        for(int i=0;i+wsp<N;i++)
        {
            if(tab[i]>tab[i+wsp])
            {
                swap(tab[i],tab[i+wsp]);
            }
        }
    }
}
/*
Sortowanie bombelkowe:
-standardowa wersja
-petla wew zaczyna sie od elementu o indeksie i
-sprawdzanie czy byla jakas zmiana dokonana
*/
void proste_combsort11(int tab[])
{
    int wsp =N;
    while(wsp>1)
    {
        wsp=max(int(wsp/1.3),1);
        if(N>11 and (wsp==9 or wsp==10)) wsp=11;
        for(int i=0;i+wsp<N;i++)
        {
            if(tab[i]>tab[i+wsp])
            {
                swap(tab[i],tab[i+wsp]);
            }
        }
    }
}


void quick_sort(int tab[], int l, int p)
{
    int i,j,tmp;
    i=l;
    j=p;
    tmp=tab[(i+j)/2];
    while(i<=j)
    {
        while(tab[i]<tmp and i<=j) i++;
        while(tab[j]>tmp and i<=j) j--;
        if(i<=j)
        {
            swap(tab[i],tab[j]);
            i++;
            j--;
        }
    }
    if(l<j)quick_sort(tab,l,j);
    if(i<p)quick_sort(tab,i,p);
}




















