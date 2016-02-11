#include <iostream>
using namespace std;

struct node{
    int w;
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
    n->w=l;
    n->next=NULL;
    if(prev==NULL) return n;
    prev->next=n;
    return fi;
}
void wypisz(node *f)
{
    while(f!=NULL)
    {
        cout<<f->w<<" ";
        f=f->next;
    }
}

void usun(node *&f1, node *&f2);
int main()
{
    node *f1, *f2;
    f1=f2=NULL;
    f1=add(f1,5);
    f1=add(f1,7);
    f1=add(f1,56);
    f1=add(f1,588);
    f1=add(f1,5889);
    f1=add(f1,58811);
    wypisz(f1);
    f2=add(f2,56);
    f2=add(f2,5611);
    f2=add(f2,1);
    f2=add(f2,17);
    f2=add(f2,5);
    f2=add(f2,7);
    cout<<endl;
    wypisz(f2);
    usun(f1,f2);
    cout<<endl;
    wypisz(f1);cout<<endl;
    wypisz(f2);

}

void usun(node *&f1, node *&f2)
{
    node *tmp, *f, *prev1, *prev2, *w;
    bool dalej=false;
    w=f2;
    prev2=NULL;
    while(f2!=NULL)
    {
        f=f1;
        prev1=NULL;
        while(f!=NULL and f2->w>f->w)
        {
            prev1=f;
            f=f->next;
        }

        if(f!=NULL and f->w==f2->w)
        {
            tmp=f2;
            f2=f2->next;
            if(prev2==NULL) w=f2;
            else prev2->next=f2;
            delete tmp;
            tmp=f;
            f=f->next;
            if(prev1==NULL)f1=f;
            else  prev1->next=f;
            delete tmp;
        }else{
        prev2=f2;
        f2=f2->next;
        }
    }
    f2=w;
}
