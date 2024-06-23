#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,x,y,n;
    cin>>a>>b>>x>>y>>n;
    int d1=a-x,d2=b-y,ans,ans1,ans2;
    if(d1+d2<=n)
    {
        cout<<x*y<<endl;
        return;
    }
    ans1=(a-min(d1,n))*(b-min(n-min(d1,n),d2));
    ans2=(b-min(d2,n))*(a-min(n-min(d2,n),d1));
    ans=min(ans1,ans2);
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