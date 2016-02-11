#include <iostream>
using namespace std;

struct node{
    int n;
    node *next;
};
void wypisz(node *f)
{
    while(f!=NULL)
    {
        cout<<f->n<<" ";
        f=f->next;
    }
}

void add(node *&f, int w)
{
    node *tmp;
    tmp=new node;
    tmp->n=w;
    tmp->next=f;
    f=tmp;
}
node *odwroc(node *f)
{
    node *w, *tmp;
    w=NULL;
    while(f!=NULL)
    {
        tmp=f;
        f=f->next;
        tmp->next=w;
        w=tmp;

    }
    return w;
}
node *usunwiecej(node *f);
node *dajnastart(node *f);
node *usunbinarnie(node *f);
node *mergel(node *f1, node *f2);
int main()
{
    /*node *f;
    f=NULL;
    add(f,1);
    add(f,43);
    add(f,1);
    add(f,1301);
    add(f,43);
    add(f,11);
    add(f,186973);
    add(f,124);
    add(f,1);
    wypisz(f);
    //f=odwroc(f);
    //f=usunwiecej(f);
    //f=dajnastart(f);
    f=usunbinarnie(f);*/

    node *f1, *f2;
    f1=f2=NULL;
    add(f1,30);
    add(f1,20);
    add(f1,15);
    add(f1,11);
    add(f1,10);
    add(f1,3);
    add(f2,30);
    add(f2,15);
    add(f2,10);
    add(f2,5);
    add(f2,3);
    wypisz(f1);
    cout<<endl;
    wypisz(f2);
    f1=mergel(f1,f2);
    cout<<endl;
    wypisz(f1);
}


/*
Proszę napisać procedurę, otrzymującą jako parametr wskaźnik na
pierwszy element jednokierunkowego łańcucha odsyłaczowego o
wartościach typu Integer, usuwającą wszystkie elementy, których
wartość dzieli bez reszty wartość bezpośrednio następujących po nich
elementów. Proszę zadeklarować odpowiednie typy.
*/

node *usunmodulo(node *f)
{
    int pval=f->n;
    node *prev, *tmp, *w;
    w=f;
    prev=f;
    f=f->next;

    while (f!=NULL)
    {
        if(f->n%pval==0)
        {
            tmp=f;
            f=f->next;
            prev->next=f;
            delete tmp;
            if(f==NULL) break;
        }
        pval=f->n;
        prev=f;
        f=f->next;
    }
    return w;
}

/*
Proszę napisać procedurę, która otrzymując jako parametr zmienną
head (wskazującą na początek listy jednokierunkowej), usuwa z niej
wszystkie elementy, w których wartość klucza w zapisie trójkowym ma
większą ilość jedynek niż dwójek. Proszę zadeklarować odpowiednie
typy.
*/
int ileliczb(int liczba, int szukana)
{
    int licz=0;
    while(liczba>0)
    {
        if(liczba%3==szukana) licz++;
        liczba=liczba/3;
    }
    return licz;
}
bool usun(int liczba)
{
    return ileliczb(liczba,1)>ileliczb(liczba,2);
}
node *usunwiecej(node *f)
{
    node *prev, *tmp, *w;
    while(usun(f->n) and f!=NULL)
    {
        tmp=f;
        f=f->next;
        delete tmp;
    }
    prev=f;
    w=f;
    f=f->next;
    while(f!=NULL)
    {
        if(usun(f->n))
        {
            tmp=f;
            f=f->next;
            prev->next=f;
            delete tmp;
        }
        else
        {
            prev=f;
            f=f->next;
        }
    }
    return w;
}
/*
Proszę napisać procedurę, która otrzymując jako parametr zmienną
head (wskazującą na początek listy jednokierunkowej), przenosi na
początek listy te z nich, które mają parzystą ilość piątek w zapisie
ósemkowym. Proszę zadeklarować odpowiednie typy.
*/
int ilepiatek(int liczba)
{
    int licz=0;
    while(liczba>0)
    {
        if(liczba%8==5)licz++;
        liczba=liczba/8;
    }
    return licz;
}
bool parzystepiatki(int liczba)
{
    int tmp=ilepiatek(liczba);
    return (tmp%2==0 and tmp>0);
}
node *dajnastart(node *f)
{
    node *first, *tmp, *prev;
    first=f;
    prev=f;
    if(f!=NULL)f=f->next;
    while(f!=NULL)
    {
        if(parzystepiatki(f->n))
        {

            tmp=f;
            f=f->next;
            prev->next=f;
            tmp->next=first;
            first=tmp;
        }
        else
        {
            prev=f;
            f=f->next;
        }
    }
    return first;
}
/*
Proszę napisać procedurę, która otrzymując jako parametr zmienną
head (wskazującą na początek listy dwukierunkowej), usuwa z niej
wszystkie elementy, w których wartość klucza w zapisie binarnym ma
nieparzystą ilość jedynek. Proszę zadeklarować odpowiednie typy.
*/
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
node *usunbinarnie(node *f)
{
    node *first, *prev, *tmp;
    prev=NULL;
    while(f!=NULL and ilejedynek(f->n)%2==1)
    {
        tmp=f;
        f=f->next;
        delete tmp;
    }
    if(f==NULL) return NULL;
    prev=f;
    first=f->next;
    while(first!=NULL)
    {
        if(ilejedynek(first->n)%2==1)
        {
            tmp=first;
            first=first->next;
            prev->next=first;
            delete tmp;
        }
        else
        {
            prev=first;
            first=first->next;
        }

    }
    return f;
}
/*
Dane są dwie uporządkowane listy zawierające niepowtarzające się
liczby naturalne. Proszę napisać funkcję scalającą dwie listy tak,
aby scalona lista zawierała niepowtarzające się elementy występujące
w jednej lub drugiej liście. Funkcja powinna zwrócić wskaźnik do
scalonej listy.
*/

node *mergel(node *f1, node *f2)
{
    if(f1==NULL)return f2;
    if(f2==NULL)return f1;
    node *w, *wlast, *tmp;
    if(f1->n < f2->n)
    {
        w=wlast=f1;
        f1=f1->next;
    }
    else
    {
        if(f1->n==f2->n)
        {
            tmp=f1;
            f1=f1->next;
            delete tmp;
        }
        w=wlast=f2;
        f2=f2->next;
    }
    while(f1!=NULL and f2!=NULL)
    {
        if(f1->n == f2->n)
        {
            tmp=f2;
            f2=f2->next;
        }
        else
        {
            if(f1->n < f2->n)
            {
                wlast->next=f1;
                wlast=f1;
                f1=f1->next;
                wlast->next=NULL;
            }
            else
            {
                if(f1->n > f2->n)
                {
                    wlast->next=f2;
                    wlast=f2;
                    f2=f2->next;
                    wlast->next=NULL;
                }
            }
        }
    }
    if(f1!=NULL)wlast->next=f1;
    if(f2!=NULL)wlast->next=f2;
    return w;
}
