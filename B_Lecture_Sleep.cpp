#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>v(n),a(n);
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i])
        {
            ans+=v[i];
        }
    }
    int current=0,present=0;
    for(int i=k-1;~i;--i)
    {
        if(a[i]==0)
        {
            present+=v[i];
        }
    }
    current=max(current,present);
    for(int i=k;i<n;++i)
    {
        if(a[i]==0 && i-k>=0)
        {
            present+=v[i];
        }
        if(a[i-k]==0 && i-k>=0)
        {
            present-=v[i-k];
        }
        current=max(current,present);
    }
    cout<<ans+current<<endl;
}
signed main()
{
    sol();
    return 0;
}