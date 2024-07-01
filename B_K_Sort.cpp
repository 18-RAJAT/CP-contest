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
    for(int i=0;i<n-1;++i)
    {
        if(a[i+1]<a[i])
        {
            ans+=a[i]-a[i+1];
            mx=max(a[i]-a[i+1],mx);
            a[i+1]=a[i];
        }
    }
    cout<<mx+ans<<endl;
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