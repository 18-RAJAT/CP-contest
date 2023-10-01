#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[5005][5005];
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n+1);

    vector<int>cnt(n+20);

    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        cnt[min(n+2,a[i])]++;
    }
    int mex=0;
    while(cnt[mex]>0)
    {
        mex++;
    }
    if(mex==0)
    {
        cout<<0<<endl;
        return;
    }
    for(int i=0;i<=mex;++i)
    {
        dp[0][i]=(cnt[0]-1)*i;//cnt[0]-1 because we are not counting the first element in the array
    }
    for(int i=1;i<mex;++i)
    {
        for(int j=1;j<=mex;++j)
        {
            dp[i][j]=min(dp[i-1][j],dp[i-1][i]+(cnt[i]-1)*j+i);//for this transition we are taking i as the new mex and j as the old mex
        }
    }
    cout<<dp[mex-1][mex]<<endl;
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