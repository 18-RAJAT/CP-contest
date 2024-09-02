#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=1000000007;
int mul(int a,int b){return (a%MOD*b%MOD)%MOD;}
int exp(int base,int e)
{
    int ans=1;
    while(e)
    {
        if(e&1)ans=mul(ans,base);
        base=mul(base,base),e>>=1;
    }
    return ans;
}
int binary_exp(int a,int b)
{
    if(b==0)return 1;
    int ans=binary_exp(a,b/2);
    ans=mul(ans,ans);
    if(b&1)return mul(ans,a);
    return ans;
}
int extended_gcd(int a,int b,int& x,int& y)
{
    if(a==0)
    {
        x=0,y=1;
        return b;
    }
    int x1,y1;
    int Gcd=extended_gcd(b%a,a,x1,y1);
    x=y1-(b/a)*x1,y=x1;
    return Gcd;
}
int inv(int a)
{
    // int x,y;
    // int Gcd=extended_gcd(a,mod,x,y);
    // if(Gcd!=1)throw invalid_argument("In");
    // return (x%mod+mod)%mod;
    return binary_exp(a,MOD-2);
}
void sol()
{
    int n;
    cin>>n;
    int sum=0,ans=0;
    vector<int>a(n);
    for(auto& it:a)
    {
        cin>>it;sum+=it;
    }
    // for(auto& it:a)
    // {
    //     ans=(ans+mul(sum-it,it))%MOD;
    // }
    int res=0;
    for(int i=0;i<n;++i)
    {
        res=(res+mul(sum-a[i],a[i]))%MOD;
    }
    int calc=mul(res,inv(mul(n,n-1)));
    cout<<calc<<endl;
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