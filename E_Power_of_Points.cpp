#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sol()
{
    ll n;
    cin>>n;
    vector<ll>a(n),b(n);
    for(ll i=0;i<n;++i)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    // function<bool(ll,ll)>cmp=[&](ll x,ll y)->bool
    // {
    //     return a[x]<a[y];
    // };
    ll array[n];
    sort(b.begin(),b.end());
    ll sum=0;
    for(ll i=0;i<n;++i)
    {
        sum+=b[i];
        array[i]=sum;
    }
    for(ll i=0;i<n;++i)
    {
        ll lb=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        ll ans;
        if(lb==0)
        {
            ans=sum-a[i]*n;
        }
        else
        {
            ans=sum-array[lb-1]-(n-lb)*a[i];
            ans+=lb*a[i]-array[lb-1];
        }
        cout<<n+ans<<" ";
    }
    cout<<"\n";
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}