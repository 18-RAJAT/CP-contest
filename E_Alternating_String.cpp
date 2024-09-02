#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
int dp[N][26][2];
void sol()
{
    int n;
    cin>>n;
    char c;
    int ans;
    for(int i=1;i<=n;++i)
    {
        cin>>c;
        ans=c-'a';
        for(int j=0;j<26;++j)
        {
            for(int k=0;k<2;++k)
            {
                dp[i][j][k]=dp[i-1][j][k]+(ans==j && i%2==k);
            }
        }
    }
    if(n%2==0)
    {
        int x=0,y=0;
        for(int i=0;i<26;++i)
        {
            x=max(x,dp[n][i][0]);
            y=max(y,dp[n][i][1]);
        }
        cout<<n-x-y<<endl;
        return;
    }
    ans=n;
    for(int i=1;i<=n;++i)
    {
        int x=0,y=0;
        for(int j=0;j<26;++j)
        {
            x=max(dp[i-1][j][0]+dp[n][j][1]-dp[i][j][1],x);
            y=max(dp[i-1][j][1]+dp[n][j][0]-dp[i][j][0],y);
        }
        ans=min(n-x-y,ans);
    }
    cout<<(ans<n?ans:n)<<endl;
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