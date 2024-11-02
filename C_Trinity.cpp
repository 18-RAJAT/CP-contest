#include<bits/stdc++.h>
using namespace std;
#define int long long
int sorted(vector<int>&a,int n,int mid)
{
    for(int i=0;i+mid-1<n;++i)
    {
        if(a[i+mid-1]<a[i]+a[i+1]) return 1;
    }
    return 0;
}
int binary_search_ans(vector<int>&a,int n)
{
    int ans=n,l=1,r=n;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        int ok=0;
        if(mid==1)
        {
            ans=min(ans,n-1);
            l=mid+1;
            continue;
        }
        ok=sorted(a,n,mid);
        (ok)?ans=min(ans,n-mid),l=mid+1:r=mid-1;
    }
    return ans;
}
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a.begin(),a.end());
    cout<<binary_search_ans(a,n)<<endl;
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