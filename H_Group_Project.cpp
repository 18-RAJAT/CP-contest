#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    auto pos=[&](string s)->int
    {
        return stoll(s.substr(7,3));
    };
    function<int(int,int,int)>power_mod=[&](int x,int y,int p)->int
    {
        int res=1;
        x=x%p;
        if(x==0)
        return 0;
        while(y>0)
        {
            if(y&1)
            res=(res*x)%p;
            y=y>>1;
            x=(x*x)%p;
        }
        return res;
    };
    int x=pos(a);
    int y=pos(b);
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        if((x-1)/i==(y-1)/i)
        ans++;
    }
    cout<<(ans*power_mod(n,998244351,998244353))%998244353<<"\n";
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