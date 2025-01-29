#include<bits/stdc++.h>
using namespace std;
#define int long long

//Rajat joshi template
const int mod=1000000007;
int Exp(int a,int b)
{
    int res=1%mod;
    a%=mod;
    while(b)
    {
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int Check(int a,int b,int k)
{
    if(a && b)return a==b;
    if(a || b)return 1;
    return k;
}
void sol()
{
    int n,k;
    cin>>n>>k;
    int a[n+1],z=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        if(!a[i])z++;
    }
    int m=Exp(k,z),p=1,x=1,c1=0,c2=0;
    for(int i=1,j=n;i<j;++i,--j)
    {
        if(a[i] && a[j])
        {
            if(a[i]!=a[j])
            {
                p=0;c1=1;
                break;
            }
        }
        else if(!a[i] && !a[j])p=p*k%mod;
    }
    if(!c1 && n%2 && !a[(n+1)/2])p=p*k%mod;
    for(int i=1,j=n;i<j;++i,--j)
    {
        int l=Check(a[i],a[j],k);
        if(!l){x=0;c2=1;break;}
        x=x*l%mod*l%mod;
    }
    if(!c2 && n%2 && !a[(n+1)/2])x=x*(a[(n+1)/2]?1:k)%mod;
    int d=(x+2*mod-p)%mod,inv2=(mod+1)/2;
    cout<<(m+2*mod-d*inv2%mod)%mod<<endl;
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