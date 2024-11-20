#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
void sol()
{
    int n,a,b;
    cin>>n>>a>>b;
    vector<int>ar(n+1),br(n+1);
    for(int i=1;i<=n;++i)ar[i]=gcd(i,a);
    for(int i=1;i<=n;++i)br[i]=gcd(i,b);
    int x=-1,y=-1;
    for(int i=n;i>0;--i)
    {
        if(ar[i]==1 && x==-1)x=i;
        if(br[i]==1 && y==-1)y=i;
        if(~x && ~y)break;
    }
    vector<vector<int>>dp(n-x+1,vector<int>(n-y+1,1e18));
    dp[0][0]=0;
    for(int i=x;i<=n;++i)
    {
        for(int j=y;j<=n;++j)
        {
            if(i>x)dp[i-x][j-y]=min(dp[i-x][j-y],dp[i-x-1][j-y]);
            if(j>y)dp[i-x][j-y]=min(dp[i-x][j-y],dp[i-x][j-y-1]);
            dp[i-x][j-y]+=ar[i]+br[j];
        }
    }
    int ans=dp[n-x][n-y];
    for(int i=1;i<=x;++i)ans+=ar[i]+1;
    for(int i=1;i<=y;++i)ans+=br[i]+1;
    ans-=4;
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}