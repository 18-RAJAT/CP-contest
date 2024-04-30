#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,a,b;
    cin>>n>>a>>b;
    int ans=0;
    auto binary_search=[&](int l,int r)->void
    {
        while(l<=r)
        {
            int mid=l+((r-l)>>1);
            if(a/mid+b/mid<n || a/mid==0 || b/mid==0)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1,ans=mid;
            }
        }
    };
    binary_search(1,1e9);
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}