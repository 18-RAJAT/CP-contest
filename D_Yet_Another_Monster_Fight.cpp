#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int pref[n],suf[n];
    int current=0;
    for(int i=0;i<n;++i)
    {
        pref[i]=max(current,a[i]);
        current=max(current,a[i]+n-i-1);//n-i-1 is the distance from the end
    }
    current=0;
    for(int i=n-1;i>=0;--i)
    {
        suf[i]=max(current,a[i]);
        current=max(current,a[i]+i);//i is the distance from the beginning
    }
    int ans=INT_MAX;
    for(int i=0;i<n;++i)
    {
        ans=min(ans,max(pref[i],suf[i]));
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}