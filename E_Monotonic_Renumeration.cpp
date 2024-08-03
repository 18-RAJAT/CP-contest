#include<bits/stdc++.h>
using namespace std;
#define int long long
int mul(const int x,const int y,const int& mod)
{
    return ((x%mod)*(y%mod))%mod;
}
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    map<int,vector<int>>mp;
    for(int i=0;i<n;++i)
    {
        mp[a[i]].push_back(i);
    }
    const int M=1000000007;
    int ans=1;
    for(int i=0;i<n;++i)
    {
        int current=mp[a[i]].back();
        if(i!=0)ans=mul(ans,2,M);
        while(i<n && i<current)
        {
            i++;
            current=max(current,mp[a[i]].back());
        }
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}