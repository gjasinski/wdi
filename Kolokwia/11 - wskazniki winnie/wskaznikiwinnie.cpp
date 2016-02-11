#include<iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

struct node
{
    int n;
    node *next;
};

void addNode(node *&f, int w);
void usunPowtarzajaceElementy(node *f);
node *scalIloczynMnogosciowy(node *f1, node *f2);

void wypisz(node *f)
{
    while(f!=NULL)
    {
        cout<<f->n<<" ";
        f=f->next;
    }
}
void insertInOrder(node *&first, int w)
{
    node *p, *q;
    p=first;
    q=NULL;
    while(p!=NULL and p->n<w)
    {
        q=p;
        p=p->next;
    }
    if(p!=NULL and p->n==w) return;
    node *r = new node;
    r->n=w;
    r->next=p;
    if(q==NULL) first=r;
    else q->next=r;
}

int main()
{
    node *lista, *lista2;
    lista = lista2 = NULL;
    srand (time(NULL));
    for(int i=0;i<100;i++)
    {
        insertInOrder(lista, rand()%100);

        insertInOrder(lista2,rand()%150);
    }
    wypisz(lista);
    cout<<endl;
    wypisz(lista2);
    //usunPowtarzajaceElementy(lista);
    lista=scalIloczynMnogosciowy(lista, lista2);
    cout<<endl<<endl;
    wypisz(lista);
}

void addNode(node *&f, int w)
{
    node *tmp, *t;
    tmp=new node;
    tmp->n=w;
    tmp->next=NULL;
    if(f==NULL)
    {
        f=tmp;
        return;
    }
    t=f;
    while(t->next!=NULL) t=t->next;
    t->next=tmp;
}

/*
Proszę napisać procedurę, która w liście wskazywanej przez zmienna typu pwezel usuwa
powtarzające się elementy. Można założyć, że lista jest niepusta.
*/
void usunPowtarzajaceElementy(node *f)
{
    node *i, *j, *p;
    i=f;
    while(i!=NULL)
    {
        j=i->next;
        p=i;
        while(j!=NULL)
        {
            if(i->n==j->n)
            {
                p->next=j->next;
                delete j;
                j=p->next;
            }
            else
            {
                p=j;
                j=j->next;
            }
        }
        i=i->next;
    }
}

/*
Globalna zmienna typu pwezel wskazuje na listę cykliczną. Proszę napisać procedurę,
usuwającą nadmiarowe (tj. o powtarzających się wartościach) elementy z listy. Można założyć,
że lista zawiera co najmniej 2 różne elementy.
*/
void usunPowtarzajaceElementyCykl(node*f)
{}

/*
Dane są definicje:
const
max = 500;
type
tablica = array[1..max, 1..max] of integer;
W zmiennych typu tablica większość (np. 95%) elementów jest równa 0. Proszę zaproponować
strukturę dynamiczną (wskaźnikową) przechowującą w sposób efektywny (pod względem
wykorzystania pamięci) zawartość zmiennej typu tablica.
Proszę napisać procedurę przekształcającą zmienną typu tablica na zaproponowaną
strukturę;
Proszę napisać funkcję, która korzystając z zaproponowanej struktury zwraca wartość
wybranego elementu (określonego przez parę indeksów (i, j)).
*/

/*
Pojedyncza lista zawiera niepowtarzające się liczby naturalne uporządkowane rosnąco. Proszę
napisać procedurę, która dwie niepuste listy wejściowe przekształca na jedną listę wynikową
tak że elementy listy wynikowej stanowią iloczyn mnogościowy list wejściowych. Listy
wejściowe są usuwane z pamięci.
*/
node *scalIloczynMnogosciowy(node *f1, node *f2)
{
    node *w, *tmp, *prev, *i;
    w=NULL;
    while (f1!=NULL and f2!=NULL)
    {

        if(f1->n==f2->n)
        {

            tmp=f1;
            f1=f1->next;
            delete tmp;
            tmp=f2;
            f2=f2->next;
            tmp->next=NULL;
            if(w==NULL) w=tmp;
            else
            {
                i=w;
                while(i!=NULL)
                {
                    prev=i;
                    i=i->next;
                }
                prev->next=tmp;
            }
        }else
        {
            if(f1->n>f2->n)
            {
                tmp=f2;
                f2=f2->next;
                delete tmp;
            }
            if(f1->n<f2->n)
            {
                tmp=f1;
                f1=f1->next;
                delete tmp;
            }
        }
    }
    tmp=w;
    return w;
}
