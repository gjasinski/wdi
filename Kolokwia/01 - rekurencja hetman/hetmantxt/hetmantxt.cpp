#include <iostream>
#include <fstream>

using namespace std;

fstream plik( "hetmani.txt", ios::out );
const int NConst=20;
int tab[NConst][NConst];
int N;
void wypisz();
bool czyMozliwe(int w, int k);
void ustawiajHetmana(int k);
int licz=0;

int main()
{
    for(N=1;N<=NConst;N++)
    {
        plik<<"Szchownica o rozmiarze "<<N<<" i hetmanach "<<N<<endl;
        ustawiajHetmana(0);
        plik<<endl<<licz<<endl<<"#-----------------------"<<endl;
        licz=0;
    }
}

bool czyMozliwePoziomo(int w, int k)
{
    for(int i=0;i<N;i++)
    {
        if(tab[w][i]==true) return false;
    }
    return true;
}
bool czyMozliwePionowo(int w, int k)
{
    for(int i=0;i<N;i++)
    {
        if(tab[i][k]==true) return false;
    }
    return true;
}

bool czyMozliweUkos(int w, int k)
{
    for(int i=w, j=k;i>=0 and j>=0;i--, j--)
    {
        if(tab[i][j]==true)return false;
    }
    for(int i=w, j=k;i<N and j<N;i++, j++)
    {
        if(tab[i][j]==true)return false;
    }
    for(int i=w, j=k;i>=0 and j<N;i--, j++)
    {
        if(tab[i][j]==true)return false;
    }
    for(int i=w, j=k;i<N and j>=0;i++, j--)
    {
        if(tab[i][j]==true)return false;
    }
    return true;
}
bool czyMozliwe(int w, int k)
{
    bool dasie=true;
    if(dasie) dasie=czyMozliwePionowo(w,k);
    if(dasie) dasie=czyMozliwePoziomo(w,k);
    if(dasie) dasie=czyMozliweUkos(w,k);
    return dasie;
}

void wypisz()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(tab[i][j]) plik<<" H "; else plik<<" - ";
        }
        plik<<endl;
    }
    plik<<endl;
    licz++;
}

void ustawiajHetmana(int k)
{
    int stop;
    if(k<N){
        for(int i=0;i<N;i++)
        {
            if(czyMozliwe(i,k))
            {
                tab[i][k]=true;
                ustawiajHetmana(k+1);
                if(k==N-1)wypisz();
                tab[i][k]=false;
            }
        }
    }
}

