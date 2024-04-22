#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int i=0;i<31;++i)
    {
        if((ans|(1LL<<i))<=k)
        {
            ans|=(1LL<<i);
        }
        else break;
    }
    if(n==1)
    {
        cout<<k<<" ";cout<<endl;
    }
    else
    {
        cout<<ans<<" "<<k-ans<<" ";
        for(int i=0;i<n-2;++i)
        {
            cout<<0<<" ";
        }
        cout<<endl;
    }
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}