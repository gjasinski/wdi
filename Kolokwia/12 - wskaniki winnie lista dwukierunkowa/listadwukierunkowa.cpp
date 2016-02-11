#include <iostream>

using namespace std;

struct node{
    int n;
    node *prev;
    node *next;
};

void add(node *&f, int w)
{
    node *tmp;
    tmp=new node;
    tmp->n=w;
    if(f==NULL)
    {
        f=tmp;
        f->next=NULL;
        f->prev=NULL;
    }
    else
    {
        f->prev=tmp;
        tmp->next=f;
        f=tmp;
    }
}
void wypisz(node *f)
{
    while(f!=NULL)
    {
        cout<<f->n<< " ";
        f=f->next;
    }
}
void addin(node *&f, int n, int w);
void delin(node *&first, int n);
int main()
{
    node *lista;
    lista=NULL;
    add(lista,5);
    add(lista,5);
    add(lista,69);
    add(lista,69);
    add(lista,61);
    add(lista,69);
    add(lista,5);
    wypisz(lista);
    //addin(lista, 3, 200);
    delin(lista,10);
    cout<<endl;
    wypisz(lista);
}



/*
Dana jest zmienna globalna wskazująca na początek listy. Proszę napisać procedurę, która
wstawia do powyższej listy nowy element typu wezel na n-tą pozycję. Można założyć, że lista
posiada co najmniej n elementów. Do procedury należy przekazać: wskaźnik na początek listy,
wstawiany element oraz pozycję, na której należy wstawić nowy element.
*/
void addin(node *&first, int n, int w)
{
    node *p, *f;
    f=first;
    for(int i=0;i<n;i++)
    {
        p=f;
        f=f->next;
    }
    node *tmp;
    tmp = new node;
    tmp->n=w;
    tmp->next=f;
    f->prev=tmp;
    if(n>0)
    {
        tmp->prev=p;
        p->next=tmp;
    }
    else
    {
        tmp->prev=NULL;
        first=tmp;
    }
}
/*
Dana jest zmienna globalna wskazująca na początek listy. Proszę napisać procedurę, która z
powyższej listy usuwa z n-ty element, jeżeli lista posiada co najmniej n elementów; jeżeli lista
posiada mniej niż n elementów procedura nie robi nic. Do procedury należy przekazać
wskaźnik na początek listy oraz numer elementu do usunięcia.
*/
void delin(node *&first, int n)
{
    if(first==NULL)return;
    node *tmp;
    if(n==0)
    {
        tmp=first;
        first=first->next;
        delete tmp;
        first->prev=NULL;
        return;
    }
    node *f, *p;
    f=first;
    while(n>0 and f!=NULL)
    {
        f=f->next;
        n--;
    }
    if(n>0)return;
    tmp=f->prev;
    tmp->next=f->next;
    tmp=f->next;
    tmp->prev=f->prev;
    delete f;
}
