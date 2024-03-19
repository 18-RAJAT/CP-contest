#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    int ans=0,sum=0,nums=1e18;
    for(int i=n-1;i>=m;--i)
    {
        ans+=min(a[i],b[i]);
    }
    for(int i=m-1;i>=0;--i)
    {
        nums=min(nums,a[i]+sum);
        sum+=b[i];
    }
    ans+=nums;
    cout<<ans<<endl;
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