#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>path;
    unordered_map<int,vector<int>>mp;
    queue<int>que;
    vector<set<int>>adj(n+1);
    for(int i=0;i<m;++i)
    {
        int u,v,e;
        cin>>u>>v>>e;
        adj[u].insert(e);
        adj[v].insert(e);
        mp[e].push_back(u);
        mp[e].push_back(v);
    }
    int s,t;
    cin>>s>>t;
    path.assign(n+1,1e9);
    path[s]=0;
    que.push(s);
    while(!que.empty())
    {
        int f=que.front();
        que.pop();
        for(auto& init:adj[f])
        {
            for(auto& final:mp[init])
            {
                if(1+path[f]<path[final])
                {
                    path[final]=1+path[f];
                    que.push(final);
                }
            }
        }
    }
    cout<<path[t]<<endl;
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