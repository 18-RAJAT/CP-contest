#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=2000000005;

void solve()
{
    int n,m;
    cin>>n>>m;
    map<int,string>a;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    map<char,int>Lazy;
    Lazy['n']=0;
    Lazy['a']=1;
    Lazy['r']=2;
    Lazy['e']=3;
    Lazy['k']=4;

    vector<vector<int>>dp(n+1,vector<int>(5,-inf));
    dp[0][0]=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<5;++j)
        {
            dp[i+1][j]=max(dp[i][j],dp[i+1][j]);
            int take=j,temp=dp[i][j],ans=0,Nark=0;
            for(auto& it:a[i])
            {
                if(Lazy.count(it) && Lazy[it]==take)
                {
                    take++;
                }
                else
                {
                    if(Lazy.count(it))
                    {
                        ans++;
                    }
                }
                if(take==5)
                {
                    temp+=5,take=0;
                    Nark=1;
                }
            }
            dp[i+1][take]=max({dp[i][take],temp-ans,dp[i+1][take]});
        }
    }
    int ans=-inf;
    for(int i=0;i<5;++i)
    {
        ans=max(ans,dp[n][i]-i);
    }
    cout<<ans<<endl;
}

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}