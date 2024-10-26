#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<m;++i)cin>>b[i];
    vector<int>cost(n+1,0);
    for(int i=0;i<n;++i)cost[i+1]=cost[i]+a[i];
    int end=0;
    for(int i=1;i<=n;++i)
    {
        if(cost[i]-cost[i-1]<a[i-1])
        {
            int ok=0;
            for(int j=0;j<m;++j)
            {
                if(a[i-1]<=b[j])
                {
                    ok=1;
                    break;
                }
            }
            if(!ok)
            {
                end=1;
                break;
            }
        }
    }
    if(end)
    {
        cout<<-1<<endl;
        return;
    }
    vector<int>dp(n+1,1e18);
    dp[0]=0;
    for(int k=1;k<=m;++k)
    {
        int temp=b[k-1],maxi=0;
        for(int i=0;i<=n;++i)
        {
            if(dp[i]==1e18)continue;
            maxi=max(maxi,i+1);
            for(;maxi<=n && cost[maxi]-cost[i]<=temp;++maxi);
            maxi--;
            if(i+1<=maxi)
            {
                dp[maxi]=min(dp[maxi],dp[i]+m-k);
            }
        }
    }
    cout<<((dp[n]==1e18)?-1:dp[n])<<endl;
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