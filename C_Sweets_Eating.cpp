#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<int>dp(n);
    for(int i=0;i<m;++i)
    {
        dp[i]=a[i];
    }
    for(int i=m;i<n;++i)
    {
        dp[i]=dp[i-m]+a[i];//use the previous m elements to get the current element
    }
    vector<int>cache(n);
    // int& cache=dp[0];
    // assert(~cache);
    cache[0]=dp[0];
    for(int i=1;i<m;++i)
    {
        cache[i]=cache[i-1]+a[i];
    }
    for(int i=m;i<n;++i)
    {
        // dp[i]=dp[i]+dp[i-m];
        cache[i]=cache[i-1]+a[i]+dp[i-m];//it is not dp[i-m] because we have to add all the elements from 0 to i-m
    }
    for(int i=0;i<n;++i)
    {
        cout<<cache[i]<<" ";
    }
}
signed main()
{
    sol();
    return 0;
}