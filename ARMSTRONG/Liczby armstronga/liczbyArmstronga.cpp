#include <iostream>


using namespace std;

const int tsize=10;


void generujLiczby(int tab[tsize]);

int main()
{
    int tablica[tsize];
    for (int i=0;i<tsize;i++) tablica[i]=0;
    tablica[tsize-1]=1;
    generujLiczby(tablica);
}

void wypisz(int tab[tsize])
{
    for (int i=0;i<tsize;i++) cout<<tab[i];
    cout<<endl;
}

//dodawanie 2 liczb
//wynik w w[tsize]
//zwraca false w przypadku przekroczenia zakresu
bool dodawanie(int w[tsize], int t2[tsize])
{
    int tmp;
    for (int i=tsize-1;i>=0;i--)
    {
        w[i]+=t2[i];
        tmp=w[i];
        w[i]=tmp%10;
        if(i==0 and tmp>9) return false;
        w[i-1]+=tmp/10;
    }
    return true;
}

//dodawanie 2 liczb
//wynik w w[tsize]
//zwraca false w przypadku przekroczenia zakresu
bool inkrementacja(int w[tsize])
{
    int tmp, i;
    i=tsize-1;
    w[i]++;
    if(w[i]<10)return true;
    tmp=0;
    do
    {
        if(i<0)return false;
        tmp+=w[i];
        w[i]=tmp%10;
        tmp/=10;
        i--;
    }while(tmp>0);
    return true;
}

//mnozenie liczby o rozmiarze do 60 i 1
//zwraca false w przypadku przeroczenia zakresu
bool mnozenie(int t1[tsize], int m)
{
    int tmp=0;
    for (int i=tsize-1;i>=0;i--)
    {
        t1[i]*=m;
        tmp+=t1[i];
        t1[i]=tmp%10;
        if(i==0 and tmp>9)return false;
        tmp/=10;
    }
    return true;
}

//funkcja uzupelnia tablice poteg
void uzupelnijTablicePoteg(int t[10][tsize])
{
    for (int i=2;i<10;i++)
    {
        if(!mnozenie(t[i],i)){cout<<"Funkcja uzupelnijTablicePoteg - PRZEKROCZENIE ZAKRESU TABLICY INDEKS: "<<i<<endl;}
    }
}

//Zwraca true gdy liczby są takie same, false gdy są różne
//Liczby uzanjemy za takie same gdy mają taką sama ilość takich samuch cyfr
//Ponieważ nie generujemy wszystkich liczb, a jedynie kombinacje liczb
//np: 12, 13, 14, 23, 24, 34
//Dwie takie same liczby:
//556211==155126
bool takieSameLiczby(int t1[tsize],int t2[tsize])
{
    int s1, s2;
    s1=s2=tsize-1;
    while (s1>0 and t1[s1]==0) s1--;
    while (s2>0 and t2[s2]==0) s2--;

    if(s1!=s2) return false;


    int tab[10][2];
    for (int i=0;i<10;i++) tab[i][0]=tab[i][1]=0;
    while (s1>=0)
    {
        tab[t1[s1]][0]++;
        tab[t2[s1]][1]++;
        s1--;
    }

    for (int i=0;i<10;i++) if (tab[i][0]!=tab[i][1]) return false;
    wypisz(t2);
    if (t2[tsize-1]==1)
    {
        t2[tsize-1]=0;
        wypisz(t2);
    }
    return true;
}

//1 - liczba jest liczba armstronga
//0 - liczba nie jest liczba armstroga
//-1 - wystapil nadmiar podczas zliczania poteg, nalezy zakonczyc obecnie generowane liczby
int sprawdzajWarunki(int tab[tsize], int t[10][tsize])
{
    int liczba[tsize];
    for(int i=0;i<tsize;i++)liczba[i]=0;
    bool nieNadmiar=true;
    for (int i=0;i<tsize and nieNadmiar;i++)
    {
        if(tab[i]>1) nieNadmiar=dodawanie(liczba,t[tab[i]]);
        if(tab[i]==1) nieNadmiar=inkrementacja(liczba);
    }
    if(!nieNadmiar) return -1;
    if(takieSameLiczby(tab,liczba)) return 1;
    return 0;
}
/*---------UWAGA
Podczas generowania są pomijany liczby z zerami w środku!
dlatego należy dodać te liczby.
Jednakże te liczby są liczbami armstroga wtw gdy
istnieje taka liczba armstraga koncząca się na 1
wtedy taka liczba mniejsza o 1 też jest l. armstrąga.
Przykład:
ZLE ROZUMOWANIE!

*/
void generujLiczby(int tab[tsize])
{
    int t[10][tsize];
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<tsize-1;j++)t[i][j]=0;
        t[i][tsize-1]=1;
    }
    t[0][tsize-1]=0;
    uzupelnijTablicePoteg(t);


    int i=tsize-1;
    int tmp,tmpi, rozmiar,w;
    rozmiar=1;
    while (tab[0]!=9)
    {
        tab[i]++;
        if(tab[i]>9)
        {
            tmpi=i-1;
            while(tab[tmpi]==9 and tmpi>=0) tmpi--;
            if(rozmiar<tsize-tmpi)
            {
                rozmiar=tsize-tmpi;
                uzupelnijTablicePoteg(t);
            }
            tab[tmpi]++;
            tmp=tab[tmpi];

            for (tmpi;tmpi<tsize;tmpi++)
            {
                tab[tmpi]=tmp;
            }

        }

        w=sprawdzajWarunki(tab,t);

        //if(w==1)cout<<"ARMSTRONG"<<endl;
        //if(w==0)cout<<"NOPE"<<endl;

        if(w==-1)
        {
           do
            {
                tmpi=i-1;
                while(tab[tmpi]==9 and tmpi>=0) tmpi--;
                if(rozmiar<tsize-tmpi)
                {
                    rozmiar=tsize-tmpi;
                    uzupelnijTablicePoteg(t);
                }
                tab[tmpi]++;
                tmp=tab[tmpi];

                for (tmpi;tmpi<tsize;tmpi++)
                {
                    tab[tmpi]=tmp;
                }
            }
            while(sprawdzajWarunki(tab,t) and tab[0]!=9);

        }
        }


}



