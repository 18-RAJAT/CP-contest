#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    array<int,13>dp;
    dp[0]=10;
    dp[1]=10;
    dp[2]=8;
    dp[3]=9;
    dp[4]=8;
    dp[5]=7;
    dp[6]=7;
    dp[7]=7;
    dp[8]=7;
    dp[9]=0;
    dp[10]=9;
    dp[11]=6;
    dp[12]=8;
    cout<<dp[n]<<endl;
}
signed main()
{
    sol();
    return 0;
}