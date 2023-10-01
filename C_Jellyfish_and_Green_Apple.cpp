#include<bits/stdc++.h>
using namespace std;
#define int long long
int recur(int a,int b)
{
    b%=a;
    if(b==0)
    {
        return 0;
    }
    return b+recur(a,2*b);
}
int lowBt(int x)
{
    return x&(-x);
}
int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
void sol()
{
    int n,m;
    cin>>n>>m;
    if(n%m==0)
    {
        cout<<0<<endl;
        return;
    }
    n%=m;
    int G=gcd(n,m);
    int ert=m/G,ert1=n/G;
    if(lowBt(ert)!=ert)
    {
        cout<<-1<<endl;
        return;
    }
    int ans=0;
    for(int i=0;i<31;++i)
    {
        if((1<<i)&ert1)
        {
            int jo=ert/gcd(ert,(1<<i));
            // ans+=recur(m,n);
            ans+=m/jo*(jo-1);
            // break;
        }
    }
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