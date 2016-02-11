#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;

int main()
{
    //szukamy najwiekszej sumy(kolumana)/suma(wiersz)
    //szukamy najwiekszej sumy w kolumnie dzielimy przez najmniejsza sume w wierszu
    const int N=10;
    int t[N][N];
    int w, k, tmp_col, tmp_row, max_col, min_row;
    max_col = 0;
    min_row = INT_MAX;

    for (int i =0;i<N;i++)
        for(int j=0;j<N;j++) t[i][j]=rand()%100+1;
    for (int i =0;i<N;i++)
    {
        tmp_col=0;
        tmp_row=0;
        for(int j=0;j<N;j++)
        {
            tmp_col=tmp_col+t[j][i];
            tmp_row=tmp_row+t[i][j];
        }
        if(tmp_col>max_col)
        {
            max_col=tmp_col;
            k=i;
        }
        if(tmp_row>min_row)
        {
            min_row=tmp_row;
            w=i;
        }
    }

    cout<<"Kolumna: "<<k<<" Wiersz: "<<w;
    return 0;
}

