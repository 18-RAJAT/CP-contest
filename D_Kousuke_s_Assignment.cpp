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
        if(i>0)a[i]+=a[i-1];
    }
    map<int,int>mp;
    int ans=0;
    mp[0]=1;
    for(int i=0;i<n;++i)
    {
        if(mp[a[i]]==1)
        {
            ans++,mp.clear();
        }
        mp[a[i]]=1;
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