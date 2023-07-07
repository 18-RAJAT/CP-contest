#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sol()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll ans=0,curr=-1;
    for(ll i=0;i<n;i++)
    {
        if(curr==-1)
        {
            curr=arr[i];
        }
        curr&=arr[i];
        if(curr==0)
        {
            ans++;
            curr=-1;
        }
    }
    cout<<((ans==0)?1:ans)<<"\n";
}
int main()
{
	int t;
	cin>>t;
	while(t-->0)
	{
        sol();
	}
	return 0;
}