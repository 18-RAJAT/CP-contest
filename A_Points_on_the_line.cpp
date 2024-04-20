#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,d;
    cin>>n>>d;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        cout<<0;
        return;
    }
    int ans=n;
    sort(a,a+n);
    for(int i=0;i<n-1;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(a[j]-a[i]<=d)
            {
                int diff=(a[j]-a[i]);
                if(diff<=d)
                {
                    int res=0;
                    for(int k=0;k<n;++k)
                    {
                        if(a[k]>=a[i] && a[k]<=a[j])
                        {
                            res++;
                        }
                    }
                    ans=min(ans,n-res);
                }
            }
        }
    }
    if(n==ans)
    {
        cout<<n-1;
        return;
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}