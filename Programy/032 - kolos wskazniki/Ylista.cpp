#include<iostream>
using namespace std;
struct node
{
    int n;
    node *next;
};
node *add(node *f, int l)
{
    node *tmp;
    tmp=new node;
    tmp->next=f;
    tmp->n=l;
    return tmp;
}
void wypisz(node *f)
{
    while(f!=NULL)
    {
        cout<<f->n<<" ";
        f=f->next;
    }
    cout<<endl;
}
node *czescwspolna(node *l1, node *l2);
int main()
{
    node *wspolna, *A, *B;
    wspolna=A=B=NULL;
    wspolna=add(wspolna,5);
    wspolna=add(wspolna,30);
    wspolna=add(wspolna,2);
    wspolna=add(wspolna,123);
    A=add(A, 4);
    A->next=wspolna;
    B=add(B, 4);
    B->next=wspolna;
    A=add(A,12);
    A=add(A,77);
    A=add(A,9);
    A=add(A,5678);
    B=add(B,123);
    B=add(B,54);
    B=add(B,1);
    wypisz(wspolna);
    wypisz(A);
    wypisz(B);
    A=czescwspolna(A,B);
    wypisz(A);
}

node *czescwspolna(node *l1, node *l2)
{
    node *tmp, *tmp2, *w;
    tmp=l1;
    while(tmp!=NULL)
    {
        tmp->n=-tmp->n;
        tmp=tmp->next;
    }
    tmp=l2;
    while(tmp!=NULL and tmp->n>0)
    {
        tmp2=tmp;
        tmp=tmp->next;
        delete tmp2;
    }
    w=tmp;
    while(tmp!=NULL)
    {
        tmp->n=-tmp->n;
        tmp=tmp->next;
    }
    tmp=l1;
    while(tmp!=NULL and tmp->n<0)
    {
        tmp2=tmp;
        tmp=tmp->next;
        delete tmp2;
    }
    return w;
}
