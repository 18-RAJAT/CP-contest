#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1e9+7;
int Power(int b,int e,int mod)
{
    int ans=1;
    b%=mod;
    while(e>=1)
    {
        if(e&1)ans=(ans*b)%mod;
        b=(b*b)%mod;
        e>>=1;
    }
    return ans;
}
int Div(int a,int b,int mod)
{
    return a*Power(b,mod-2,mod)%mod;
}
void sol()
{
    int n,d;
    cin>>n>>d;
    int X=0;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        X^=x;
    }
    int A=d+1,B=d-1,D=2*d,ans;
    if(X!=0)ans=Div(A,D,MOD);
    else ans=Div(B,D,MOD);
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