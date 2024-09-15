#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int l,n,m;
    cin>>l>>n>>m;
    vector<int>a(l);
    for(int i=0;i<l;++i)
    {
        cin>>a[i];
    }
    vector<vector<int>>matrix(n,vector<int>(m));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>matrix[i][j];
        }
    }
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(l+1,0)));
    for(int i=n-1;i>=0;--i)
    {
        for(int j=m-1;j>=0;--j)
        {
            for(int k=l-1;k>=0;--k)
            {
                int leave=dp[i+1][j][k]|dp[i][j+1][k];
                int take=(matrix[i][j]==a[k])&(!dp[i+1][j+1][k+1]);
                dp[i][j][k]=leave|take;

            }
        }
    }
    cout<<(dp[0][0][0]?"T":"N")<<endl;
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