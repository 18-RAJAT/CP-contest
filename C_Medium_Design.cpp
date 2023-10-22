#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(),a.end());
    vector<int>seg;
    int r=-1;
    for(int i=0;i<n;++i)
    {
        if(a[i].first>r)
        {
            seg.push_back(a[i].second-a[i].first+1);
            r=a[i].second;
        }
        else
        {
            seg.back()=max(seg.back(),a[i].second-r);
            r=a[i].second;
        }
    }
    int ans=0;
    int sum=0;
    for(int i=0;i<seg.size();++i)
    {
        sum+=seg[i];
        ans=max(ans,sum);
    }
    cout<<m-ans<<"\n";
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