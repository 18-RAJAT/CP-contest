#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
int power(int a,int b,int mod)
{
    int ans=1;
    a%=mod;
    while(b>0)
    {
        if(b&1)ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    int z=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]!=0)z++;
    }
    int ans=(n*power(2,n-1,MOD))%MOD,tmp=z;
    int res=(tmp*power(2,tmp-1,MOD))%MOD;
    ans=(ans-res+MOD)%MOD;
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