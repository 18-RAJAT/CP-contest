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
    int ans=0,mx=0;
    for(int i=0;i<n;++i)
    {
        ans+=a[i];
    }
    map<int,int>fz;
    for(auto& it:a)
    {
        fz[it]++;
        if(fz[it]>=2)
        {
            mx=max(it,mx);
        }
        it=mx;
    }
    for(int i=0;i<n;++i)
    {
        ans+=a[i];
    }
    mx=0;
    fz.clear();
    for(auto& it:a)
    {
        fz[it]++;
        if(fz[it]>=2)
        {
            mx=max(it,mx);
        }
        it=mx;
    }
    for(int i=0;i<n;++i)ans+=a[i]*(n-i);
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