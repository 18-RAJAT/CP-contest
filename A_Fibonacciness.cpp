#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int x=a+b,y=c-b,z=d-c,ans=0;
    for(auto& it:{x,y,z})
    {
        int cnt=0;
        if(it==x)cnt++;
        if(it==y)cnt++;
        if(it==z)cnt++;
        ans=max(ans,cnt);
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