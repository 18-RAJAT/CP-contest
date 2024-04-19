#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int ans=0;
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        ans+=mp[x]*(n-i);
        mp[x]+=i+1;
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