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
    for(int i=0;i<n-1;++i)
    {
        if(a[i]==1)mp[1]++;
    }
    for(int i=1;i<n;++i)
    {
        if(a[i]==0)mp[0]++;
    }
    int x=mp[1],y=mp[0];
    int ans=min(x+y,n-1);
    cout<<n+ans<<endl;
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