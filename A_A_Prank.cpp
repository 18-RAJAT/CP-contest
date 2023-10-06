#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[1001];
    int cnt=0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        cout<<0;
        return;
    }
    int res=0;
    for(int i=1;i<=n;++i)
    {
        int ans=0;
        if(i==1)
        {
            for(int j=1;j<=1000;++j)
            {
                if(j<a[i+1])
                {
                    ans+=1;
                }
            }
        }
        else if(i==n)
        {
            for(int j=1;j<=1000;++j)
            {
                if(j>a[i-1])
                {
                    ans+=1;
                }
            }
        }
        else
        {
            for(int j=1;j<=1000;++j)
            {
                if(j>a[i-1] && j<a[i+1])
                {
                    ans+=1;
                }
            }
        }
        if(ans==1)
        {
            cnt++;
        }
        else
        {
            res=max(res,cnt);
            cnt=0;
        }
    }
    res=max(res,cnt);
    cout<<res;
}
signed main()
{
    sol();
    return 0;
}