#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    auto check=[&](int mid,int n,int k,int arr[])->bool
    {
        int tot=a[0]+mid;
        for(int i=1;i<n;++i)
        {
            if(k*tot<100LL*a[i])
            {
                return false;
            }
            tot+=a[i];
        }
        return true;
    };
    int l=0,r=1e12+5;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(check(mid,n,k,a))
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<l<<endl;
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