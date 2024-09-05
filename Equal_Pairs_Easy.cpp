#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    map<int,int>mp;
    int count=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        a[i]==0?count++:mp[a[i]]++;
    }
    int maxi=0,max_fz=-1;
    for(auto &it:mp)
    {
        if(it.second>maxi)
        {
            max_fz=it.first,maxi=it.second;
        }
    }
    maxi+=count;
    int ans=(maxi*(maxi-1))>>1;
    for(auto &it:mp)
    {
        if(it.first!=max_fz)
        {
            ans+=(it.second*(it.second-1))>>1;
        }
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