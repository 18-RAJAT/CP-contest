#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,d;
    cin>>n>>d;
    vector<array<int,2>>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i][0]>>a[i][1];
    }
    sort(a.begin(),a.end());
    int res=0,ans=0;
    for(int i=0,j=0;i<n;++i)
    {
        res+=a[i][1];
        for(;j<i && a[i][0]-a[j][0]>=d;++j)res-=a[j][1];
        ans=max(ans,res);
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}