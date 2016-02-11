#include <iostream>
#include <cstdlib>
using namespace std;
const int N=100;
int ilepol(int tab[N][N]);
int main()
{
    int tab[N][N];
    srand(time(NULL));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++) tab[i][j]=rand()%100;
    }
    for(int i=5;i<15;i++)
        for(int j=0;j<10;j++)tab[i][j]=13;
    cout<<ilepol(tab);
}
bool pierwsza(int liczba)
{
    int i=2;
    while(i*i<=liczba)
    {
        if(liczba%i==0)return false;
        i++;
    }
    return true;
}
bool wiekszoscpierwsza(int tab[N][N], int w, int k)
{
    int licz=0;
    for(int i=w;i<w+10;i++)
        for(int j=k;j<k+10;j++) if(pierwsza(tab[i][j])) licz++;
    if(licz>50) return true;
    return false;
}

int ilepol(int tab[N][N])
{
    int licz=0;
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)if(wiekszoscpierwsza(tab,10*i,10*j))licz++;
    return licz;
}
