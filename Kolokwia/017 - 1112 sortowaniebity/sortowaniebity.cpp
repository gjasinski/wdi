#include <iostream>
using namespace std;
struct node{
    int n;
    node *next;
};
node *add(node *f,int l)
{
    node *prev, *fi, *n;
    fi=f;
    prev=NULL;
    while(f!=NULL)
    {
        prev=f;
        f=f->next;
    }
    n= new node;
    n->n=l;
    n->next=NULL;
    if(prev==NULL) return n;
    prev->next=n;
    return fi;
}
void wypisz(node *f)
{
    while(f!=NULL)
    {
        cout<<f->n<<" ";
        f=f->next;
    }
}
node *sortuj (node *f);
int main()
{
    node *f;
    f=NULL;
    f=add(f,5);
    f=add(f,51);
    f=add(f,511);
    f=add(f,54);
    f=add(f,2588542);
    wypisz(f);
    f=sortuj(f);
    cout<<endl;
    wypisz(f);
}

int ilejedynek(int liczba)
{
    int licz=0;
    while(liczba>0)
    {
        if(liczba%2==1)licz++;
        liczba=liczba/2;
    }
    return licz;
}
int pozycjawtab(int liczba)
{
    int l=ilejedynek(liczba);
    if(l<8) return 0;
    if(l<24) return 1;
    return 2;
}
node *sortuj (node *f)
{
    node *tmp;
    node *t[3][2];
    int w;
    for(int i=0;i<3;i++)
        for(int j=0;j<2;j++)t[i][j]=NULL;
    while (f!=NULL)
    {
        w=pozycjawtab(f->n);
        tmp=f;
        f=f->next;
        tmp->next=NULL;
        if(t[w][0]==NULL)t[w][0]=t[w][1]=tmp;
        else
        {
            t[w][1]->next=tmp;
            t[w][1]=tmp;
        }

    }
    bool jestwynik=false;
    for(int i=0;i<3;i++)
    {
        if(t[i][0]!=NULL)
        {
            if(!jestwynik)
            {
                tmp=t[i][0];
                jestwynik=true;
            }
            for(int j=i+1;j<3;j++)
            {
                if(t[j][0]!=NULL) t[i][1]->next=t[j][0];
            }
        }
    }
    return tmp;
}
