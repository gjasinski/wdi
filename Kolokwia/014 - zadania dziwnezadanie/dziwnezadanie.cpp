/*
Napis s1 poprzedza napis s2 jeżeli ostatnia litera s1 jest mniejsza
od pierwszej litery s2. Według tej zasady rozmieszczono napisy w
cyklicznym łańcuchu odsyłaczowym, na przykład:
┌─bartek-leszek-marcjan-ola-zosia─┐
└─────────────────────────────────┘
Proszę napisać stosowne definicje typów oraz funkcję wstawiającą do
łańcucha napis z zachowaniem zasady poprzedzania. Do funkcji należy
przekazać wskaźnik do łańcucha oraz wstawiany napis, funkcja powinna
zwrócić wartość logiczną wskazującą, czy udało się wstawić napis do
łańcucha. Po wstawieniu elementu wskaźnik do łańcucha powinien
wskazywać na nowo wstawiony element.
*/
#include <iostream>
using namespace std;

struct node{
    char p;
    char o;
    string imie;
    node * next;
};
int main()
{

}
