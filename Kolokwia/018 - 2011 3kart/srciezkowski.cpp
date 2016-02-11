#include<iostream>
#include<cstdlib>
using namespace std;
struct punkt{int x,y;};
const int maks=100;
bool dasie(punkt tab[maks], int r, int k);
int main()
{
    punkt tab[maks];
    srand(time(NULL));
    for(int i=0;i<maks;i++)
    {
            tab[i].x=rand()%100-50;
            tab[i].y=rand()%100-50;
    }
    if(dasie(tab,12,6))cout<<"OK";else cout<<"NOPE";
}

bool dasie(punkt tab[maks], int r, int k)
{
    int n=3;
    double x,y;
    while(n<k)
    {
        for(int i=0;i<maks;i++)
        {
            for(int j=i+1;j<maks;j++)
            {
                for(int l=j+1;l<maks;l++)
                {
                    x=tab[i].x+tab[j].x+tab[l].x;
                    y=tab[i].y+tab[j].y+tab[l].y;
                    x=x/3.0;
                    y=y/3.0;
                    if(x*x+y*y<r*r) return true;
                }
            }
        }
        n=n+3;
    }
    return false;
}
