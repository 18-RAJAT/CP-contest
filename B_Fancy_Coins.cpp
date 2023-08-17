#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,k,a1,ak;
        cin>>m>>k>>a1>>ak;
        int x=m/k;
        if(m/k<ak)
        {
            m-=(m/k*k);
        }
        else
        {
            m-=ak*k;
        }
        if(m<=a1)
        {
            m=0;//no change
        }
        else
        {
            m-=a1;
        }
        int ans=m/k;
        // ans+=min(m%k,1LL);
        int ert=(ans+1)*k;
        // cout<<"CHECK -> "<<ert<<" ";//taking ending state
        ert-=m;
        // cout<<ans<<"\n";
        m-=(ans*k);
        if(ert<=a1 && m>=2)
        {
            ans++;
            m=0;
        } 
        // else
        // {
        //     ans+=max(m,1LL)-1;
        //     m=0;
        //     if(ans>=4 && ans<=10)
        //     {
        //         ans+=1;
        //     }
        // }
        cout<<ans+m<<"\n";
    }
    return 0;
}