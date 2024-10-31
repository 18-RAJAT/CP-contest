#include<bits/stdc++.h>
using namespace std;
#define int long long
struct item
{
    int x,y;
    int diff(){return x-y;}
};
void sol()
{
    int n;
    cin>>n;
    vector<item>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i].x;
    }
    for(int i=0;i<n;++i)
    {
        cin>>a[i].y;
    }
    sort(a.begin(),a.end(),[&](item &a,item &b){return a.diff()<b.diff();});
    int ans=0,buy=0;
    for(int i=0;i<n;++i)buy+=a[i].y;
    ans=buy;
    buy+=a[0].diff();
    for(int i=1;i<=n-1;++i)
    {
        buy+=a[i].diff(),ans=min<int>(ans,buy);
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