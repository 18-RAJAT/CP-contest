#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+5);
    vector<int>visited(n+5,0),cover(n+5,0);
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int>q;
    q.push(1);
    while(!q.empty())
    {
        int F=q.front();
        visited[F]=1;
        q.pop();
        for(auto& it:adj[F])
        {
            if(!visited[it])
            {
                q.push(it);
                visited[it]=1;
                cover[it]=cover[F]+1;
            }
        }
    }
    vector<int>prev,nxt;
    for(int i=1;i<n+1;++i)
    {
        if(cover[i]&1)nxt.push_back(i);
        else prev.push_back(i);
    }
    if(prev.size()<nxt.size())
    {
        cout<<prev.size()<<endl;
        for(int i=0;i<prev.size();++i) cout<<prev[i]<<" ";
    }
    else
    {
        cout<<nxt.size()<<endl;
        for(int i=0;i<nxt.size();++i) cout<<nxt[i]<<" ";
    }
    cout<<endl;
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