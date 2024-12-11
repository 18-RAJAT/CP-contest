#include <bits/stdc++.h>
using namespace std;
#define int long long

void sol()
{
    int n,k;cin>>n>>k;
    int a[n];
    for(int i=0;i<n;++i)cin>>a[i];
    vector<vector<int>>v(2);
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        v[x-1].push_back(a[i]);
    }
    int sum=accumulate(a,a+n,0ll);
    if(sum<k)
    {
        cout<<-1<<endl;
        return;
    }
    int ans=LLONG_MAX;
    for(int i=0;i<2;++i)
    {
        if(v[i].empty())continue;
        sort(v[i].rbegin(),v[i].rend());
        if(v[i][0]>=k)ans=min(ans,i+1);
        for(int j=1;j<v[i].size();j++)
        {
            v[i][j]+=v[i][j-1];
            if(v[i][j]>=k)ans=min(ans,(j+1)*(i+1));
        }
    }
    for(int i=0;i<v[0].size();++i)
    {
        if(v[1].empty())continue;
        int l=0,r=v[1].size()-1;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            (v[0][i]+v[1][mid]<k)?l=mid:r=mid;
        }
        if(v[0][i]+v[1][l]>=k)ans=min(ans,i+l*2+3);
        if(v[0][i]+v[1][r]>=k)ans=min(ans,i+r*2+3);
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
}