#include <iostream>

using namespace std;

void szukajKolejnsoc(int liczba, int szukana, int n, string wynik);

int A(int liczba)
{
    return liczba+3;
}
int B(int liczba)
{
    return liczba*2;
}
int C(int liczba)
{
    //zamienia dwie ostatnie cyfry liczby
    if(liczba>=10)
    {
        int tmp1, tmp2;
        tmp1=liczba%10;
        liczba/=10;
        tmp2=liczba%10;
        liczba-=tmp2;
        liczba+=tmp1;
        liczba*=10;
        liczba+=tmp2;
    }
    return liczba;
}

int main()
{
    //program szuka czy da sie dojsc z liczby a do b przy pomocy dzialan ABC w max n krokach
    //wypisuje kolejnosc

    szukajKolejnsoc(181,118,5,"");
    return 0;
}

void szukajKolejnsoc(int liczba, int szukana, int n, string wynik)
{
    if(liczba==szukana)
    {
        cout<<wynik<<endl;
        return;
    }
    if(n>0)
    {
        szukajKolejnsoc(A(liczba),szukana,n-1,wynik+"A");
        szukajKolejnsoc(B(liczba),szukana,n-1,wynik+"B");
        szukajKolejnsoc(C(liczba),szukana,n-1,wynik+"C");
    }
    if(n>=0 and C(liczba)==szukana)
    {
        cout<<wynik+"C"<<endl;
        return;
    }
}
