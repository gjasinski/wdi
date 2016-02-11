#include <iostream>

using namespace std;

struct node
{
    int value;
    node *next;
};

void init(node *&n);
bool empty(node *n);
void push(node *&n, int v);
int pop(node *&n);

int main()
{
    node *p;
    init(p);
    push(p,10);
    push(p,10);
    push(p,10);
    push(p,5);
    cout<<pop(p);
    cout<<pop(p);
    cout<<pop(p);
    cout<<pop(p);
    cout<<pop(p);
    cout<<pop(p);
}

//inicjalizacja stosu
void init(node *&n)
{
    n=NULL;
}
//funkcja sprawdza czy stos jest putsy
//true jest pusty
//false nie jest pusty
bool empty(node *n)
{
    return n==NULL;
}

//funkcja dodaje element na stos
void push(node *&n, int v)
{
    node *tmp;
    tmp = new node;
    if(empty(n))
    {
        tmp->value=v;
        tmp->next=NULL;
        n=tmp;
    }
    else
    {
        tmp->value=n->value;
        tmp->next=n->next;
        n->value=v;
        n->next=tmp;
    }
}

//funkcja zwraca element ze stosu i go zdejmuje
int pop(node *&n)
{
    if(empty(n))return -1;
    int t = n->value;
    if(empty(n->next))
    {
        delete n;
        n=NULL;
    }
    else
    {
        node *tmp = n->next;
        n->value=n->next->value;
        n->next=n->next->next;
        delete tmp;
    }
    return t;
}
