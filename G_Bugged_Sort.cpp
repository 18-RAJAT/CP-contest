#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;cin>>n;
    vector<array<int,3>>a(n);
    for(int i=0;i<n;++i)cin>>a[i][1];
    for(int i=0;i<n;++i)
    {
        cin>>a[i][2];
        a[i][0]=min(a[i][1],a[i][2]);
    }
    sort(a.begin(),a.end());
    int dp[n][2][2]={0};
    dp[0][0][0]=dp[0][1][1]=1;
    vector<array<array<int,2>,2>>b(n);
    for(int i=0;i<n;++i)
    {
        b[i][0]={a[i][1],a[i][2]},b[i][1]={a[i][2],a[i][1]};
    }
    for(int i=1;i<n;++i)
    {
        for(int j=0;j<2;++j)
        {
            for(int k=0;k<2;++k)
            {
                for(int l=0;l<2;++l)
                {
                    if(b[i-1][k][0]<b[i][l][0] && b[i-1][k][1]<b[i][l][1])
                    if(dp[i-1][k][j])dp[i][l][j^l]=1;
                }
            }
        }
    }
    cout<<(dp[n-1][0][0] || dp[n-1][1][0]?"YES":"NO")<<endl;
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