#include<bits/stdc++.h>
using namespace std;
#define int long long
bool recur(int n,int m,int k,vector<int>& a,vector<int>& b,int x)
{
    vector<pair<int,int>>arr;
    for(int i=0;i<n;++i)
    {
        int p=m-(a[i]+x-1)/x;
        if(p<0)continue;
        int left=b[i]-p,right=b[i]+p;
        arr.push_back({left,1});
        arr.push_back({right+1,-1});
    }
    if(arr.empty())return false;
    sort(arr.begin(),arr.end());
    int cur=0,maxi=0;
    for(auto& it:arr)
    {
        cur+=it.second;
        if(maxi<cur)
        {
            maxi=cur;
            if(maxi>=k)return true;
        }
    }
    return false;
}
void sol()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>a(n),b(n);
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)cin>>b[i];
    int l=1,r=1e14,ans=-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        (recur(n,m,k,a,b,mid))?ans=mid,r=mid-1:l=mid+1;
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