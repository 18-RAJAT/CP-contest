#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i].first;
    }
    for(int i=0;i<n;++i)
    {
        cin>>a[i].second;
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;++i)
    {
        cout<<a[i].first<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<a[i].second<<" ";
    }
    cout<<endl;
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