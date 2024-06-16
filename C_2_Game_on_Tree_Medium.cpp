#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX=1000005;
vector<int>adj[MAX];
int n,t,u,v;
int dfs(int child,int parent)
{
    int sum=0;
    for(auto& edge:adj[child])
    {
        if(edge!=parent)sum+=(dfs(edge,child)==0);
    }
    return sum>=1;
}
void sol()
{
    cin>>n>>t;
    for(int i=1;i<n;++i)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin>>u;
    cout<<(dfs(u,0)==1?"Ron":"Hermione");
}
signed main()
{
    sol();
    return 0;
}