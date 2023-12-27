#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    unordered_map<int,int>mp1,mp2;
    mp1.clear();
    mp2.clear();
    int maximum1=0,maximum2=0;
    int x,y;
    for(int i=0;i<n;++i)
    {
        cin>>x>>y;
        mp1[(x+y)]++,mp2[(x-y)]++;
    }
    int total=0;
    for(auto it=mp1.begin();it!=mp1.end();++it)
    {
        total+=(it->second*(it->second-1))/2;
    }
    for(auto it=mp2.begin();it!=mp2.end();++it)
    {
        total+=(it->second*(it->second-1))/2;
    }
    cout<<total<<endl;
}
signed main()
{
    sol();
    return 0;
}