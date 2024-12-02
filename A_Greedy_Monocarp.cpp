#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    int k;
    cin>>n>>k;
    vector<int>a(n);
    int sum=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sort(a.rbegin(),a.rend());
    int ans=LLONG_MAX,cnt=0;
    for(int i=1;i<=n;++i)
    {
        cnt+=a[i-1];
        if(cnt<=k)
        {
            int res=k-cnt;
            if(res>=0)ans=min(ans,res);
        }
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