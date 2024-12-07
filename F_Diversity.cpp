#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX_N=-1e18;
void sol()
{
    int N,X,K;
    cin>>N>>X>>K;
    vector<vector<pair<int,int>>>g(N+1);
    for(int i=0;i<N;++i)
    {
        int p,u,c;
        cin>>p>>u>>c;
        g[c].emplace_back(p,u);
    }
    vector<vector<pair<int,int>>>vp;
    for(int i=1;i<=N;++i)
    {
        if(!g[i].empty())vp.emplace_back(g[i]);
    }
    int C=vp.size();
    vector<vector<int>>dp(C+1,vector<int>(X+1,MAX_N));
    dp[0][0]=0;
    
    for(auto& it:vp)
    {
        vector<int>dp1(X+1,MAX_N);
        dp1[0]=0;
        for(auto& it1:it)
        {
            int p=it1.first,u=it1.second;
            if(p>X)continue;
            for(int i=X;i>=p;--i)
            {
                if(dp1[i-p]!=MAX_N)
                {
                    dp1[i]=max(dp1[i],dp1[i-p]+u);
                }
            }
        }
        vector<pair<int,int>>res;
        for(int i=1;i<=X;++i)
        {
            if(dp1[i]!=MAX_N)
            {
                res.emplace_back(i,dp1[i]);
            }
        }
        if(res.empty())continue;
        for(int t=C;t>=0;--t)
        {
            for(int x=0;x<=X;++x)
            {
                if(dp[t][x]!=MAX_N)
                {
                    for(auto& it1:res)
                    {
                        int F=it1.first,S=it1.second;
                        if(x+F>X)continue;
                        if(t+1>C)continue;
                        dp[t+1][x+F]=max<int>(dp[t+1][x+F],dp[t][x]+S);
                    }
                }
            }
        }
        // for dp
        // assert(!res.empty());
    }
    int ans=0;
    for(int t=0;t<=C;++t)
    {
        for(int x=0;x<=X;++x)
        {
            if(dp[t][x]!=MAX_N)
            {
                ans=max<int>(ans,dp[t][x]+t*K);
            }
        }
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}