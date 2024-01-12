#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>left(m),right(m);
    for(int i=0;i<m;++i)
    {
        cin>>left[i]>>right[i];
    }
    int q;
    cin>>q;
    vector<int>query(q);
    for(int i=0;i<q;++i)
    {
        cin>>query[i];
    }
    int low=0,high=q-1,ans=-1;
    while(low<=high)
    {
        int mid=low+high>>1;
        vector<int>prefix_sum(n+1,0);
        for(int i=0;i<=mid;++i)
        {
            prefix_sum[query[i]]++;
        }
        for(int i=1;i<=n;++i)
        {
            prefix_sum[i]+=prefix_sum[i-1];
        }
        bool ok=false;
        for(int i=0;i<m;++i)
        {
            //The number of queries in the range [left[i],right[i]] is greater than (right[i]-left[i]+1)/2
            if(prefix_sum[right[i]]-prefix_sum[left[i]-1]>(right[i]-left[i]+1)/2)
            {
                ok=true;
            }
        }
        (ok?ans=mid+1,high=mid-1:low=mid+1);
    }
    cout<<ans<<"\n";
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