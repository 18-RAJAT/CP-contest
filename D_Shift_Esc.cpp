#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    int memo[n][m];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)cin>>memo[i][j];
    }
    int dp[m][m];
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<m;++j)dp[i][j]=1e18;
    }
    for(int l=0;l<m;++l)
    {
        dp[0][l]=k*l+memo[0][l];
    }
    for(int j=1;j<m;++j)
    {
        for(int l=0;l<m;++l)dp[j][l]=dp[j-1][l]+memo[0][(j+l)%m];
    }
    for(int i=1;i<n;++i)
    {
        int ndp[m][m];
        for(int p=0;p<m;++p)
        {
            for(int q=0;q<m;++q)ndp[p][q]=1e18;
        }
        int arr[m];
        for(int j=0;j<m;++j)
        {
            arr[j]=1e18;
            for(int l=0;l<m;++l)arr[j]=min(arr[j],dp[j][l]);
        }
        for(int j=0;j<m;++j)
        {
            for(int l=0;l<m;++l)ndp[j][l]=min<int>(arr[j]+k*l+memo[i][(j+l)%m],(j>=1?ndp[j-1][l]+memo[i][(j+l)%m]:1e18));
        }
        for(int p=0;p<m;++p)
        {
            for(int q=0;q<m;++q)dp[p][q]=ndp[p][q];
        }
    }
    int ans=1e18;
    for(int l=0;l<m;++l)ans=min<int>(ans,dp[m-1][l]);
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