#include <iostream>
#include <cstdlib>
#include "/headers/list.hpp"

using namespace std;

node * concatenete(node *&f1, node *&f2);
node *concateneteReqursive(node *&f1, node *&f2);
node *sorts(node *f);
int main()
{
    node *first1, *first2;
    first1=first2=NULL;
    insertInOrder(first1, 5);
    insertInOrder(first1, 70);
    insertInOrder(first1, 20);
    insertInOrder(first1, 32);
    insertInOrder(first2, 31);
    insertInOrder(first2, 1);
    insertInOrder(first2, 71);
    insertInOrder(first2, 35);
    insertInOrder(first2, 32);
    insertInOrder(first2, 41);
    writeOutNormal(first1);
    cout<<endl;
    writeOutNormal(first2);
    cout<<endl;
    //first1=concatenete(first1,first2);
    first1=concateneteReqursive(first1,first2);
    writeOutNormal(first1);
    cout<<endl;
    //writeOutNormal(first2);
    first1=sorts(first1);
    writeOutNormal(first1);
    return 0;
}
//scalanie dwóch łańcuchów uporządkowyanych w jeden łańcuch
node * concatenete(node *&f1, node *&f2)
{
    if(f1==NULL)return f2;
    if(f2==NULL)return f1;
    node *wynik=NULL;
    node *last;
    if(f1->n<f2->n)
    {
        wynik=f1;
        f1=f1->next;
    }
    else
    {
        wynik=f2;
        f2=f2->next;
    }
    //wynik->next=NULL;
    last=wynik;
    while(f1!=NULL and f2!=NULL)
    {
        if(f1->n==f2->n and f1!=NULL) f1=f1->next;
        if(f1->n<f2->n)
        {
            last->next=f1;
            last=last->next;
            f1=f1->next;
        }
        else
        {
            last->next=f2;
            last=last->next;
            f2=f2->next;
        }
    }
    if(f1!=NULL)last->next=f1;
    if(f2!=NULL)last->next=f2;
    f1=f2=NULL;
    return wynik;
}
//scalanie dwóch łańcuchów uporządkowanych w jeden, rekurencyjnie
node *concateneteReqursive(node *&f1, node *&f2)
{
    if(f1==NULL)return f2;
    if(f2==NULL)return f1;
    node *wynik=NULL;
    if(f1->n<f2->n)
    {
        wynik=f1;
        wynik->next=concateneteReqursive(f1->next,f2);
    }
    else
    {
        wynik=f2;
        if(f1->n==f2->n) wynik->next=concateneteReqursive(f1->next,f2->next);
        else    wynik->next=concateneteReqursive(f1,f2->next);
    }
    f1=f2=NULL;
    return wynik;
}
//sortowanie listy po wyniku dzialania %10
node *sorts(node *f)
{
    node *first[10];
    node *last[10];
    int m;
    for(int i=0;i<10;i++) first[i]=last[i]=NULL;
    while(f!=NULL)
    {
        m=f->n%10;
        if(first[m]==NULL)
            first[m]=last[m]=f;
        else
        {
            last[m]->next=f;
            last[m]=last[m]->next;
        }
        f=f->next;
    }
    node *w;
    w=NULL;
    for(int i=9;i>=0;i--)
    {
        if(first[i]!=NULL)
        {
            last[i]->next=w;
            w=first[i];
        }
    }
    return  w;
}
