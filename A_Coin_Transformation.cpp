#include<bits/stdc++.h>
using namespace std;
#define int long long
unordered_map<int,int> dp;
int f(int n)
{
    if(n<=3)return 1;
    if(dp.find(n)!=dp.end())return dp[n];
    return dp[n]=2*f(n/4);
}
void sol()
{
    int n;
    cin>>n;
    cout<<f(n)<<endl;
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