#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int m,n;
    cin>>m>>n;
    vector<int>s(m),l(m);
    for(int i=0;i<m;++i)cin>>s[i];
    for(int i=0;i<m;++i)cin>>l[i];
    vector<vector<int>>dp(m,vector<int>(n+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<m;++j)
        {
            for(int k=0;k<m;++k)
            {
                dp[j][i]+=dp[k][i-1]*(s[j]*l[k]+s[k]*l[j]+s[j]*s[k])%1000000007;
            }
        }
    }
    int ans=0;
    for(int i=0;i<m;++i)ans+=dp[i][n];
    cout<<ans%1000000007;
}
signed main()
{
    sol();
    return 0;
}