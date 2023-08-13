#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        }
    int mx(-1);
    for(auto&it:a)
    {
        mx=max<int>(mx,it);
    }
    for(auto&it:a)
    {
        it=mx-it;
    }
    int tmp(a[0]);
    for(auto&it:a)
    {
        tmp=__gcd(tmp,it);
    }
    int ans(0);
    for(auto&it:a)
    {
        ans+=it/tmp;
    }
    cout<<ans<<" "<<tmp<<"\n";
    return 0;
}