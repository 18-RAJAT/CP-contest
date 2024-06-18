#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    pair<int,int>p;
    p.first=0,p.second=0;
    int count=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        (i&1)?p.first+=a[i]:p.second+=a[i];
    }
    (n&1)?p.second-=a[0]:p.second-=a[0];
    for(int i=0;i<n-1;++i)
    {
        if(p.first==p.second)count++;
        (i&1)?p.second-=(a[i+1]-a[i]):p.first-=(a[i+1]-a[i]);
    }
    if(p.first==p.second)count++;
    cout<<count;
}
signed main()
{
    sol();
    return 0;
}