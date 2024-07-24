#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int sum=0,ans=0;
    sort(a.begin(),a.end());
    int j=0;    
    for(int i=0;i<n;++i)
    {
        sum+=a[i];
        for(;a[i]-a[j]>=2 || m<sum;)
        {
            sum-=a[j],j++;
        }
        if(sum<=m)ans=max(ans,sum);
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