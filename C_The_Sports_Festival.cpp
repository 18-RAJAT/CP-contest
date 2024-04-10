#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    array<int,2005>dp[n];
    for(int i=0;i<n;++i)
    {
        dp[i][i]=0;
    }
    for(int i=1;i<n;++i)
    {
        for(int j=0;j+i<n;++j)
        {
            dp[j][j+i]=a[j+i]-a[j]+min(dp[j+1][j+i],dp[j][j+i-1]);
        }
    }
    cout<<dp[0][n-1];
}
signed main()
{
    sol();
    return 0;
}