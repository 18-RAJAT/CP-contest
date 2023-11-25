#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int ans=0;
    int tmp=a[0];
    ans=max(ans,tmp);
    for(int i=1;i<n;++i)
    {
        ans=max(ans,a[i]-a[i-1]);
    }
    int ert=2*(x-a[n-1]);
    ans=max(ans,ert);
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