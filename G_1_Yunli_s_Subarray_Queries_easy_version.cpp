#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k,q;
    cin>>n>>k>>q;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        a[i]-=i;
    }
    vector<int>dp(n);
    map<int,int>mp;
    multiset<int>ms;
    for(int i=0;i<n;++i)ms.insert(0);
    for(int i=0;i<n;++i)
    {
        if(i>=k)
        {
            ms.erase(ms.find(mp[a[i-k]]));
            mp[a[i-k]]--;
            ms.insert(mp[a[i-k]]);
        }
        ms.erase(ms.find(mp[a[i]]));
        mp[a[i]]++;
        ms.insert(mp[a[i]]);
        dp[i]=*ms.rbegin();
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--,r--;
        cout<<r-l+1-dp[r]<<endl;
    }
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