#include <iostream>

using namespace std;
bool mozliwe(int n, int w, int k, int &w1, int &k1);
void skoczek(int n, int w, int k);
const int N=8;
int t[N][N];
int main()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            t[i][j]=0;
        }
    }
    skoczek(1,0,0);
    cout<<"koniec";
}
void wypisz()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(t[i][j]>10) cout<<t[i][j]<<" "; else cout<<t[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void skoczek(int n, int w, int k)//skoczek(1,0,0);
{
    int w1,k1;
    t[w][k]=n;
    if(n==N*N) {wypisz();t[w][k]=0;}
    else
    {

        for (int i=0;i<8;i++)
        {
            if(mozliwe(i,w,k,w1,k1)) skoczek(n+1,w1,k1);
        }
        t[w][k]=0;
    }

}

bool mozliwe(int n, int w, int k, int &w1, int &k1)//mozliwe(0,5,5,w1,k1);
{
    int dy[]={-2,-1,1,2,2,1,-1,-2};
    int dx[]={1,2,2,1,-1,-2,-2,-1};
    w1=w+dy[n];
    k1=k+dx[n];
    return (w1>=0) and (w1<N) and (k1>=0) and (k1<N) and (t[w1][k1]==0);
}
