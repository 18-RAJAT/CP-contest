#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],n,k;
int recur(int x)
{
    int ans=0;
    for(int i=0;i<n;++i)ans+=min(a[i],x);
    return ans;
}
void sol()
{
    cin>>n>>k;
    for(int i=0;i<n;++i)cin>>a[i];
    int l=0,r=1e18;
    while(r-l>=2)
    {
        int mid=(l+r)/2;
        (recur(mid)>=k)?r=mid:l=mid;
    }
    int ans=0,count=0;
    for(int i=0;i<n;++i)ans+=min(1+a[i],l);
    int rem=k-recur(l);
    for(int i=0;i<n;++i)
    {
        count+=(l==a[i]);
    }
    int res=rem+ans+count;
    cout<<res<<endl;
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