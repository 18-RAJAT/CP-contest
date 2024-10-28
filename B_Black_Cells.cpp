#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int l=1,r=1e18,ans=-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        int i=0,j=1,ok=1;
        while(i<n)
        {
            if(i+1<n && a[i+1]-a[i]<=mid)
            {
                i+=2;
            }
            else
            {
                if(j>0 && mid>=1)
                {
                    j--;
                    i++;
                }
                else
                {
                    ok=0;
                    break;
                }
            }
        }
        (ok)?ans=mid,r=mid-1:l=mid+1;
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