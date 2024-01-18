#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int ans=0;
    map<int,int>mp;
    mp.clear();
    for(int i=0;i<n;++i)
    {
        int j=i;
        if(mp[a[i]]>=1)
        {
            int check=mp[a[i]];//check is the number of times a[i] has appeared before
            ans+=(j-check)*(check);
        }
        if(mp[a[i]]>=1)
        {
            //if a[i] has appeared before,then we need to add the number of pairs of indices (i,j) such that a[i]+a[j]>a[i]
            int ret=mp[a[i]];
            ret*=(ret-1);
            ret/=2;
            ans+=ret;
        }
        // for(auto it:mp)
        // {
        //     if(it.first>=a[i])
        //     {
        //         break;
        //     }
        //     ans+=it.second;
        // }
        mp[a[i]]++;
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