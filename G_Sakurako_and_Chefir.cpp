#include<bits/stdc++.h>
using namespace std;
#define long long int

const int MAX=200005;
const int LOG=20;
vector<vector<int>>adj(MAX);
int nodes[MAX],subtree[MAX];
int DpTable[LOG][MAX];

void dfs(int u,int parent)
{
    DpTable[0][u]=parent;
    nodes[u]=nodes[parent]+1;
    subtree[u]=nodes[u];
    for(auto&v:adj[u])
    {
        if(v==parent)continue;
        dfs(v,u);
        subtree[u]=max(subtree[u],subtree[v]);
    }
}

void preprocess(int n)
{
    for(int k=1;k<LOG;++k)
    {
        for(int u=1;u<=n;++u)
        {
            if(~DpTable[k-1][u])
            {
                DpTable[k][u]=DpTable[k-1][DpTable[k-1][u]];
            }
            else
            {
                DpTable[k][u]=-1;
            }
        }
    }
}

int sol(int u,int dep)
{
    if(nodes[u]<dep)return -1;
    for(int k=LOG-1;k>=0;--k)
    {
        if(~DpTable[k][u] && nodes[DpTable[k][u]]>=dep)
        {
            u=DpTable[k][u];
        }
    }
    return u;
}

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            adj[i].clear();
        }
        for(int i=1;i<n;++i)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(DpTable,-1,sizeof(DpTable));
        nodes[1]=0;
        dfs(1,0);
        preprocess(n);
        int depth=0;
        for(int i=1;i<=n;++i)
        {
            depth=max(depth,subtree[i]);
        }
        int q;
        cin>>q;
        while(q--)
        {
            int vi;
            int ki;
            cin>>vi>>ki;
            int option1=subtree[vi]-nodes[vi];
            int dep=nodes[vi]-ki;
            if(dep<1)dep=1;
            int ancestor=sol(vi,dep);
            if(ancestor==-1)ancestor=1;
            int option2=subtree[ancestor]-nodes[ancestor]+ki;
            int max_dist=max(option1,option2);
            cout<<max_dist<<" ";
        }
        cout<<endl;
    }
    return 0;
}