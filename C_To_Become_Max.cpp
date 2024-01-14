#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        int temp=k;
        auto binary_search=[&](int mid)->bool
        {
            int ert=mid;
            temp=k;
            bool ok=false;
            for(int j=i;j<n;++j)
            {
                if(a[j]>=mid)
                {
                    ok=true;
                    break;
                }
                if(mid-a[j]<=temp)
                {
                    temp-=(mid-a[j]);
                    mid--;
                }
                else
                {
                    ok=false;
                    break;
                }
            }
            mid=ert;
            ok?ans=max(mid,ans):ans;
            return ok?true:false;
        };
        int left=0,right=1e9+5;
        while(left<=right)
        {
            int mid=(left+right)/2;
            binary_search(mid)?left=mid+1:right=mid-1;
        }
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