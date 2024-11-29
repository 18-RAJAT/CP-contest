#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,h,m;
    cin>>n>>h>>m;
    vector<int>a(n,h);
    for(int i=0;i<m;++i)
    {
        int l,r,x;
        cin>>l>>r>>x;
        for(int j=l-1;j<r;++j)
        {
            a[j]=min(x,a[j]);
        }
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        ans+=a[i]*a[i];
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}