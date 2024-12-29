#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
vector<int>adj[N];
int F,S,ans,res[N],init[N],n;

//Rajat joshi template - modified DFS
void dfs(int u,int p,int depth,int &lc,int par)
{
    for(int i=0;i<adj[u].size();++i)
    {
        int x=adj[u][i];
        if(x==p)continue;
        dfs(x,u,depth+1,lc,init[u]);
        res[u]+=res[x];
    }
    if(adj[u].size()==1)lc++;
    if(init[u]==1)
    {
        int rem=n-S-F,deg=adj[u].size();
        for(int i=0;i<adj[u].size();++i)
        {
            int x=adj[u][i];
            if(x!=p) ans+=res[x]*(deg-1),rem-=res[x];
        }
        ans+=rem*(deg-1);
    }
    if(init[u]==2)res[u]++;
    // if(init[u]==0)F--;
}
void dfs2(int u,int p,int depth,int &lc,int par)
{
    for(int i=0;i<adj[u].size();++i)
    {
        int x=adj[u][i];
        if(x==p)continue;
        dfs2(x,u,depth+1,lc,init[u]);
    }
    if(adj[u].size()==1)lc++;
}
void sol()
{
    cin>>n;
    F=0;S=0;ans=0;
    for(int i=0;i<n;++i)
    {
        adj[i].clear(),res[i]=0,init[i]=2;
    }
    for(int i=0;i<n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;++i)
    {
        if(adj[i].size()==1)
        {
            init[i]=0;
            int p=adj[i][0],q=adj[p][0];
            // if(q==i)q=adj[p][1];
            // init[q]=min<int>(init[q],1);
            init[p]=min<int>(init[p],1);
        }
    }
    // dfs2(0,-1,0,F,-1);
    for(int i=0;i<n;++i)
    {
        if(init[i]==0)F++;
        if(init[i]==1)S++;
    }
    ans=S*F;
    int lc=0;
    // for(int i=0;i<n;++i)
    // {
    //     if(init[i]==2)lc++;
    // }
    dfs(n-1,-1,0,lc,-1);
    cout<<ans<<endl;
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