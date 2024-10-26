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
    int ans=INT_MAX;
    auto count=[&](int x)->int
    {
        int cnt=0;
        for(int i=x;i<n;++i)
        {
            if(a[x]<a[i])cnt++;
        }
        return cnt;
    };
    for(int i=0;i<n;++i)
    {
        ans=min(ans,i+count(i));
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