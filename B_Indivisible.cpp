#include<bits/stdc++.h>
using namespace std;
#define ll long long

void sol()
{
    ll n;
    cin>>n;

    if(n==1)
    {
        cout<<"1"<<"\n";
        return;
    }
    if(n%2)
    {
        cout<<"-1"<<"\n";
        return;
    }
    ll dist=2,ans=1;
    for(ll i=0;i<n;++i)
    {
        if(i%2)
        {
            cout<<ans<<" ";
            ans+=2;
        }
        else
        {
            cout<<dist<<" ";
            dist+=2;
        }
    }
    cout<<"\n";
}
int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        sol();
    }
    return 0;
}