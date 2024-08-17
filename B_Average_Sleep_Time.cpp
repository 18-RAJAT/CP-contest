#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    double sum=0,ans=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<k;++i)
    {
        sum+=a[i];
    }
    ans=sum;
    for(int i=k;i<n;++i)
    {
        sum+=a[i]-a[i-k];
        ans+=sum;
    }
    cout<<fixed<<setprecision(10)<<ans/(n-k+1);
}
signed main()
{
    sol();
    return 0;
}