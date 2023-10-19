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
    sort(a,a+n);
    int dp[n],ndp[n];
    int i=0,j=n/2,k=n-1;
    for(int l=0;l<n;++l)
    {
        if(l&1)
        {
            dp[l]=a[i];
            ndp[l]=a[i++];
        }
        else
        {
            dp[l]=a[j++];
            ndp[l]=a[k--];
        }
    }
    int c1=0,c2=0;
    for(int i=1;i<n-1;++i)
    {
        if(dp[i]<dp[i-1] && dp[i]<dp[i+1])
        {
            c1++;
        }
        if(ndp[i]<ndp[i-1] && ndp[i]<ndp[i+1])
        {
            c2++;
        }
    }
    cout<<max(c1,c2)<<"\n";
    if(c1>c2)
    {
        for(int i=0;i<n;++i)
        {
            cout<<dp[i]<<" ";
        }
    }
    else
    {
        for(int i=0;i<n;++i)
        {
            cout<<ndp[i]<<" ";
        }
    }
}
signed main()
{
    sol();
    return 0;
}