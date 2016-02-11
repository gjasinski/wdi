/*
1. Na szachownicy o wymiarach 201 wierszy i 201 kolumn umieszczamy 100 króli szachowych. Proszê 
napisaæ program, który wczytuje z klawiatury po³o¿enia 100 króli (wiersz, kolumna), odnajduje dwa 
króle jednakowo odleg³e od œrodka szachownicy i wypisuje ich pozycjê (wiersz, kolumna). W 
przypadku gdy ¿adna para króli nie spe³nia warunku program koñczy siê stosownym komunikatem. 
Odleg³oœæ króla od œrodka to liczba jego ruchów, które musi wykonaæ aby dotrzeæ do œrodka 
szachownicy.
Uwagi: 
1. Król mo¿e przesun¹æ siê na dowolne z 8 s¹siednich pól 
2. Mo¿na za³o¿yæ, ¿e dane wprowadzone z klawiatury bêd¹ poprawne 
3. Licz¹c drogê króla zak³adamy, ¿e szachownica jest pusta
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
