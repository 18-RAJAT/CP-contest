#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1000000007;
int mod_exp(int base,int exp,int m)
{
    int ans=1;
    while(exp>0)
    {
        if(exp&1)ans=(ans*base)%m;
        base=(base*base)%m,exp/=2;
    }
    return ans;
}
int Combination(int n,int r)
{
    int ans=1;
    if(n<r)return 0;
    r=min(n-r,r);
    for(int i=0;i<r;++i)
    {
        ans=(ans*(n-i))%MOD;
        ans=(ans*mod_exp(i+1,MOD-2,MOD))%MOD;
    }
    return ans;
}
void sol()
{
    int n,k;
    cin>>n>>k;
    int One=0,Zero=0,ans=0;
    while(n--)
    {
        int t;
        cin>>t;
        (t)?One++:Zero++;
    }
    int Expected=k+1;
    for(int i=Expected/2;i<Expected;++i)
    {
        if(One<i)break;
        if(Zero<(k-i))continue;
        ans=(ans+(Combination(One,i)*max(Combination(Zero,k-i),(int)1))%MOD);
    }
    cout<<ans%MOD<<endl;
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