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
    double ans=0;
    for(int i=0;i<n;++i)
    {
        int sum=0;
        for(int j=i;j<n;++j)
        {
            sum+=a[j];
            if(j-i+1>=k)
            {
                ans=max(ans,sum*1.0/(j-i+1));
            }
        }
    }
    cout<<fixed<<setprecision(15)<<ans;
}
signed main()
{
    sol();
    return 0;
}