#include <iostream>
using namespace std;
struct punkt{int x,y;};
bool wieze(int t[8][8], int w1, int w2);
int main()
{
    int tab[8][8];
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        tab[i][j]=0;
    }
    tab[3][5]=tab[1][7]=-5;
    tab[3][2]=tab[5][1]=5;
    wieze(tab,5,-5);
}

bool szachowanie(punkt p1, punkt p2)
{
  if(p1.x==p2.x or p1.y==p2.y)return true;
  else return false;
}

bool wieze(int t[8][8], int w1, int w2)//podajemy wartosc pol na których jest wieza
{
    punkt tab[4];
    int indeks=0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(t[i][j]==w1 or t[i][j]==w2)
            {
                tab[indeks].x=i;
                tab[indeks].y=j;
                indeks++;
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=i+1;j<4;j++)
        {
            if(szachowanie(tab[i],tab[j]))cout<<"OK";
        }
    }
}
