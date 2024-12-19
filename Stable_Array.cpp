#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i)cin>>a[i];
    int mx=LLONG_MIN,p=-1,ans=0;
    vector<int>mp(n+1,0);
    for(int i=n;i>=1;--i)
    {
        if(a[i]>=mx){
            mx=a[i];
            p=i;
        }
        mp[i]=p;
    }
    for(int i=1;i<=n;++i)
    {
        int t=mp[i]-i;
        if(t>ans)ans=t;
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