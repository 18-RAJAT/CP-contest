#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[2005][2005],cache[2005][2005];
int n;
void sol()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>dp[i][0];
        cache[dp[i][0]][0]++;
    }
    for(int j=1;j<=n;++j)
    {
        for(int i=1;i<=n;++i)
        {
            dp[i][j]=cache[dp[i][j-1]][j-1];
            cache[dp[i][j]][j]++;
        }
    }
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	sol();
        int q;
        cin>>q;
        while(q--)
        {
            int x,k;
            cin>>x>>k;
            int ans=0;
            // for(int i=0;i<=10;++i)
            // {
            //     if(k&(1<<i))
            //     {
            //         ans+=cache[x][i];
            //         x=dp[x][i];
            //     }
            // }
            // cout<<ans<<endl;
            k=min(k,n);
            cout<<dp[x][k]<<endl;
        }
        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=n;++j)
            {
                dp[i][j]=0;
                cache[i][j]=0;
            }
        }
        assert(dp[0][0]==0 && cache[0][0]==0);
    }
    return 0;
}