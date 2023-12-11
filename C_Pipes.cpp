#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>dp[2];
    string s[2];
    for(int i=0;i<2;++i)
    {
        cin>>s[i];
        s[i]=' '+s[i];
        dp[i].resize(n+10);
    }
    dp[0][0]=1;//state
    for(int i=1;i<=n+1;++i)
    {
        if(s[0][i]<='2' && s[1][i]<='2')
        {
            dp[0][i]=dp[0][i-1],dp[1][i]=dp[1][i-1];
        }
        else if(s[0][i]<='2')
        {
            dp[0][i]=dp[0][i-1];
        }
        else if(s[1][i]<='2')
        {
            dp[1][i]=dp[1][i-1];
        }
        else
        {
            dp[0][i]=dp[1][i-1],dp[1][i]=dp[0][i-1];
        }
    }
    assert(~dp[0][n+1] && ~dp[1][n+1]);
    cout<<(dp[1][n+1]?"YES":"NO")<<endl;
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