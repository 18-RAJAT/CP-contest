#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[105][105][15][15];
void sol()
{
    int n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;
    for(int i=0;i<=k1;++i)
    {
        for(int j=0;j<=k2;++j)
        {
            fill(dp[n1][n2][i]+j,dp[n1][n2][i]+k2+1,1);
        }
    }
    for(int i=n1;i>=0;--i)
    {
        for(int j=n2;j>=0;--j)
        {
            if(i==n1 && j==n2)
            {
                continue;
            }
            for(int m=0;m<=k1;++m)
            {
                for(int h=0;h<=k2;++h)
                {
                    int res=0;
                    if(i<n1 && m-1>=0)
                    {
                        res+=dp[i+1][j][m-1][k2];
                    }
                    if(j<n2 && h-1>=0)
                    {
                        res+=dp[i][j+1][k1][h-1];
                    }
                    dp[i][j][m][h]=res%100000000;
                }
            }
        }
    }
    cout<<dp[0][0][k1][k2]%100000000<<endl;
}
signed main()
{
    sol();
    return 0;
}