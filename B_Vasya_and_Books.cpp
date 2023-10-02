#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    map<int,int>mp;
    vector<int>a;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        mp[x]=i+(1);
    }
    int last=0;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        a.push_back(max<int>(mp[x]-last,(0)));
        last=max(last,mp[x]);
    }
    for(int i=0;i<a.size();++i)
    {
        cout<<a[i]<<" ";
    }
}
signed main()
{
    sol();
    return 0;
}