#include <iostream>
#include <cstdlib>
using namespace std;

const int N=1000;

struct punkt{
    int w;
    int k;
};
punkt szukajkwadratu(int t[N][N], int k);
int main()
{
    int t[N][N];
    srand(time(NULL));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            t[i][j]=rand()%100;

        }
    }
    punkt p;
    p=szukajkwadratu(t,64);
    cout<<p.w<<endl<<p.k;
}

punkt szukajkwadratu(int t[N][N], int k)
{
    bool stop=false;
    int i,j,s,w;
    i=j=0;
    s=2;
    while(s<N and !stop)
    {
        while(i<N-s and !stop)
        {
            j=0;
            while(j<N-s and !stop)
            {
                w=t[i][j]*t[i+s][j+s]*t[i+s][j]*t[i][j+s];
                //cout<<w<<" ";
                if(k==w) stop=true;
                j++;
            }
            i++;
        }
        s=s+2;
    }
    punkt p;
    if(!stop)
    {
        p.w=-1;
        p.k=-1;
    }
    else
    {
        j--;
        i--;
        s=s-2;
        p.w=i+s/2+1;
        p.k=j+s/2+1;
        cout<<endl;
        for(int m=i;m<i+s+2;m++)
        {
            for(int n=j;n<j+s+2;n++)
            cout<<t[m][n]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    return p;
}
