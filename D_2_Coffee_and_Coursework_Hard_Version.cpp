#include<bits/stdc++.h>
using namespace std;
#define int long long
int recur(vector<int>& a,int days,int m)
{
    int ans=0,maxi=0;
    for(int i=0;i<a.size();++i)
    {
        maxi+=max(0ll,a[i]-ans);
        if((i+1)%days==0)ans++;
    }
    return m<=maxi;
}
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    int ans=-1,l=1,r=n;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        (recur(a,mid,m)?ans=mid,r=mid-1:l=mid+1);
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}