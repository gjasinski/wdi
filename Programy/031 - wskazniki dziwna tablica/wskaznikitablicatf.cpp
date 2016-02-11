#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

struct node{
    node *right;
    node *down;
};

int main()
{
    srand (time(NULL));
    int w,k;
    w=k=5;
    bool tab[w][k];
    for(int i=0;i<w;i++)
        for(int j=0;j<k;j++) tab[i][k]=random()%2;
    for(int i=0;i<w;i++)
        {for(int j=0;j<k;j++) if(tab[i][j])cout<<"+";else cout<<"-";
        cout<<endl;}
    node *row[w];
    node *col[k];
    node *tmp;
    for(int i=0;i<w;i++) row[i]=NULL;
    for(int i=0;i<k;i++) col[i]=NULL;
    for(int i=k-1;i>=0;i--)
    {
        for(int j=w-1;j>=0;j--)
        {
            if(tab[j][i])
            {
                tmp=new node;
                tmp->right=col[i];
                tmp->down=row[j];
                col[i]=row[j]=tmp;
            }
        }
    }
}
