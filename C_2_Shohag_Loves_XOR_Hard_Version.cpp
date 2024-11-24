#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int x,m;
    cin>>x>>m;
    int tmp=1;
    while(tmp<=x)tmp<<=1;
    vector<int>a(tmp,1e18);
    for(int i=x;i>=1;--i)a[(x-i*tmp%x)%x]=i*tmp;
    int ans=m/a[0];
    for(int i=1;i<tmp && i<=m;++i)
    {
        int res=x^i;
        if(res%x==0 || res%i==0)++ans;
        int cmp=i+a[res%x];
        if(cmp<=m)ans+=(m-cmp)/a[0]+1;
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