#include<bits/stdc++.h>
using namespace std;
#define ll long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>s(n,0),e(n,0);
    int arr[n];
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    int f=arr[0],l=arr[n-1];
    bool ok=false;
    s[0]=1,e[n-1]=1;
    for(int i=1;i<n;++i)
    {
        if(arr[i]==f)
        {
            s[i]=s[i-1]+1;
        }
        else
        {
            s[i]=s[i-1];
        }
    }
    for(int i=n-2;i>=0;--i)
    {
        if(arr[i]==l)
        {
            e[i]=e[i+1]+1;
        }
        else
        {
            e[i]=e[i+1];
        }
    }
    // for(int i=0;i<n;++i)
    // {
    //     cout<<s[i]<<" ";
    // }
    for(int i=0;i<n;++i)
    {
        if(k<=s[i] && k<=e[i])
        {
            ok=true;
            break;
        }
    }
    cout<<((f==l && k<=s[n-1]) || ok?"YES\n":"NO\n");
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