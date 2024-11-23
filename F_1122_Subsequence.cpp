#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=20,INF=1e9;
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    vector<vector<int>>pos(N,vector<int>());
    for(int i=0;i<n;++i)
    {
        if(a[i]>=1 && a[i]<=N)pos[a[i]-1].push_back(i+1);
    }
    int M=1<<N;
    vector<int>dp(M,INF);
    dp[0]=0;
    //j is my mask to be updated
    for(int j=0;j<M;++j)
    {
        if(dp[j]==INF)continue;
        for(int i=0;i<N;++i)
        {
            int shift=1<<i;
            if((j&shift)!=0)continue;
            if(pos[i].size()<=1)continue;
            int Ub=upper_bound(pos[i].begin(),pos[i].end(),dp[j])-pos[i].begin();
            if(Ub+1>=pos[i].size())continue;
            int prev=pos[i][Ub],nxt=pos[i][Ub+1];
            int update_mask=j|shift;
            if(nxt<dp[update_mask])dp[update_mask]=nxt;
        }
    }
    int ans=0;
    for(int j=0;j<M;++j)
    {
        if(dp[j]!=INF)ans=max<int>(ans,2*__builtin_popcountll(j));
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}