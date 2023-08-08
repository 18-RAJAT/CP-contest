#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sol()
{
    ll n;
    cin>>n;
    vector<ll>a(n*(n-1)/2);
    for(ll i=0;i<n*(n-1)/2;++i)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    ll idx=0;
    ll cnt=n-1;
    for(ll i=0;i<n-1;++i)
    {
        ll mn=INT_MAX;
        for(ll j=0;j<cnt;++j)
        {
            mn=min<ll>(mn,a[idx++]);
        }
        cnt--;
        cout<<mn<<" ";
    }
    cout<<1000000000<<" ";
    cout<<"\n";
}
signed main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}