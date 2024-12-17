#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[25],memo[25][25];
int dp[(1<<20)+5][25];
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<k;++i)
    {
        int x,y,z;
        cin>>x>>y>>z;
        x--,y--;
        memo[x][y]=z;
    }
    for(int i=0;i<(1<<n);++i)
    {
        for(int j=0;j<n;++j)
        {
            if(i&(1<<j))
            {
                if(i==(1<<j))dp[i][j]=a[j];
                for(int k=0;k<n;++k)
                {
                    if(i&(1<<k))continue;
                    dp[i|(1<<k)][k]=max(dp[i|(1<<k)][k],a[k]+memo[j][k]+dp[i][j]);
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<(1<<n);++i)
    {
        int val=__builtin_popcount(i);
        if(m<val)continue;
        for(int j=0;j<n;++j)
        {
            ans=max(dp[i][j],ans);
        }
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}