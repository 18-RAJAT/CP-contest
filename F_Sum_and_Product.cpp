#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sol()
{
    ll n;
    cin>>n;
    map<ll,ll>mp;
    for(ll i=0;i<n;++i)
    {
        ll x;
        cin>>x;
        mp[x]++;
    }
    ll q;
    cin>>q;
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        if(x*x-4*y<0)
        {
            cout<<"0"<<" ";
            continue;
        }
        ll sq=(sqrt(x*x-4*y));
        ll ert=(x+sq)/2;
        ll ert1=(x-sq)/2;
        if(ert+ert1==x && ert*ert1==y && mp.count(ert) && mp.count(ert1))
        {
            if(ert==ert1)
            {
                cout<<mp[ert]*(mp[ert]-1)/2<<" ";
            }
            else
            {
                cout<<mp[ert]*mp[ert1]<<" ";
            }
        }
        else
        {
            cout<<"0"<<" ";
        }
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