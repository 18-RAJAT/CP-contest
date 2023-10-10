#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n/2;++i)
    {
        cin>>a[i];
    }
    vector<int>first,last;
    first.push_back(0),last.push_back(a[0]);
    for(int i=1;i<n/2;++i)
    {
        int mn=min(last.back(),a[i]);
        int mx=max(first.back(),a[i]-mn);
        first.push_back(mx);
        last.push_back(a[i]-mx);
    }
    sort(last.begin(),last.end());
    for(auto& it:first)
    {
        cout<<it<<" ";
    }
    for(auto& it:last)
    {
        cout<<it<<" ";
    }
}
signed main()
{
    sol();
    return 0;
}