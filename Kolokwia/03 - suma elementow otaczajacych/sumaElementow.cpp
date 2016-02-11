/*
Dane s¹ definicje:
const
max1 = 100;
max2 = 2000;
type
table = array[1..max1, 1..max2] of real;
Proszê napisaæ procedurê, która dla zmiennej typu table zwraca numer wiersza i kolumny
elementu, dla którego suma otaczaj¹cych go elementów jest najmniejsza.
*/
#include <iostream>
#include <cstdlib>
using namespace std;

const int N=10;
int tab[N][N];

int suma(int w, int k)
{
    int wynik=0;
    if(w-1>=0) wynik+=tab[w-1][k];
    if(w-1>=0 and k-1>=0) wynik+=tab[w-1][k-1];
    if(w-1>=0 and k+1<N) wynik+=tab[w-1][k+1];
    if(k-1>=0)wynik+=tab[w][k-1];
    if(k<N)wynik+=tab[w][k+1];
    if(w+1<N) wynik+=tab[w+1][k];
    if(w+1<N and k-1>=0) wynik+=tab[w+1][k-1];
    if(w+1<N and k+1<N) wynik+=tab[w+1][k+1];
    return wynik;
}
int main()
{

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            tab[i][j]=random()%100;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<tab[i][j]<<" ";
            cout<<endl;
    }
    int maks=0;
    int maksk, maksw,tmp;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            tmp=suma(i,j);
            if(tmp>maks){
            maks=tmp;
            maksw=N-i;
            maksk=0;}
        }
    }
    cout<<maks;

}
