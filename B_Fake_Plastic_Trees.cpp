#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>parent(n,-1),leaf(n,1),visited(n);
    vector<pair<int,int>>a(n);
    for(int i=0;i<n-1;++i)
    {
        int u=i+1,v;
        cin>>v;v--;
        parent[u]=v;
        leaf[v]=0;
    }
    a.push_back({0,0});
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first>>a[i].second;
    }
    queue<int>leaves;
    for(int i=0;i<n;++i)
    {
        if(leaf[i])
        {
            leaves.push(i);
            visited[i]=1;
        }
    }
    vector<int>dp(n);
    int count=0;
    while(!leaves.empty())
    {
        int v=leaves.front();
        leaves.pop();
        int l=a[v].first,r=a[v].second;
        if(parent[v]==-1)
        {
            if(l>dp[v])
            {
                count++;
            }
            continue;
        }
        (((l>dp[v])?count++,dp[parent[v]]+=(dp[v]+(r-dp[v])):dp[parent[v]]+=min(dp[v],r)));
        if(!visited[parent[v]])
        {
            visited[parent[v]]=1;
            leaves.push(parent[v]);
        }
    }
    cout<<count<<endl;
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