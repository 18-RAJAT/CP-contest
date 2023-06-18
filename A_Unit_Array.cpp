#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sol()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    ll pos=0,neg=0;
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
        if(arr[i]==1)
        {
            pos++;
        }
        else
        {
            neg++;
        }
    }
    ll ctr=0;
    if(neg%2==1)
    {
        neg--;ctr++;pos++;
    }
    while(pos<neg)
    {
        neg--;ctr++;pos++;
    }
    if(neg%2==1)
    {
        neg--;ctr++;pos++;
    }
    cout<<ctr<<"\n";
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