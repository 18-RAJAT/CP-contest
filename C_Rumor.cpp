#include<bits/stdc++.h>
using namespace std;
#define int long long
int visited[100005],cost[100005];
vector<int>adj[100005];
void sol()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        cin>>cost[i];
    }
    int sum=0;
    int x,y;
    for(int i=0;i<m;++i)
    {
        cin>>x>>y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    function<int(int,int)>dfs=[&](int u,int c)->int
    {
        visited[u]=1;
        c=min(c,cost[u]);
        for(auto& v:adj[u])
        {
            if(visited[v]==0)
            {
                c=min(c,dfs(v,c));
            }
        }
        return c;
    };
    for(int i=0;i<n;++i)
    {
        if(visited[i]==0)
        {
            sum+=dfs(i,1e18);
        }
    }
    cout<<sum;
}
signed main()
{
    sol();
    return 0;
}