#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    map<int,int>mp;
    for(int i=0;i<n;++i)mp[a[i]]++;
    vector<pair<int,int>>vp;
    for(auto& it:mp)vp.push_back(it);
    vector<int>prod;
    int res=0;
    while(res<vp.size() && prod.size()<=1)
    {
        if(vp[res].second>=2)
        {
            prod.push_back(vp[res].first);
            vp[res].second-=2;
        }
        if(vp[res].second<2)res++;
    }
    res=vp.size()-1;
    while(res>=0 && prod.size()<=3)
    {
        if(vp[res].second>=2)
        {
            prod.push_back(vp[res].first);
            vp[res].second-=2;
        }
        if(vp[res].second<2)res--;
    }
    if(prod.size()!=4)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    cout<<prod[0]<<" "<<prod[1]<<" "<<prod[3]<<" "<<prod[1]<<" "<<prod[0]<<" "<<prod[2]<<" "<<prod[3]<<" "<<prod[2]<<endl;
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