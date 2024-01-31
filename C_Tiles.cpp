#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    function<int(int,int)>power=[&](int a,int b)->int
    {
        int ans=1;
        while(b>0)
        {
            if(b&1)
            {
                ans=(1ll*ans*a)%998244353;
            }
            a=(1ll*a*a)%998244353;
            b>>=1;
        }
        return ans;
    };
    cout<<power(2,n+m);
}
signed main()
{
    sol();
    return 0;
}