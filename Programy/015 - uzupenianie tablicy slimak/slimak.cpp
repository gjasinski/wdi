#include <iostream>


using namespace std;

int main()
{
    /*
    Program wypisujacy tablice z liczbami inkrementujacymi sie jak slimak
    Przyklad:
    1  2  3  4
    12 13 14 5
    11 16 15 6
    10 9  8  7
    Algorytm:
    Zerujemy tablice, zauwazamy ze ilosc licz do wpisania w 1. iteracji jest o 1 mniejsza od rozmiaru tablicy,
    potem zmniejsza sie o 2. Działamy gdy rozmiar jest > 0. 4 Pętle każda uzupełnia kolejno
    wiersz góra, kolumna prawo, wiersz dół, kolumna lewo.
    Zauważamy że startowe miejsca dla wew. petli maja współżedne kratowe i,i.
    */
    const int N=11;
    int tab[N][N];
    int dlugosc,i,n,p;
    i=0;
    n=1;
    for(int l=0;l<N;l++)
        for(int k=0;k<N;k++)tab[l][k]=0;

    for(dlugosc=N-1;dlugosc>0;dlugosc=dlugosc-2,i++)
    {
        p=N-i-1;
        for(int q=i;q<i+dlugosc;q++,n++) tab[i][q]=n;
        for(int q=i;q<i+dlugosc;q++,n++) tab[q][p]=n;
        for(int q=p;q>=N-i-dlugosc;q--,n++)tab[p][q]=n;
        for(int q=p;q>=N-i-dlugosc;q--,n++)tab[q][i]=n;

    }
    if(N%2!=0) tab[(N+1)/2-1][(N+1)/2-1]=n;
    for(int l=0;l<N;l++)
    {
        for(int k=0;k<N;k++)cout <<tab[l][k]<<" ";
        cout<<endl;
    }

    return 0;
}
