#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,m;
    cin>>a>>m;
    m/=__gcd(a,m);
    int ans=m;
    for(int i=2;i*i<=m;++i)
    {
        if(m%i==0)
        {
            ans-=ans/i;
            while(m%i==0)m/=i;
        }
    }
    if(m>=2)ans-=ans/m;
    cout<<ans<<endl;
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