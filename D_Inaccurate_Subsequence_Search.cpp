#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>a(n),b(m);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;++i)
    {
        cin>>b[i];
    }
    vector<int>mp1(1e6+1,0),mp2(1e6+1,0);
    for(int i=0;i<b.size();++i)
    {
        mp1[b[i]]++;
    }
    int current=0,ans=0;
    for(int i=0;i<m;++i)//m
    {
        mp2[a[i]]++;
    }
    if(current>=k)
    {
        ans++;
    }
    if(n==m)
    {
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<n-m;++i)
    {
        if(a[i]!=a[i+m])
        {
            current-=min(mp1[a[i]],mp2[a[i]]);
            current-=min(mp1[a[i+m]],mp2[a[i+m]]);
            mp2[a[i]]--;
            mp2[a[i+m]]++;
            current+=min(mp1[a[i]],mp2[a[i]]);
            current+=min(mp1[a[i+m]],mp2[a[i+m]]);
            // for(int i=mp1.size()-1;i>=0;--i)
            // {
            //     if(mp2[i]>0)
            //     {
            //         cout<<i<<" ";
            //     }
            // }
        }
        if(current>=k)
        {
            ans++;
        }
    }
    // mp1.clear();
    // mp2.clear();
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