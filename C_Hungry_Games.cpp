#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x;
    cin>>n>>x;
    vector<int>a(n),b(n+1);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        b[i+1]=a[i]+b[i];
    }
    vector<int>dp(n+5);
    for(int i=n;i>=0;--i)
    {
        int l_side=i,r_side=n;
        for(;l_side<r_side;)
        {
            int mid=(l_side+r_side)/2;
            (b[mid+1]-b[i]<=x)?l_side=mid+1:r_side=mid;
        }
        dp[i]=l_side-i+dp[r_side+1];
    }
    cout<<accumulate(dp.begin(),dp.end(),0LL)<<endl;
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