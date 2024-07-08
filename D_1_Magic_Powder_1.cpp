#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int a[n],b[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    int l=0,r=1e10;
    while(r-l>=2)
    {
        int mid=l+r>>1;
        double ans=0;
        for(int i=0;i<n;++i)
        {
            ans+=max(0LL,a[i]*mid-b[i]);
        }
        (ans<=k)?l=mid:r=mid;
    }
    cout<<l;
}
signed main()
{
    sol();
    return 0;
}