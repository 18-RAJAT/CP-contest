#include<bits/stdc++.h>
using namespace std;
#define int long long
int c[2000005];
int Gcd(int a,int b)
{
    if(a%b==0)return b;
    else return Gcd(b,a%b);
}
void sol()
{
    int n,a,b;
    cin>>n>>a>>b;
    int ans=Gcd(a,b);
    for(int i=1;i<=n;++i)
    {
        cin>>c[i];
        c[i]%=ans;
    }
    sort(c+1,c+1+n);
    for(int i=1;i<=n;++i)
    {
        c[n+i]=c[i]+ans;
    }
    int res=1e18;
    for(int i=1;i<=n;++i)
    {
        res=min(c[i+n-1]-c[i],res);
    }
    // int temp=d[n-1]-d[0];
    // for(int i=0;i<n-1;++i)
    // {
    //     d[i]+=ans;
    //     int total=d[i]-d[i-1];
    //     if(total<temp)temp=total;
    // }
    cout<<res<<endl;
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