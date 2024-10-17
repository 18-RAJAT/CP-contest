#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1,vector<int>());
    for(int i=0;i<n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n<=3)
    {
        cout<<-1<<endl;
        return;
    }
    vector<int>take,leave;
    for(int i=1;i<=n;++i)
    {
        if(adj[i].size()==1)take.push_back(i);
        else leave.push_back(i);
    }
    int root=1,state=adj[1].size();
    for(int i=2;i<=n;++i)
    {
        if(adj[i].size()>state)
        {
            root=i;
            state=adj[i].size();
        }
    }
    vector<int>depth(n+1,-1);
    queue<int>q;
    depth[root]=0;
    q.push(root);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(auto&v:adj[u])
        {
            if(depth[v]==-1)
            {
                depth[v]=depth[u]+1;
                q.push(v);
            }
        }
    }
    sort(leave.begin(),leave.end(),[&](int&a,int&b)->bool
    {
        if(depth[a]!=depth[b])return depth[a]>depth[b];
        return a<b;
    });
    sort(take.begin(),take.end(),[&](int&a,int&b)->bool
    {
        if(depth[a]!=depth[b])return depth[a]>depth[b];
        return a<b;
    });
    vector<int>dp;
    for(int i=0;i<take.size();++i)dp.push_back(take[i]);
    for(int i=0;i<leave.size();++i)dp.push_back(leave[i]);
    for(int i=0;i<dp.size();i++)
    {
        cout<<dp[i]<<(i<dp.size()-1?" ":"\n");
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