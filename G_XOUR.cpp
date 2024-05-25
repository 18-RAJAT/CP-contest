#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    map<int,priority_queue<int,vector<int>,greater<int>>>mp;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        mp[a[i]/4].push(a[i]);
    }
    for(int i=0;i<n;++i)
    {
        cout<<mp[a[i]/4].top()<<" ";
        mp[a[i]/4].pop();
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