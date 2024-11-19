#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)cin>>b[i];
    vector<int>maxi(n);
    int total=0;
    for(int i=0;i<n;++i)
    {
        maxi[i]=a[i]/b[i];
        total+=maxi[i];
    }
    if(total<k)
    {
        for(int i=0;i<n;++i)cout<<0<<(i<n-1?" ":"\n");
        return;
    }
    vector<int>ans(n);
    int rem=k;
    for(int i=0;i<n;++i)
    {
        int sum=0;
        for(int j=i+1;j<n;++j)sum+=maxi[j];
        int mx=max(0LL,rem-sum);
        ans[i]=min(maxi[i],mx);
        rem-=ans[i];
    }
    for(int i=0;i<n;++i)cout<<ans[i]<<(i<n-1?" ":"\n");
}
signed main()
{
    sol();
    return 0;
}