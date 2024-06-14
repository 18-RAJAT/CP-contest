#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T>int bin_pow(T value,int n,int mod=1000000007){int ans=1,pos=value;for(;n;){if(n&1)ans=(ans*pos)%mod;ans%mod;pos*=pos,pos%=mod;n>>=1;}return ans;}
void sol()
{
    int l,r,k;
    cin>>l>>r>>k;
    int mod=1000000007;
    int base=9/k+1;
    cout<<((bin_pow(base,r,mod)-bin_pow(base,l,mod)%mod)+mod)%mod<<endl;
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