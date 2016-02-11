#include <iostream>
#include <cstdlib>
#include <time.h>
#include "/headers/list.hpp"

using namespace std;

/*
Dany jest łańcuch odsyłaczowy/lista, wiemy że jest niepusty i zawiera cykl.
Znajdz dlusogsc cyklu.
*/

void makeLoop(node *f, int n);
int ver1(node *f);
int ver2(node *f);

int main()
{
    node *first;
    first=NULL;
    srand (time(NULL));
    for(int i=0;i<100;i++)
        insertInOrder(first, rand()%1000);
    writeOutNormal(first);
    makeLoop(first, 20);
    //writeOutNormal(first);
    cout<<endl<<ver1(first);
    cout<<endl<<ver2(first);
}

void makeLoop(node *f, int n)
{
    while(n>0 and f!=NULL)
    {
        f=f->next;
        n--;
    }
    node *tmp, *l;
    tmp=f;
    cout<<endl<<endl<<tmp->n<<endl;
    while(f!=NULL)
    {
        l=f;
        f=f->next;
    }
    l->next=tmp;
}

//Dodatkowo wiadomo ze jest nie wiecej niz 100 elementów w liście
int ver1(node *f)
{
    for(int i=0;i<=100;i++)
        f=f->next;
    node *tmp =f;
    int licz=1;
    f=f->next;
    while(f!=tmp)
    {
        f=f->next;
        licz++;
    }
    return licz;
}

//nie mamy dodatkowego zalozenia
//dzialmy jak wilk i zajac jeden biegnie za drugim (jedne wolniej)
int ver2(node *f)
{
    node *wilk, *zajac;
    wilk=zajac=f;
    wilk=wilk->next->next;
    zajac=zajac->next;
    while(wilk!=zajac)
    {
        wilk=wilk->next->next;
        zajac=zajac->next;
    }
    int licz=1;
    wilk=wilk->next;
    while(wilk!=zajac)
    {
        wilk=wilk->next;
        licz++;
    }
    return licz;
}
