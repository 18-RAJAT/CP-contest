#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans=0;
    vector<bool>visited(n+1,false);
    function<bool(int,vector<int>[],vector<bool>&)>solve=[&](int x, vector<int> Adj[], vector<bool> &visited)->bool
    {
        bool ans=Adj[x].size()==2;
        queue<int>q;
        q.push(x);
        visited[x]=true;
        while(q.size()>0)
        {
            auto front=q.front();
            q.pop();
            ans&= Adj[front].size()==2;
            for(int &adjacent:Adj[front])
            {
                if(!visited[adjacent])
                {
                    visited[adjacent]=true;
                    q.push(adjacent);
                }
            }
        }
        return ans;
    };
    for(int i=1;i<=n;++i)
    {
        if(visited[i])
        {
            continue;
        }
        if(solve(i,adj,visited))
        {
            ans++;
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}