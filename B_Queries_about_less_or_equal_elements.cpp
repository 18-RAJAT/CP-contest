#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;++i)
    {
        cin>>b[i];
    }
    sort(a,a+n);
    function<int(int,int*,int)>binary_search=[&](int n,int *arr,int target)->int
    {
        int l=0,r=n-1;
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            (target<arr[mid])?
            ans=mid,r=mid-1:l=mid+1;
        }
        return(ans==-1)?n:ans;
    };
    vector<int>queries;
    queries.clear();
    for(int i=0;i<m;++i)
    {
        queries.emplace_back(binary_search(n,a,b[i]));
    }
    for(int i=0;i<queries.size();++i)
    {
        cout<<queries[i]<<" ";
    }
}
signed main()
{
    sol();
    return 0;
}