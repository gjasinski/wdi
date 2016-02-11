#include <iostream>
#include <cstdlib>

using namespace std;

const int N=10;
int t1[N];
int t2[N][N];
void bin(int n);
int zlicz(int n, int s, int p);
int det(int t2[N][N],int r);
void przesun(int t2[N][N], int t3[N][N], int x, int r);




int main()
{
    //bin
    bin(19);
    cout<<endl;
    //-------------------------------


    //zlicz
    for(int i=0;i<N;i++) t1[i]=rand()%10;
    cout<<endl<<zlicz(2,42,0);
    //-----------------------------------


    //det
    t2[0][0]=5;
    t2[0][1]=12;
    t2[0][2]=7;
    t2[1][0]=8;
    t2[1][1]=13;
    t2[1][2]=5;
    t2[2][0]=125;
    t2[2][1]=2;
    t2[2][2]=3;
    cout<<endl<<det(t2,3);
    //----------------------
    return 0;
}

void bin(int n)
{
    /*
    rekurencyjna funkcja zamieniająca liczbe w systemie (10) na (2)
    bin(19);
    */
    if(n>0)
    {
        bin(n/2);
        cout<<n%2;
    }
}

int zlicz(int n, int s, int p)
{
    /*
    rekurencyjna funkcja szukająca w tablicy liczb które przemnożone przez siebie dadzą liczbę s
    Przykladowe poczatkowe wywołanie
    zlicz(2,42,0);
    int zlicz(int n, int s, int p)
    n - ilosc licz z których ma sie składać liczba
    s - liczba jakiej szukamy
    p - numer w tablicy od jakieog ma dzialć rekurencja, pomocnicze
    */
    int l=0;
    if(n==1)
    {
        for(int i=p;i<N;i++)
        {
            if(s==t1[i]) l++;//licz++;
        }
    }
    else
    {
        for(int i=p;i<N;i++)
        {
            if(s%t1[i]==0) l=l+zlicz(n-1,s/t1[i],i+1);
        }
    }
    return l;
}


int det(int t2[N][N],int r)
{
    /*
    funkcja rekurencyjna liczaca wyznacznik macierzy;
    det(t2,3);
    funkcja zwraca wyznacznik macierzy o 1 mniejszczej.
    */
    int t3[N][N];
    if(r==1) return t2[0][0];
    int sum=0;
    int znak=-1;
    for(int i=0;i<r;i++)
    {
        przesun(t2,t3,i,r);
        sum=sum+t2[0][i]*det(t3,r-1)*znak;
        znak=-znak;
    }
    return sum;

}
void przesun(int t2[N][N], int t3[N][N], int x, int r)
{
    // funkcja zmniejsza tablice poprzez dosunięcie do elementu (0,0)
    for(int k=0;k<r-1;k++)
        for(int w=0;w<r;w++) t3[k][w]=t2[k+1][w];

    for(int k=0;k<r;k++)
        for(int w=x;w<r-1;w++) t3[k][w]=t3[k][w+1];
}
