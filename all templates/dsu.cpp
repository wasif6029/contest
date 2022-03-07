///dsu not fully optimised wasif

#include <bits/stdc++.h>

using namespace std;

void makeset(int * par,int *a)
{
    for(int i:a)
    {
        par[i]=i;
    }
}
int grandparent(int * par,int x)
{
    if(x==par[x])return x;
    return par[x]=grandparent(par[x]);
}

void make_union(int *par,int x,int y)
{
    int parx=grandparent(x);
    int pary=grandparent(y);
    if(parx==pary)return ;
    par[y]=x;
}

int main() {
    
    
    
    
}