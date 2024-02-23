#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int ans=0;
    ans=max(min(a,b)*min(c,d),min(a,c)*min(b,d));
    ans=max(ans,min(a,d)*min(b,c));
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