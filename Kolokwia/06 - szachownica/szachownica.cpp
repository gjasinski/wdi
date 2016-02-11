/*
1. Na szachownicy o wymiarach 201 wierszy i 201 kolumn umieszczamy 100 kr�li szachowych. Prosz� 
napisa� program, kt�ry wczytuje z klawiatury po�o�enia 100 kr�li (wiersz, kolumna), odnajduje dwa 
kr�le jednakowo odleg�e od �rodka szachownicy i wypisuje ich pozycj� (wiersz, kolumna). W 
przypadku gdy �adna para kr�li nie spe�nia warunku program ko�czy si� stosownym komunikatem. 
Odleg�o�� kr�la od �rodka to liczba jego ruch�w, kt�re musi wykona� aby dotrze� do �rodka 
szachownicy.
Uwagi: 
1. Kr�l mo�e przesun�� si� na dowolne z 8 s�siednich p�l 
2. Mo�na za�o�y�, �e dane wprowadzone z klawiatury b�d� poprawne 
3. Licz�c drog� kr�la zak�adamy, �e szachownica jest pusta
*/
#include <iostream>
#include <cmath>
using namespace std;

struct krol
{
    int w;
    int k;
    int droga;
};

int main()
{
    const int N=3;
    krol tablica[N];
    for(int i=0;i<N;i++)
    {
        cin>>tablica[i].w>>tablica[i].k;
    }
    int tmp=0;
    int tmpw=0;
    int tmpk=0;
    for(int i=0;i<N;i++)
    {
        tmpw=abs(tablica[i].w-100);
        tmpk=abs(tablica[i].k-100);
        if(tmpw<tmpk)
        {
            tmp=tmpw/8;
            if(tmpw%8!=0)tmp++;
            tmpk-=tmpw;
            tmp+=tmpk/8;
            if(tmpk%8!=0) tmp++;
        }
        else
        {
            tmp=tmpk/8;
            if(tmpk%8!=0) tmp++;
            tmpw-=tmpk;
            tmp+=tmpw/8;
            if(tmpw%8!=0)tmp++;
        }
        tablica[i].droga=tmp;
    }
    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(tablica[i].droga==tablica[j].droga)
            {
                cout<<tablica[i].w<<" "<<tablica[i].k<<"  |  "<<tablica[j].w<<" "<<tablica[j].k<<endl;
            }
        }
    }
}
