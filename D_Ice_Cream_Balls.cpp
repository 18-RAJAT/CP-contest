#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int ans=0;
    int l=1,r=INT_MAX;
    while(l<=r)
    {
        int m=l+(r-l)/2;
        if(m*(m-1)/2>n)
        {
            ans=m;
            r=m-1;
        }
        else
        {
            l=m+1;
        }   
    }
    ans--;
    ans+=n-ans*(ans-1)/2;
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