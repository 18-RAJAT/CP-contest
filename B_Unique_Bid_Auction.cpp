#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    map<int,int>mp;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    int mn=INT_MAX;
    int ans=-1;
    for(int i=0;i<n;++i)
    {
        if(mp[a[i]]==1)
        {
            if(a[i]<mn)
            {
                mn=a[i];
                ans=i+1;
            }
        }
    }
    cout<<ans<<"\n";
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