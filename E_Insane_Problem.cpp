#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int k,l1,r1,l2,r2;
    cin>>k>>l1>>r1>>l2>>r2;
    int res=0;
    if(k==1)
    {
        int low=max(l1,l2);
        int high=min(r1,r2);
        if(low<=high)res+=high-low+1;
    }
    else
    {
        int p=1;
        while(p<=r2/l1)
        {
            int xLow=(l2+p-1)/p;
            int xHigh=r2/p;
            int aLow=max(xLow,l1);
            int aHigh=min(xHigh,r1);
            if(aLow<=aHigh)res+=aHigh-aLow+1;
            if(p>r2/k)break;
            p*=k;
            if(p==0)break;
        }
    }
    cout<<res<<endl;
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