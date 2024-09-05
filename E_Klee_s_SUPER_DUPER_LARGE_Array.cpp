#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    auto calc=[&](int x)
    {
        int ans=0;
        ans+=(2*k+x-1)*x>>1;
        ans-=(2*k+x+n-1)*(n-x)>>1;
        return abs(ans);
    };
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r)>>1;
        (calc(mid)>calc(mid+1))?l=mid+1:r=mid;
    }
    cout<<calc(l)<<endl;
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