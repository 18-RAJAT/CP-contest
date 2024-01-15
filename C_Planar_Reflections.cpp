#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[2005][2005][2];
int n,k;
int recur(int i,int j,int memo)
{
    if(j<1)
    {
        return 0;
    }
    if(i>n||i<=0)
    {
        return 1;
    }
    int &ans=dp[i][j][memo];
    if(~ans)
    {
        return ans;
    }
    if(memo)
    {
        return ans=(recur(i+1,j,memo)+recur(i-1,j-1,0))%1000000007;
    }
    else
    {
        return ans=(recur(i-1,j,memo)+recur(i+1,j-1,1))%1000000007;
    }
}
void sol()
{
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    cout<<recur(1,k,1)<<endl;
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