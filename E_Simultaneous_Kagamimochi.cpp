#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int l=0,r=n/2,ans=0;
    while(l<=r)
    {
        int mid=l+(r-l)/2,ok=1;
        for(int i=0;i<mid;++i)
        {
            if(a[n-mid+i]<a[i]*2)
            {
                ok=0;
                break;
            }
        }
        (ok)?ans=mid,l=mid+1:r=mid-1;
    }
    cout<<ans<<endl;
}
signed main()
{
    sol(); 
    return 0;
}