#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=20;
int dp[5000][5000],cube[20][20][20];
void sol()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            for(int k=0;k<n;++k)
            {
                cin>>cube[i][j][k];
            }
        }
    }
    //percompute
    for(int i=0;i<(1<<n);++i)
    {
        for(int j=0;j<(1<<n);++j)
        {
            dp[i][j]=1e18;
        }
    }
    dp[0][0]=0;
    for(int i=0;i<n;++i)
    {
        for(int p=0;p<(1<<n);++p)
        {
            if(__builtin_popcount(p)!=i)continue;
            for(int q=0;q<(1<<n);++q)
            {
                if(__builtin_popcount(q)!=i)continue;
                for(int j=0;j<n;++j)
                {
                    if((p>>j)&1)continue;
                    for(int k=0;k<n;++k)
                    {
                        if((q>>k)&1)continue;
                        dp[p|(1<<j)][q|(1<<k)]=min<int>(dp[p|(1<<j)][q|(1<<k)],dp[p][q]+cube[i][j][k]);
                    }
                }
            }
        }
    }
    int ls=(1<<n);
    cout<<dp[ls-1][ls-1];
}
signed main()
{
    sol();
    return 0;
}