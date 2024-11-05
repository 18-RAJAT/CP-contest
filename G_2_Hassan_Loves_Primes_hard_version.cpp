#include<bits/stdc++.h>
using namespace std;
#define int long long
int Mul(int a,int b,int mod)
{
    int res=0;
    a%=mod;
    while(b)
    {
        if(b&1)res=(res+a)%mod;
        a=(a*2)%mod;
        b>>=1;
    }
    return res;
}
int MulPower(int a,int d,int n)
{
    int res=1;
    a%=n;
    while(d)
    {
        if(d&1)res=Mul(res,a,n);
        a=Mul(a,a,n);
        d>>=1;
    }
    return res;
}
bool Primes(int n)
{
    if(n<2)return false;
    for(auto& it:{2,7,61})
    {
        if(n%it==0)return n==it;
    }
    int d=n-1,count=0;
    while(d%2==0)
    {
        d/=2;
        count++;
    }
    for(auto& it:{2,7,61})
    {
        int x=MulPower(it,d,n);
        if(x==1 || x==n-1)continue;
        bool ok=false;
        for(int i=1;i<count;++i)
        {
            x=Mul(x,x,n);
            if(x==n-1)
            {
                ok=true;
                break;
            }
        }
        if(!ok)return false;
    }
    return true;
}
void sol()
{
    int x;
    cin>>x;
    if(Primes(x))cout<<1<<endl;
    else if(~x&1)cout<<2<<endl;
    else if(Primes(x-2))cout<<2<<endl;
    else cout<<3<<endl;
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