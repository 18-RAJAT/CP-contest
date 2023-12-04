#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,l,t,p;
    cin>>n>>l>>t>>p;
    auto check_pts=[&](int x)->int
    {
        int ert=(n-x);
        int mul=ert*t;
        int task=min((n-1)/7+1,2*ert);
        mul+=task*p;
        return l<=mul;
    };
    int ans=0;
    int low=0,high=n;
    auto right_shift=[&](int x)->int
    {
        return x>>1;
    };
    while(low<=high)
    {
        int mid=right_shift(low+high);
        if(check_pts(mid))
        {
            ans=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
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