#include<bits/stdc++.h>
using namespace std;
#define int long long
//USING ITERATIVE DP
void sol()
{
    int n,c;
    cin>>n>>c;
    int a[n+1],b[n+1];
    for(int i=1;i<=n-1;++i)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n-1;++i)
    {
        cin>>b[i];
    }
    int dp[n+1][2];//2 states: 0: stairs, 1: elevator
    memset(dp,1e9,sizeof(dp));
    dp[1][0]=0;
    dp[1][1]=1e9;
    for(int i=1;i<=n-1;++i)
    {
        dp[i+1][0]=min<int>(dp[i][0],dp[i][1])+a[i];
        //check if elevator is cheaper or stairs is cheaper to reach ith floor from i-1th floor and add the cost of elevator or stairs to reach ith floor from i-1th floor to the cost of reaching i-1th floor from 1st floor and store it in dp[i+1][0].
        // (dp[i][1]<dp[i][0])?dp[i+1][1]=min<int>(dp[i][0],dp[i][1])+b[i]:dp[i+1][1]=min<int>(dp[i][0],dp[i][1])+b[i]+c;

        //here we are checking if elevator is cheaper or stairs is cheaper to reach ith floor from i-1th floor and add the cost of elevator or stairs to reach ith floor from i-1th floor to the cost of reaching i-1th floor from 1st floor and store it in dp[i+1][1].
        dp[i+1][1]=min<int>(dp[i][0]+c,dp[i][1])+b[i];
    }
    for(int i=1;i<=n;++i)
    {
        cout<<min<int>(dp[i][0],dp[i][1])<<" ";
    }
    cout<<'\n';
}
signed main()
{
    sol();
    return 0;
}