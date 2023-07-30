#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sol()
{
    ll n;
    cin>>n;
    ll ans=1;
    for(ll i=1;i<=100001;++i)
    {
        if(n%i!=0)
        {
            ans=i;
            break;
        }
    }
    cout<<ans-1<<"\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
}