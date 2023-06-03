#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<n-2;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    vector<vector<int>>find(2,vector<int>(n+1,-1));
    find[0][a]=find[1][b]=0;
    auto bfs=[&](int src,int k)
    {
        vector<int>vis(n+1);
        queue<int>q;
        q.push(src);
        vis[src]=true;
        while(not q.empty())
        {
            int u=q.front();
            q.pop();
            // for(auto [v,w]:adj[u])
            // {
            // }
            for(auto p:adj[u])
            {
                int v=p.first;
                int w=p.second;
                if(not vis[v])
                {
                    vis[v]=true;
                    find[k][v]=find[k][u]+w;
                    q.push(v);
                }
            }
        }
    };
    bfs(a,0);
    bfs(b,1);
    set<int>st;
    for(int i=1;i<=n;++i)
    {
        st.insert(find[0][i]);
    }
    bool ok=false;
    for(int i=1;i<=n;++i)
    {
        if(i!=b and find[1][i]!=-1)
        {
            ok|=(st.find(find[0][i])!=st.end());
        }
    }
    cout<<(ok?"YES":"NO")<<'\n';
}