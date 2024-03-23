#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans=0;
int dfs(int current,vector<vector<int>>& adj,vector<bool>& visited,int middle)
{
    int count=1;
    visited[current]=true;
    for(auto& it:adj[current])
    {
        if(visited[it])
        {
            continue;
        }
        count+=dfs(it,adj,visited,middle);
    }
    if(middle<=count)
    {
        ans++,count=0;
    }
    return count;
}
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>>adj(n+1);
    vector<bool>visited(n+1,false);
    for(int i=0;i<n-1;++i)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int low=1,high=1e9,res=1;
    while(low<=high)
    {
        int middle=(low+high)/2;
        ans=0;
        visited.assign(n+1,false);
        dfs(1,adj,visited,middle);
        if(k<ans)
        {
            res=max(res,middle);
            low=middle+1;
        }
        else
        {
            high=middle-1;
        }
        fill(visited.begin(),visited.end(),false);
    }
    cout<<res<<endl;
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