#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e4+5;
int dp[105][N];
void sol()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)cin>>b[i];
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<N;++j)dp[i][j]=-1e18;
    }
    dp[0][0]=0;
    for(int i=0;i<n;++i)
    {
        for(int j=n;j>=1;--j)
        {
            for(int k=N-1;k>=a[i];--k)
            {
                int& ret=dp[j][k];
                ret=max(ret,dp[j-1][k-a[i]]+b[i]);
            }
        }
    }
    int sum=0;
    for(int i=0;i<n;++i)sum+=a[i];
    for(int i=0;i<=n;++i)
    {
        for(int j=N-1;j>=0;--j)
        {
            if(sum<=dp[i][j])
            {
                cout<<i<<" "<<sum-j;
                return;
            }
        }
    }
}
signed main()
{
    sol();
    return 0;
}