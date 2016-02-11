#include <iostream>

using namespace std;

struct node
{
    int n;
    node *next;
};
node* addOnBeginning(node *first);
void writeOut(node *first);
void writeOutBack(node *first);
void writeOutNormal(node *first);
void addOnEnd(node *&first);
void deleteEnd(node *first);
void deleteBegginning(node *&first);
void insertInOrder(node *&first, int w);
node * reverseList(node *first);

int main()
{
    node *first;

    first = new node;
    first = NULL;
    //addOnEnd(first);
    //addOnEnd(first);
    /*
    first = addOnBeginning(first);
    first = addOnBeginning(first);
    first = addOnBeginning(first);
    first = addOnBeginning(first);*/

    int tmp;
    cin>>tmp;
    insertInOrder(first,tmp);
    cin>>tmp;
    insertInOrder(first,tmp);
    cin>>tmp;
    insertInOrder(first,tmp);
    cin>>tmp;
    insertInOrder(first,tmp);
    cin>>tmp;
    insertInOrder(first,tmp);
    //writeOut(first);
    //addOnEnd(first);
    writeOutNormal(first);
    cout<<endl;
    first=reverseList(first);
    writeOutNormal(first);
    //deleteEnd(first);
    //deleteBegginning(first);
    //cout<<endl;
    //writeOutNormal(first);
    return 0;
}

/*
    Funkcja insert można zrealizować
    1) Przez referencje
    void insert(node *&f, int i);
    2) Przez zwracanie wskaźnika
    node * insert(node *f, int i);
*/


node* addOnBeginning(node *first)    //addOnBeginning(first);
{
/*
    Dodanie elementu na poczatku listy
    Funkcja zwraca wskaznik do poczatku listy
*/
    node *tmp;
    tmp = new node;
    cin>>tmp->n;
    tmp->next=first;
    first=tmp;
}

void addOnEnd(node *&first)   //addOnEnd(first)
{
/*
    Dodanie elementu na koncu listy
    Funkcja nie zwraca wskaznika do poczatku listy,
    przekazanie wskaźnika odbywa się przez referencje.
    to jest konieczne gdy lista jest pusta.
*/
    node *last;
    node *p;
    last=NULL;
    p=first;
    while(p!=NULL)
    {
        last=p;
        p=p->next;
    }
    p = new node;
    cin>>p->n;
    p->next=NULL;
    if(last!=NULL)
    {
        last->next=p;
        last=last->next;
    }
    else    first=last=p;
}

void writeOutNormal(node *first) //writeOutNormal(first);
{
/*
    Normalne wypisanie listy
*/
    while(first!=NULL)
    {
        cout<<first->n<<" ";
        first=first->next;
    }
}

void writeOut(node *first)  //writeOut(first);
{
/*
    Rekurencyjne wypisanie listy
*/
    if(first!=NULL)
    {
        cout<<first->n<<" ";
        writeOut(first->next);
    }
}

void writeOutBack(node *first)  //writeOutBack(first)
{
/*
    Rekurencyjne wypisanie listy od końca
*/
    if(first!=NULL)
    {
        writeOutBack(first->next);
        cout<<first->n<<" ";
    }
}

void deleteEnd(node *first)
{
/*
    Usuwanie elementu na koncu listy
*/
    node *last;
    node *llast;
    last=llast=NULL;
    while (first!=NULL)
    {
        llast=last;
        last=first;
        first=first->next;
    }
    delete last;
    llast->next=NULL;
}

void deleteBegginning(node *&first)
{
/*
    Usuwanie elementu na poczatku listy
*/
    node *tmp;
    tmp=first;
    if(first->next==NULL)
    {
        delete first;
        first=NULL;
    }
    else
    {
        tmp=first;
        first=first->next;
        delete tmp;
    }

}
//funkcja dodająca elemento do odpowiedniego miejsca w liście według jego wartości
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
node * reverseList(node *first)
{
    if(first == NULL or first->next==NULL)return first;
    node *p, *q, *r,*tmp;
    p=NULL;
    q=first;
    while(q!=NULL)
    {
    tmp=q->next;
     r=q;
     r->next=p;
     p=r;
     q=tmp;

    }
    return r;
    /*
    q=f;
    r=q->next;
    while (q!=NULL)
    {
        q->next=p;
        p=q;
        q=r;
    }*/
}

/*
    Funkcje dodatkowe

void addInMiddle(node *middle)
{

    //Dodanie elementu za elementem middle.

    node *p;
    p = new node;
    p->next = middle->next;
    cin>> p->n;
    middle->next=p;

}

void usunwSrodkuPo(node *f)
{
    //Usuniecie elementu za elementem f;
    node *tmp;
    tmp=f->next;
    f->next=tmp->next;
    delete tmp;
}*/
