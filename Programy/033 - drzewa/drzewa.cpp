#include<iostream>

using namespace std;

struct node{
    int v;
    node *l;
    node *r;
};

void add(node *&proot, int value)
{
    node *n, *prev, *tmp;
    n = new node;
    n->v=value;
    n->l=n->r=NULL;
    if(proot==NULL)proot=n;
    else
    {
        tmp=proot;
        while(tmp!=NULL)
        {
            prev=tmp;
            if(tmp->v>value) tmp=tmp->l;
            else tmp=tmp->r;
        }
        if(prev->v>value) prev->l=n;
        else prev->r=n;
    }
}
void addr(node *&proot, int value)
{
    if(proot==NULL)
    {
        proot=new node;
        proot->v=value;
        proot->l=proot->r=NULL;
    }
    else if(proot->v>value) addr(proot->l,value); else addr(proot->r,value);

}

void wypisz(node *proot)
{
    if(proot!=NULL)
    {
        wypisz(proot->l);
        cout<<proot->v<<endl;
        wypisz(proot->r);
    }
}

int ileJestWezlow(node *proot)
{
    if(proot==NULL) return 0;
    return ileJestWezlow(proot->l)+ileJestWezlow(proot->r)+1;
}
int wysokosc(node *proot)
{
    if(proot==NULL) return 0;
    return max(wysokosc(proot->l),wysokosc(proot->r))+1;
}
int ileJestLisci(node *proot)
{
    if(proot==NULL)return 0;
    if(proot->l==NULL and proot->r==NULL)return 1;
    return ileJestLisci(proot->l)+ileJestLisci(proot->r);
}

int ileNaPoziomie(node *proot, int n)
{
    if(proot==NULL)return 0;
    if(n==0)return 1;
    return ileNaPoziomie(proot->l,n-1)+ileNaPoziomie(proot->r,n-1);
}
bool czyWystepuje(node *p, int s)
{
    if(p==NULL)return false;
    if(p->v==s)return true;
    if(p->v>s)return czyWystepuje(p->l,s);
    else return czyWystepuje(p->r,s);
}
int main()
{
    node *proot;
    proot=NULL;
    add(proot, 5);
    add(proot, 4);
    add(proot, 7);
    add(proot, 7);
    add(proot, 6);
    add(proot, 11);
    wypisz(proot);
    cout<<endl;
    node *proo;
    proo=NULL;
    addr(proo, 5);
    addr(proo, 4);
    addr(proo, 7);
    addr(proo, 7);
    addr(proo, 6);
    addr(proo, 11);
    wypisz(proo);
    //cout<<ileJestWezlow(proot);
    //cout<<wysokosc(proot);
    //cout<<ileJestLisci(proot);
    //cout<<ileNaPoziomie(proot,2);
    //if(!czyWystepuje(proot,111))cout<<"OK";
}
