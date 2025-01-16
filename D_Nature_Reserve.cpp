#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<pair<double,double>>vp;
double func(double x,double y)
{
    double ans=0;
    for(int i=0;i<n;++i)
    {
        double calc=(x-vp[i].first)*(x-vp[i].first)+vp[i].second*vp[i].second,mul=2.0*vp[i].second;
        ans=max(ans,calc/mul);
    }
    return ans;
}
double recur(double l,double r,int i)
{
    while(r-l>1e-9)
    {
        double d1=l+(r-l)/3,d2=r-(r-l)/3,f1=func(d1,l),f2=func(d2,l);
        (f2<f1)?l=d1:r=d2;
    }
    return func(l,r);
}
void sol()
{
    cin>>n;
    vp.resize(n);
    for(int i=0;i<n;++i)cin>>vp[i].first>>vp[i].second;
    int ok=1;
    for(int i=1;i<n;++i)
    {
        if(vp[i].second*vp[0].second<=0)ok=0;
    }
    if(ok)cout<<fixed<<setprecision(10)<<recur(-1e9,1e9,0)<<endl;
    else cout<<-1<<endl;
}
signed main()
{
    sol();
    return 0;
}