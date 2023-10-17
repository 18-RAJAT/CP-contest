#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>graph;
int dp[5005];
void sol()
{
    function<int(int)>calc_child=[&](int node)->int
    {
        int& res=dp[node];
        if(~res)
        {
            return res;
        }
        int ans=0;
        for(auto& it:graph[node])
        {
            ans+=calc_child(it);
        }
        return res=ans+1;//node itself+1
    };
    function<int(int)>dfs=[&](int node)->int
    {
        int mx_child=0;
        for(auto& it:graph[node])
        {
            mx_child=max(mx_child,calc_child(it));
        }
        int ans=0;
        for(auto& it:graph[node])
        {
            ans+=mx_child*calc_child(it);//calculate the number of pairs of nodes that are not connected to each other in the subtree of node it and node node
            ans+=dfs(it);
        }
        ans-=mx_child*mx_child;
        return ans;
    };
    int n;
    cin>>n;
    graph.resize(n+1);
    for(int i=2;i<=n;++i)
    {
        int x;
        cin>>x;
        graph[x].push_back(i);
    }
    memset(dp,-1,sizeof(dp));
    cout<<dfs(1);
}
signed main()
{
    sol();
    return 0;
}