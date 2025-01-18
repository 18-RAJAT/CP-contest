#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ul unsigned long long
//Rajat joshi template
ul Sqrt(ul x)
{
    ul r=(ul)floor(sqrt((long double)x));
    while((r+1)*(ul)(r+1)<=x)r++;
    while(r*r>x)r--;
    return r;
}
void sol()
{
    int n,m;cin>>n>>m;
    vector<int>p(n);
    for(int i=0;i<n;++i)cin>>p[i];
    ul h=0,ok=0;
    for(int i=0;i<n;++i)
    {
        if(p[i]<=m)
        {
            ok=1;
            ul rem=m/p[i],k=Sqrt(rem);
            if(k==0)continue;
            ul calc=(2LL*k-1LL)*p[i];
            h=max<ul>(h,calc);
        }
    }
    if(!ok)
    {
        cout<<0<<endl;
        return;
    }
     //2*p[i] bel (10^9)^2*(2*10^9)=2*10^27(look)
    ul l=0,res=0;
    while(l<=h)
    {
        ul mid=l+(h-l)/2;
        __int128 chk=0;
        for(int i=0;i<n;++i)
        {
            ul q=mid/p[i],k=(q+1)/2;
            __int128 F=(__int128)p[i]*k*k;
            chk+=F;
            if(chk>m)break;
        }
        (chk<=m)?(res=mid,l=mid+1):(h=mid-1);
    }
    __int128 ans=0;
    for(int i=0;i<n;++i)
    {
        ul q=res/p[i],k=(q+1)/2;
        ans+=k;
    }
    cout<<(int)ans;
}
signed main()
{
    sol();
    return 0;
}