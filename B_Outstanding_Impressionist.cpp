#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<pair<int,int>>vp(n);
    int sza=0;
    for(int i=0;i<n;++i)
    {
        cin>>vp[i].first>>vp[i].second;
        if(vp[i].second>sza)sza=vp[i].second;
    }
    vector<int>cnt(sza+2,0),z;
    for(int i=0;i<n;++i)
    {
        if(vp[i].first==vp[i].second) cnt[vp[i].first]++;
    }
    for(int v=1;v<=sza;++v)
    {
        if(cnt[v]==0)z.push_back(v);
    }
    string res="";
    for(int i=0;i<n;++i)
    {
        int l=vp[i].first,r=vp[i].second;
        if(l==r)
        {
            (cnt[l]==1)?res+='1':res+='0';
        }
        else
        {
            int LB=lower_bound(z.begin(),z.end(),l)-z.begin();
            if(LB<z.size() && z[LB]<=r)res+='1';
            else res+='0';
        }
    }
    cout<<res<<endl;
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