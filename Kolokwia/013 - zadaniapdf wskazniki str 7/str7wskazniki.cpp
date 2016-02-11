#include <iostream>
using namespace std;

struct node{
    int n;
    node *next;
};
void add(node *&f, int w)
{
    node *tmp;
    tmp=new node;
    tmp->n=w;
    tmp->next=f;
    f=tmp;
}
void wypisz(node *f)
{
    while(f!=NULL)
    {
        cout<<f->n<<" ";
        f=f->next;
    }
}
node *odwroc(node *f);
node *rekurencjaodwracanie(node *f);
node *usunnajdluzszylancuch(node *f);
node *sumamnogosciowa(node *l1, node *l2);
node *usunmniejsze(node *f);

int main()
{/*
    node *lista;
    lista=NULL;
    add(lista,1);
    add(lista,2);
    add(lista,-11);
    add(lista,4);
    add(lista,5);
    add(lista,4);
    add(lista,100);
    lista=odwroc(lista);
    wypisz(lista);
    /*
    cout<<endl;
    wypisz(lista);
    cout<<endl;
    lista=rekurencjaodwracanie(lista);
    wypisz(lista);
    lista=usunnajdluzszylancuch(lista);
    cout<<endl;
    wypisz(lista);
    *//*
    node *l1, *l2;
    l1=NULL;
    l2=NULL;
    add(l1,2);
    add(l1,3);
    add(l1,5);
    add(l1,7);
    add(l1,11);
    add(l2,8);
    add(l2,2);
    add(l2,7);
    add(l2,4);
    l2=rekurencjaodwracanie(l2);
    l1=rekurencjaodwracanie(l1);
    wypisz(l1);
    cout<<endl;
    wypisz(l2);
    l1=sumamnogosciowa(l1,l2);
    cout<<endl<<endl;
    wypisz(l1);*/
    node *l1;
    l1=NULL;
    add(l1,7);
    add(l1,13);
    add(l1,7);
    add(l1,21);
    add(l1,25);
    add(l1,25);
    add(l1,1);
    add(l1,7);
    l1=rekurencjaodwracanie(l1);
    wypisz(l1);
    //l1=usunmniejsze(l1);
    l1=usunmodulo(l1);
    cout<<endl;
    wypisz(l1);
}

/*
Proszę napisać procedurę odwracającą kolejność elementów w liście
jednokierunkowej. Proszę napisać definicje odpowiednich typów.
*/
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

/*
Rekurencyjne odwracanie listy
wkaznik do pierwszego elementu, ostatniego poprzez referencje.
Wywołujemy funkcje rekurencyjne do momentu wywołania pustej listy, wtedy zostaje zwrócony ostatni element(ten z referencją przekazywany, nie jest w tym etapie zmieniany)
W kazdym wywołaniu do tmp zapisujemy wartosc o ktora skrocilismy liste przed przekazaniem dalej, zapisujemy liste to co nam zwraca funkcja i na ostani element
(ten z referencja) podpinamy element z tmp. Zmieniamy wartosc ostatniego elementu(tego z referencja) na ten który doczepiliśmy.
zwracamy lancuch
*/
node *odwrocR(node *f, node *&l)
{
    node *tmp;
    if(f!=NULL)
    {
        tmp=f;
        f=odwrocR(f->next,l);
        tmp->next=NULL;
        l->next=tmp;
        l=tmp;
        return f;
    } else return l;
}
node *rekurencjaodwracanie(node *f)
{
    node *tmp, *tmp2;
    tmp2=f;
    while(tmp2!=NULL)
    {
        tmp=tmp2;
        tmp2=tmp2->next;
    }
    return odwrocR(f, tmp);
}

/*
Kolejne elementy łańcucha o zwiększającej się wartości pola val
nazywamy podłańcuchem rosnącym. Proszę napisać procedurę, która
usuwa z łańcucha wejściowego najdłuższy podłańcuch rosnący.
Warunkiem usunięcia jest istnienie w łańcuchu dokładnie jednego
najdłuższego podłańcucha rosnącego.
*/
node *usunnajdluzszylancuch(node *f)
{
    int maks, last, i;
    maks=last=i=0;
    bool moznausunac =true;
    node *first;
    first=f;
    node *prev;//wwskaznik do el przed pierwszym w ciagu rosnacym
    prev=NULL;
    node *tmp, *p;
    p=NULL;//poprzedni element (ogon)
    last=f->n;
    while(f!=NULL)
    {
        if(last<f->n) i++;
        else
        {
            if(i>maks)
            {
                moznausunac=true;
                maks=i;
                prev=tmp;
            }
            else if(i==maks) moznausunac=false;
            i=1;
            tmp=p;
        }
        last=f->n;
        p=f;
        f=f->next;
    }
    if(i>maks)
    {
        moznausunac=true;
        maks=i;
        prev=tmp;
    }
    if(maks==0 or !moznausunac) return first;
    f=first;
    if(prev==NULL)
    {
        for(int j=0;j<maks;j++)
        {
            tmp=f;
            f=f->next;
            delete tmp;
        }
    }
    else
    {
        p=prev->next;
        for(int j=0;j<maks;j++)
        {
            tmp=p;
            p=p->next;
            delete tmp;
        }
        prev->next=p;
    }
    return f;
}
/*
Dane są dwa niepuste łańcuchy, z których każdy zawiera
niepowtarzające się elementy. Elementy w pierwszym łańcuchu są
uporządkowane rosnąco, w drugim elementy występują w przypadkowej
kolejności. Proszę napisać procedurę, która z dwóch takich łańcuchów
stworzy jeden, w którym uporządkowane elementy będą stanowić sumę
mnogościową elementów z łańcuchów wejściowych.
Do procedury należy przekazać wskazania na oba łańcuchy. Na przykład
dla łańcuchów:
2 -> 3 -> 5 ->7-> 11
8 -> 2 -> 7 -> 4
powinien pozostać łańcuch:
2 -> 3 -> 4 -> 5 ->7-> 8 -> 11
*/
node *sumamnogosciowa(node *l1, node *l2)
{
    if (l1==NULL) return l2;//posortowac;
    if (l2==NULL) return l1;
    node *tmp, *p, *t;
    while(l2!=NULL)
    {
        tmp=l1;
        p=NULL;
        while(tmp->n <l2->n and tmp!=NULL)
        {
            p=tmp;
            tmp=tmp->next;

        }
        if(tmp->n!=l2->n)
        {
            //cout<<l2->n<<" ";
            t=l2;
            l2=l2->next;
            if(p==NULL)
            {
                t->next=l1;
                l1=t;
            }
            else
            {
                p->next=t;
                t->next=tmp;
            }
        } else l2=l2->next;
    }
    return l1;
}


/*
Proszę napisać procedurę, otrzymującą jako parametr wskaźnik napierwszy element jednokierunkowego łańcucha odsyłaczowego o
wartościach typu Integer, usuwającą wszystkie elementy, których
wartość jest mniejsza od wartości bezpośrednio poprzedzających je
elementów. Proszę zadeklarować odpowiednie typy.
*/
node *usunmniejsze(node *f)
{
    int pval=f->n;
    node *prev, *w, *tmp;
    w=f;
    while(f!=NULL)
    {
        if(pval>f->n)
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

