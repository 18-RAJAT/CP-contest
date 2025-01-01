#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a[100005];
    for(int i=0;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
    }
    int res=0,ans=0;
    for(int i=1;i<=m;++i)
    {
        sort(a[i].begin(),a[i].end(),greater<int>());
        res=max<int>(res,a[i].size());
    }
    vector<int>b(res,0);
    for(int i=1;i<=m;++i)
    {
        int cur=0;
        for(int j=0;j<a[i].size();++j)
        {
            cur+=a[i][j];
            if(cur<0)break;
            b[j]+=cur;
        }
    }
    for(int i=0;i<res;++i)ans=max(ans,b[i]);
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}