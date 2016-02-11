#include <iostream>

using namespace std;
void wypisz(int a, int b);
int main()
{
    //Program tworzący palindromy skladajace sie z znakow A i B
    wypisz(5,7);
}
void palindrom(int a, int b, string wynik)
{
    //funkcja wywołujaca rekurencje
    cout<<wynik<<endl;
    if(a>1) palindrom(a-2,b, 'A'+wynik+'A');
    if(b>1) palindrom(a,b-2,'B'+wynik+'B');
}
void wypisz(int a, int b)
{
    //funkcja rekurencyjna tworzaca palindromy
    palindrom(a,b,"");
    if(a>0) palindrom(a-1,b,"A");
    if(b>0) palindrom(a,b-1,"B");
}
