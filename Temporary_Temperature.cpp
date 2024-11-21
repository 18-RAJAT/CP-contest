#include<bits/stdc++.h>
using namespace std;
#define int long long
int BinarySearchK(vector<int>& a,int x,int y,int k)
{
    int ans=1;
    int l=a[0]-y,r=a[0]+y;
    for(int i=1;i<x;++i)
    {
        int L=max(l,a[i]-y),R=min(r,a[i]+y);
        if(L<=R)
        {
            l=L,r=R;
        }
        else
        {
            ans++,l=a[i]-y,r=a[i]+y;
            if(k+1<ans)return 0;
        }
    }
    return (ans<=k+1);
}
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int l=0,r=1e9,ans=r;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        (BinarySearchK(a,n,mid,k))?ans=mid,r=mid-1:l=mid+1;
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