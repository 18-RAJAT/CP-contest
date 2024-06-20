#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,p;
    cin>>n>>p;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int ans=1;
    if(p<n){cout<<0;return;}
    auto recur=[&](int a,int b)
    {
        return (a*b*1LL)%p;
    };
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            ans=recur(ans,abs(a[i]-a[j])%p);
        }
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}