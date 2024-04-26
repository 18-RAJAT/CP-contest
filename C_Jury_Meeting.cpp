#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    map<int,int>mp;
    int meet=0,ans=1;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(a[i]>meet)
        {
            meet=a[i];
        }
        mp[a[i]]++;
        (ans*=i+1)%=998244353;
    }
    if(mp[meet]==1)
    {
        int temp=1;
        for(int i=2;i<=n;++i)
        {
            if(i!=mp[meet-1]+1)
            {
                (temp*=i)%=998244353;
            }
        }
        ans=(ans-temp+998244353)%998244353;
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