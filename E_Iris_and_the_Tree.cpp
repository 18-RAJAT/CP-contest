#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000005;
multiset<int>Adj[N];
int cnt,ans,n,weight;
int Tree[N],Parent[N];

int step_prev(int x){return (x==1)?n:x-1;}
int step_next(int x){return (x==n)?1:x+1;}
int find(int v)
{
    if(v!=Parent[v])
    {
        Parent[v]=find(Parent[v]);
    }
    return Parent[v];
}
int merge(int x,int y)
{
    x=find(x),y=find(y);
    if(Adj[x].size()>Adj[y].size())swap(x,y);
    Parent[x]=y;
    for(auto& it:Adj[x])
    {
        cnt+=Adj[y].count(step_next(it))+Adj[y].count(step_prev(it));
    }
    Adj[y].insert(Adj[x].begin(),Adj[x].end());
}
void sol()
{
    cin>>n>>weight;
    for(int i=2;i<=n;++i)cin>>Tree[i];
    for(int i=1;i<=n;++i)
    {
        Parent[i]=i,Adj[i].insert(i);
    }
    cnt=ans=0;
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        ans+=2*y,weight-=y;
        merge(x,Tree[x]);
        cout<<(ans+((n-cnt)*weight*1LL))<<" "[i==n-1];
    }
    cout<<endl;
    for(int i=1;i<=n;++i)
    {
        assert(i>=1 && i<=n);
        Adj[i].clear();
    }
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}