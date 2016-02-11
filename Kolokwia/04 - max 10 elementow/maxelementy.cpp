/*
Dane s¹ nastêpuj¹ce definicje:
const
max = 10;
var
tab: array[1..max] of real;
Proszê napisaæ program, który wczytuje wprowadzony z klawiatury ci¹g dodatnich liczb
rzeczywistych zakoñczony wartoœci¹ -1, bêd¹c¹ znacznikiem koñca ci¹gu i umieszcza max
najwiêkszych elementów w tablicy tab. Mo¿na za³o¿yæ, ¿e ci¹g zawiera co najmniej max liczb.
*/
#include <iostream>

using namespace std;
const int N=10;
int tab[N];
void sortuj();

int main()
{
//wczytuje liczby do podania -1
//wypisuje 10 najwiekszych
    for(int i=0;i<N;i++)
        cin>>tab[i];
    sortuj();
    int tmp;
    cin >>tmp;
    while(tmp!=-1)
    {
        if(tmp>tab[0]) tab[0]=tmp;
        sortuj();
        cin>>tmp;
    }
    for(int i=0;i<N;i++)
    {
        cout<<tab[i]<<" ";
    }
}

void sortuj()
{
    int tmp;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N-1;j++)
        {
            if(tab[j]>tab[j+1])
            {
                tmp=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=tmp;
            }
        }
    }
}
