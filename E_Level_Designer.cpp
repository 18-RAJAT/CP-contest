#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<int>ar(n+1);
    iota(ar.begin(),ar.end(),0);
    function<int(int)>root=[&](int x)
    {
        return x==ar[x]?x:ar[x]=root(ar[x]);
    };
    function<void(int,int)>merge=[&](int x,int y)
    {
        x=root(x);
        y=root(y);
        if(x!=y)
        {
            ar[x]=y;
        }
    };
    while(q--)
    {
        int type,u,v;
        cin>>type>>u>>v;
        if(type==2)
        {
            merge(u,v);
        }
        else
        {
            cout<<(root(u)==root(v)?"Yes":"No")<<endl;
        }
    }
}
signed main()
{
    sol();
    return 0;
}