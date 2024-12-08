#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),arr(n+1,0);
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    int ele=0;
    for(auto it=mp.begin();it!=mp.end();++it)
    {
        ele=max(ele,mp[it->first]);
        arr[mp[it->first]]++;
    }
    int ans=arr[ele]-1,count=0;
    for(int i=ele-1;~i;--i)
    {
        count+=(arr[i]*i);
    }
    ans+=(count/(ele-1));
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