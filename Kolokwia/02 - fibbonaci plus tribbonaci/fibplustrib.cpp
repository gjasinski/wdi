/*
Dane s¹ ci¹gi a(n), b(n) i c(n) okreœlone nastêpuj¹co:
a(n) = 1 dla n=1, 2
a(n) = a(n-1)+a(n-2) dla n>2
b(n) = 1 dla n=1, 2, 3
b(n) = b(n-1)+b(n-2)+b(n-3) dla n>3
Wyrazy ci¹gu c(n) s¹ kolejnymi liczbami naturalnymi nale¿¹cymi do ci¹gu a(n) lub b(n). Ci¹gi
te przyjmuj¹ wartoœci:
ci¹g a(n) 1 1 2 3 5 8 13 21 ...
ci¹g b(n) 1 1 1 3 5 9 17 31 ...
ci¹g c(n) 1 2 3 5 8 9 13 17 ...
Proszê napisaæ program który wczytuje wprowadzon¹ z klawiatury liczbê naturaln¹ i wypisuje
kolejne wyrazy ci¹gu c(n) mniejsze od wprowadzonej liczby.
*/
#include <iostream>

using namespace std;

int main()
{
    int f1,f2,t1,t2,t3,n,tmp;
    cin >>n;
    f1=8;
    f2=5;
    t1=9;
    t2=5;
    t3=3;
    int ostatni=5;
    cout<<"1 2 3 5 ";
    for(int i=4;i<=n;i++)
    {
        while(f1<=ostatni)
        {
            tmp=f1+f2;
            f2=f1;
            f1=tmp;
        }
        while(t1<=ostatni)
        {
            tmp=t1+t2+t3;
            t3=t2;
            t2=t1;
            t1=tmp;
        }
        if(t1>f1)
        {
            ostatni = f1;
            cout<<f1<<" ";
        }
        else
        {
            ostatni=t1;
            cout<<t1<<" ";
        }

    }

    return 0;
}
