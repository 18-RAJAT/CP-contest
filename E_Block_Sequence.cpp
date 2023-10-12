#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int dp[n];
    memset(dp,-1,sizeof(dp));
    function<int(int)>deletions=[&](int beautiful)->int
    {
        if(beautiful==n)
        {
            return 0;
        }
        if(~dp[beautiful])
        {
            return dp[beautiful];
        }
        dp[beautiful]=INT_MAX;
        dp[beautiful]=min(dp[beautiful],1+deletions(beautiful+1));//deleting the current element
        if(a[beautiful]+beautiful<n)//this is to check if the next block is valid or not
        {
            int calc=beautiful+a[beautiful];//find the next block length
            dp[beautiful]=min(dp[beautiful],deletions(1+calc));//deleting the next block
        }
        return dp[beautiful];
    };
    cout<<deletions(0)<<endl;
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