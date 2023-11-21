#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005];
int cnt;
int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a/gcd(a,b)*b/gcd(a,b);
}
void divisors(int n)
{
    for(int i=1;i*i<=n;++i)
    {
        if(n%i==0)
        {
            a[cnt]=i;
            cnt++;
            a[cnt]=n/i;
            cnt++;
        }
    }
}
void sol()
{
    int n;
    cin>>n;
    divisors(n);
    int a(1),b(n);
    int ans=1e18;
    for(int i=0;i<cnt;++i)
    {
        if(lcm(::a[i],n/::a[i])==n)
        {
            if(max(::a[i],n/::a[i])<=ans)
            {
                ans=max(::a[i],n/::a[i]);
                a=::a[i],b=n/::a[i];
            }
        }
    }
    cout<<b<<" "<<a;
}
signed main()
{
    sol();
    return 0;
}