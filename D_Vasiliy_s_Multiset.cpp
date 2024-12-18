#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
struct Node
{
    Node*ch[2];
    int tot;
};
Node arr[N*30],*val,*ret;
int mask(int x,int i){return (x>>i)&1;}
Node*node()
{
    ret=val++;
    ret->ch[0]=ret->ch[1]=nullptr;
    ret->tot=0;
    return ret;
}
void insert(Node*p,int x,int y)
{
    for(int i=29;~i;--i)
    {
        int k=mask(x,i);
        if(!p->ch[k])p->ch[k]=node();
        p=p->ch[k];
        p->tot+=y;
    }
}
int query(Node*p,int x)
{
    int ret=0;
    for(int i=29;~i;--i)
    {
        int k=mask(x,i);
        k^=1;
        if(p->ch[k] && p->ch[k]->tot)
        {
            p=p->ch[k];
            ret|=1<<i;
        }
        else p=p->ch[k^1];
    }
    return ret;
}
void sol()
{
    int n;
    cin>>n;
    val=arr;
    Node*root=node();
    insert(root,0,1);
    while(n--)
    {
        string s;int x;cin>>s>>x;
        if(s=="+")insert(root,x,1);
        else if(s=="-")insert(root,x,-1);
        else cout<<query(root,x)<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}