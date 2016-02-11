#include <iostream>

using namespace std;

int main()
{
    //Tworzenie rozwiniecia dziesietnego z okresem
    const int N=1000;
    int tab[N];
    int liczba, przecinek,i,mianownik,r;
    bool jest_okres=false;
    bool sprawdz=false;

    for(int i=0;i<N;i++) tab[i]=0;
    cin >> liczba;
    i=0;
    //wpisanie liczby do tablicy
    while(liczba>0)
    {
        tab[i]=liczba%10;
        liczba=liczba/10;
        i++;
        przecinek++;
    }
    i=0;
    cin>>mianownik;
    r=0;
    //podzielenie liczby w tablicy przez liczbe mianownik
    for(i;i<przecinek;i++)
    {
        r=r*10+tab[i];
        tab[i]=r/mianownik;
        r=r%mianownik;
    }
    while(i<N)
    {
        r=r*10+tab[i];
        tab[i]=r/mianownik;
        r=r%mianownik;
        i++;
    }
    int zero=N;
    //ustawienie znacznika zero na pierwsze zerow tablicy, w przypadku liczb ktore dadza się przedstwic bez okresu
    for (i=N-1;i>-0;i--) if(tab[i]==0) zero=i; else break;
    i=przecinek;
    int index=0;
    //Bierzemy dwie liczby i sprawdzamy po kolei po przecinku.
    //Dla kazdej pary liczb sprawdzamy czy istenieje jakakolwiek para w innej czesci tablicy.
    //Sprawdzamy czy liczby w tablicy od i do j sa takie same jak od j do j+i, jeżel tak to ten fragment jest okresem.
    //Ustawiamy flage jest okres i zapamietujemy poczatkowy indeks okresu czyi i,
    //i koniec okresu czyli index.
    while(!jest_okres and i<N-1)
    {
        for (int j=i+1;j<N-1 and !jest_okres;j++)
        {
            if(tab[i]==tab[j] and tab[i+1]==tab[j+1]and j+1<zero)
            {
                sprawdz=true;
                index=j;
            }
            if(sprawdz)
            {
                jest_okres=true;
                for(int k=i;k<j;k++, index++)
                {
                    if(tab[k]!=tab[index]) jest_okres=false;
                }
            }
            index=j;

        }
        i++;
    }
    i--;
    //Wypisanie, najpierw do przecinka, potem do i potem "(" i okres i zamykamy okres")"
    for(int k=0;k<przecinek;k++)cout<<tab[k];
    cout<<".";
    for(int k=przecinek;k<i and k<zero;k++)cout<<tab[k];
    if(jest_okres)
    {

        cout<<"(";
        for(int k=i;k<index;k++)cout<<tab[k];
        cout<<")";
    }
}
