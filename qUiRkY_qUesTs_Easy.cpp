#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,ans=0;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        // int x;
        // cin>>x;
        cin>>a[i];
        // sum+=x;
    }
    for(int i=0;i<n;++i)ans+=a[i];
    sort(a.begin(),a.end());
    int sum=ans;
    for(int i=0;i<n;++i)
    {
        sum-=a[i];
        // sum=max(sum,temp);
        ans=max(ans,sum+(i+1)*(i+1));
    }
    ans=max(ans,n*n);
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