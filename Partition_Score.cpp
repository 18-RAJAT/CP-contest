#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        mp[i]=x;
    }
    vector<pair<int,int>>v(mp.begin(),mp.end());
    sort(v.begin(),v.end(),[&](pair<int,int>&a,pair<int,int>&b)
    {
        return a.second<b.second;
    });
    if(k==1)
    {
        cout<<2*v[n-1].second+v[0].second+v[n-2].second<<endl;
        return;
    }
    cout<<v[0].second+v[n-1-k].second+v[n-1].second+v[n-2].second<<endl;
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