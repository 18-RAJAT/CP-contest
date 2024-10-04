// Problem: D. Make The Fence Great Again
// Contest: Codeforces - Educational Codeforces Round 73 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1221/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Author: Rajat.18
// Created: Fri 4/10/2024 19:21:47 GMT+5:30,India

#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;++i)
    {
    	cin>>a[i]>>b[i];
    }
    vector<vector<int>>dp(n,vector<int>(3,1e18));
    for(int i=0;i<3;++i)
    {
    	dp[0][i]=i*b[0];
    }
    for(int i=1;i<n;++i)
    {
    	for(int j=0;j<3;++j)
    	{
    		for(int k=0;k<3;++k)
    		{
    			if(a[i]+j!=a[i-1]+k)
    			{
    				dp[i][j]=min(dp[i][j],dp[i-1][k]+b[i]*j);
    			}
    		}
    	}
    }
    cout<<min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2])<<endl;
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