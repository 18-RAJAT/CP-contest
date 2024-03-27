#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    vector<vector<int>>dp(n,vector<int>(n+1,0));
    for(int i=n-1;~i;--i)
    {
        for(int j=n-1;j>i;--j)
        {
            if(s[i]==s[j] || s[i]=='?' || s[j]=='?')
            {
                dp[i][j]=min(j-i,1+dp[i+1][j+1]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(dp[i][j]==j-i)
            {
                ans=max(ans,2*dp[i][j]);
            }
        }
    }
    cout<<ans<<endl;
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