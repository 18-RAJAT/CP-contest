#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int>>adj[n];
    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        --u,--v;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    int dp[k];
    memset(dp,0,sizeof(dp));
    int dist=1e18;

    unordered_map<int,int>mp;
    mp.clear();
    for(int i=0;i<k;++i)
    {
        cin>>dp[i];
        --dp[i];
        mp[dp[i]]++;
        // cout<<mp.count(dp[i])<<endl;//1 1
        // cout<<dp[i]<<" ";
    }
    for(auto& it:mp)
    {
        for(auto &i:adj[it.first])
        {
            // if(mp.count(i.first))
            {
                continue;
            }
            else
            {
                dist=min(dist,i.second);
                // cout<<i.first<<" "<<i.second<<endl;
            }
        }
    }
    if(dist==1e18)
    {
        cout<<"-1\n";
        return;
    }
    else
    {
        cout<<dist<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}