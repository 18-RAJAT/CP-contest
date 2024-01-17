#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int mx=1;
    int dp[27];
    fill(dp,dp+27,0);
    for(int i=0;i<n;++i)
    {
        dp[a[i]]++;
    }
    for(int i=1;i<=26;++i)
    {
        for(int j=1;j<=dp[i]/2;++j)
        {
            int p=0,q=0,k=0,l=n-1;
            for(k=0;k<n;++k)
            {
                if(a[k]==i && p<j)
                {
                    p++;
                }
                if(p==j)
                {
                    break;
                }
            }
            for(l=n-1;~l;--l)
            {
                if(a[l]==i && q<j)
                {
                    q++;
                }
                if(q==j)
                {
                    break;
                }
            }
            if(k==l)
            {
                continue;
            }
            // for(int m=1;m<=26;++m)
            // {
            //     if(m==i)
            //     {
            //         continue;
            //     }
            //     mx=max(mx,2*j+dp[m]);
            // }
            int compute[27];
            fill(compute,compute+27,0);
            for(int m=k+1;m<l;++m)
            {
                compute[a[m]]++;
            }
            int mx2=0;
            for(int m=1;m<=26;++m)
            {
                mx2=max(mx2,compute[m]);
            }
            mx=max(mx,mx2+2*j);
        }
    }
    cout<<mx<<endl;
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