#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>adj[200005];
int n,t;
bool dfs(int node,int parent,int target)
{
    if(node==target)
    {
        return true;
    }
    for(auto it:adj[node])
    {
        if(it!=parent && !dfs(it,node,target))
        {
            return false;
        }
    }
    return false;
}
void sol()
{
    cin>>n>>t;
    for(int i=0;i<n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    int vis;
    cin>>vis;
    if(dfs(vis-1,-1,0) && dfs(vis-1,-1,n-1) && t%3==0)
    {
        cout<<"Hermione"<<endl;
    }
    else
    {
        cout<<"Ron"<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}