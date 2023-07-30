#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++)
    {
    	cin>>a[i];
    }
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
    	if(a[i]==0)
    	{
    		ans=0;
    		break;
    	}
    	else
    	{
    		ans+=a[i];
    		i+=a[i]-1;
    	}
    }
    cout<<ans-1<<"\n";
}