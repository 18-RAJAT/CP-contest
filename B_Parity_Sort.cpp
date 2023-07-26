#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sol()
{
    ll n;
    cin>>n;
    vector<ll>arr(n);
    for(int i=0;i<n;i+=1)
    {
        cin>>arr[i];
    }
    vector<ll>odd,even;
    for(int i=0;i<n;++i)
    {
        if(arr[i]&1)
        {
            odd.push_back(arr[i]);
        }
        else
        {
            even.push_back(arr[i]);
        }
    }
    int o=0,e=0;
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());
    for(int i=0;i<n;++i)
    {
        if(arr[i]&1)
        {
            arr[i]=odd[o];
            o++;
        }
        else
        {
            arr[i]=even[e];
            e++;
        }
    }
    bool flag=true;
    for(int i=0;i<n-1;++i)
    {
        if(arr[i]>arr[i+1])
        {
            flag=false;
            break;
        }
    }

    if(flag)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
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