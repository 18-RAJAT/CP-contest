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
    }
    for(ll i=0;i<n;++i)
    {
        cin>>b[i];
    }
    vector<pair<ll,ll>>ans;
    ll mx=INT_MIN;
    for(ll i=0;i<n;++i)
    {
        ans.push_back(make_pair(a[i]-b[i],i+1));
        mx=max<int>(mx,a[i]-b[i]);
    }
    vector<ll>find;
    for(ll i=0;i<n;++i)
    {
        if(ans[i].first==mx)
        {
            find.push_back(ans[i].second);
        }
        // else
        // {
        //     if(ans[i].first>0)
        //     {
        //         find.push_back(ans[i].second);
        //     }
        // }
    }
    cout<<find.size()<<"\n";
    for(auto& it:find)
    {
        cout<<it<<" ";
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