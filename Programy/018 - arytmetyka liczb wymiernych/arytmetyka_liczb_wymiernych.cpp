#include <iostream>

using namespace std;

struct ulamek
{
    /*
    Struktura ułamek
    l - liczba całkowita
    m - liczba całkowita dodatnia
    */
    int l;
    int m;
};
int nwd_rek(int a, int b);
int nwd(int a,int b);
void skroc(ulamek &a);
int iledwapiec(int a);
ulamek dodaj(ulamek a, ulamek b);
ulamek odejmij(ulamek a, ulamek b);
ulamek pomnoz(ulamek a, ulamek b);
ulamek podziel(ulamek a, ulamek b);
void wypisz(ulamek a);
/*
==
<
>
<>
%
read
*/

int main()
{
    ulamek a;
    a.l=3;
    a.m=7;
    wypisz(a);
    ulamek b;
    b.l=3;
    b.m=7;
    cout<<endl;
    wypisz(dodaj(a,b));
    cout<<endl;
    wypisz(odejmij(a,b));
    //cout<<endl;
    wypisz(pomnoz(a,b));
    cout<<endl;
    wypisz(podziel(a,b));
}

int nwd(int a,int b)
{
    /*
    Najwiekszy wspólny dzielnik - jedyna wersja akceptowalna
    */
    while(true)
    {
        if(a>b) a=a%b;
        if(a==0)return b;
        if(a<=b) b=b%a;
        if(b==0) return a;
    }
}

int nwd_rek(int a, int b)
{
    /*
    Najwiekszy wspólny dzielnik - wersja rekurencyjna
    */
    if(b>0) return nwd(b,a%b);
    return a;
}

void skroc(ulamek &a)
{
    /*
    Funkcja skraca ułamek przkeazany w referencji do postaci nieskracalnej.
    */
    int tmp=nwd(a.l,a.m);
    a.l=a.l/tmp;
    a.m=a.m/tmp;
}

int iledwapiec(int a)
{
    /*
    Z własności ułamka wynika że ilość liczb przed okresem jest to wieksza z liczb
    ilosci podzielnosci liczbika przez dwa lub piec.
    Funkcja znajduje ta liczbe
    */
    int iledwa, ilepiec;
    iledwa=0;
    while(a%2==0 and a>0)
    {
        iledwa++;
        a=a/2;
    }
    ilepiec=0;
    while(a%5==0 and a>0)
    {
        ilepiec++;
        a=a/5;
    }
    if(iledwa>ilepiec)return iledwa; else return ilepiec;
}

ulamek dodaj(ulamek a, ulamek b)
{
    /*
    Funkcja dodaje dwa ulamki.
    */
    ulamek c;
    c.l=a.l*b.m +b.l*a.m;
    c.m=a.m*b.m;
    skroc(c);
    return c;
}

ulamek odejmij(ulamek a, ulamek b)
{
    /*
    Funkcja odejmuje dwa ulamki.
    */
    ulamek c;
    c.l=a.l*b.m;
    c.m=a.m*b.m;
    c.l=c.l-b.l*a.m;
    skroc(c);
    return c;
}
ulamek pomnoz(ulamek a, ulamek b)
{
    /*
    Funkcja mnozy dwa ulamki.
    */
    a.l=a.l*b.l;
    a.m=a.m*b.m;
    //skroc(a);
    return a;
}
ulamek podziel(ulamek a, ulamek b)
{
    /*
    Funkcja dzieli dwa ulamki.
    */
    a.l=a.l*b.m;
    a.m=a.m*b.l;
    skroc(a);
    return a;
}


void wypisz(ulamek a)
{
    cout<<a.l/a.m;
    a.l=a.l%a.m;
    if(a.l>0)
    {
        cout<<".";
        for(int i=0;i<iledwapiec(a.m);i++)
        {
            a.l=a.l*10;
            cout<<a.l/a.m;
            a.l=a.l%a.m;
        }
    }
    if(a.l>0)
    {
        cout<<"(";
        int p=a.l;
        do
        {
            a.l=a.l*10;
            cout<<a.l/a.m;
            a.l=a.l%a.m;
        } while(a.l!=p);
        cout<<")";

    }

}
