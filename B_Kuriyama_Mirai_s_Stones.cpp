#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n+1],b[n+1];
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    int dp[n+1],ndp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;++i)
    {
        dp[i]=dp[i-1]+a[i];
    }
    ndp[0]=0;
    for(int i=1;i<=n;++i)
    {
        ndp[i]=ndp[i-1]+b[i];
    }
    int q;
    cin>>q;
    while(q--)
    {
        int type,l,r;
        cin>>type>>l>>r;
        cout<<(type==1?dp[r]-dp[l-1]:ndp[r]-ndp[l-1])<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}