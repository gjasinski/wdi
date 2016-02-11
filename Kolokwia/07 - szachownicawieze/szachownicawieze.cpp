/*
Na szachownicy o wymiarach 201 wierszy i 201 kolumn umieszczono pewn� liczb� wie� 
szachowych tak, �e ka�de z p�l na jest szachowane. Przyszed� z�y cz�owiek i zmieni� po�o�enie jednej z 
wie� na szachownicy, tak �e nie wszystkie pola s� szachowane. Prosz� zaproponowa� funkcj�, kt�ra 
znajdzie przeniesienie jednej wie�y tak aby ponownie wszystkie pola by�y szachowane. Do funkcji 
przekazujemy tablic� bool t[201][201] z uk�adem wie� po zmianie, funkcja powinna wyznaczy� i 
zwr�ci� dwa pola (wiersz, kolumna) � sk�d , dok�d nale�y przenie�� wie��.
*/
#include <iostream>

using namespace std;
void wypisz();
struct punkt{int x,y;};
const int N=6;
bool tab[N][N];
int tw[N];
int tk[N];
bool czyWszystkieAtakowane();


int main()
{
    punkt wieze[N];
    punkt puste[N];
    //Ustawienie poczatkowe tablicy
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            tab[i][j]=false;
        puste[i].x=puste[i].y=wieze[i].x=wieze[i].y=-1;
    }
    //tab[0][0]=tab[2][1]=tab[1][2]=tab[4][3]=tab[3][4]=tab[3][3]=tab[7][6]=tab[5][7]=true;
    //tab[0][1]=tab[0][0]=tab[0][3]=tab[0][4]=tab[3][2]=tab[4][2]=true;
    wypisz();
    //zliczenie ilosci wież w wierszach/kolumnach a takze dodanie ich współrzędnych do tablicy wież
    int w,k,wz,kz,tmp1,tmp2,tmpi,m;
    tmpi=0;
    for(int i=0;i<N;i++)
    {
        tmp1=tmp2=0;
        for(int j=0;j<N;j++)
        {
            if(tab[i][j])
            {
                tmp1++;
                wieze[tmpi].x=i;
                wieze[tmpi].y=j;
                tmpi++;
            }
            if(tab[j][i]) tmp2++;
        }
        tw[i]=tmp1;
        tk[i]=tmp2;
    }
    //dodanie do tablicy nieatakowane pola
    tmpi=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(tw[i]==0 and tk[j]==0)
            {
                puste[tmpi].x=i;
                puste[tmpi].y=j;
                tmpi++;
            }
        }
    }
/*
    Sprawdzanie każdego punktu z tablicy wiez z każdym punktem z tablicy puste.
    Za każdym razem zmieniamy pozycje wieży aż do momentu gdy wszystkie pola są atakowane.
*/
    tmp1=tmp2=-1;
    bool koniec=false;
    while(wieze[tmp1].x!=-1 and !koniec)
    {
        tmp1++;
        tmp2=-1;
        while(puste[tmp2].x!=-1 and !koniec)
        {
            tmp2++;
            tab[wieze[tmp1].x][wieze[tmp1].y]=false;
            tw[wieze[tmp1].x]--;
            tk[wieze[tmp1].y]--;
            tab[puste[tmp2].x][puste[tmp2].y]=true;
            tw[puste[tmp2].x]--;
            tk[puste[tmp2].y]--;
            koniec=czyWszystkieAtakowane();
            if(koniec)wypisz();
            tab[wieze[tmp1].x][wieze[tmp1].y]=true;
            tw[wieze[tmp1].x]++;
            tk[wieze[tmp1].y]++;
            tab[puste[tmp2].x][puste[tmp2].y]=false;
            tw[puste[tmp2].x]++;
            tk[puste[tmp2].y]++;
        }
    }
}

void wypisz()
{
    cout<<endl;
    //wypisanie tablicy
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            if(tab[i][j])cout<<" X ";else cout<<" - ";
        cout<<endl;
    }
}

bool czyWszystkieAtakowane()
{
    //funkcja sprawdza czy wszystkie pola są atakowane
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(tw[i]==0 and tk[j]==0) return false;
        }
    }
    return true;
}
