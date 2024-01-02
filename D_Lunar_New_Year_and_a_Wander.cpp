#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100'005;
vector<int>adj[N];
bool vis[N];
void sol()
{
    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;++i)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=v;++i)
    {
        vis[i]=false;
    }
    priority_queue<int,vector<int>,greater<int>>pq;
    pq.push(1);
    vis[1]=1;
    while(!pq.empty())
    {
        int current=pq.top();
        pq.pop();
        cout<<current<<" ";
        for(auto& i:adj[current])
        {
            if(vis[i])
            {
                continue;
            }
            else
            {
                vis[i]=true;
                pq.push(i);
            }
        }
    }
}
signed main()
{
    sol();
    return 0;
}