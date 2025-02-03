#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n),cnt(n+2,0),chk(n+2,0);
    for(int i=0;i<n;++i)cin>>a[i];
    int res=-1;
    for(int i=0;i<n;++i)
    {
        int x=a[i];
        if(x<=n+1)
        {
            cnt[x]++;
            if(x!=res)chk[x]++;
            // cout<<x<<" "<<cnt[x]<<" "<<chk[x]<<endl;
            // else if(x==res && chk[x]==1)
            // {
            //     res=-1;
            //     break;
            // }
            res=x;
        }
        else if(x==n+2)res=x;
        else res=-1;
    }
    int ans=n+1;
    for(int i=1;i<=n+1;++i)
    {
        if(cnt[i]==0)
        {
            ans=i;
            break;
        }
        // else if(cnt[i]+k-chk[i]==n)
        // {
        //     ans=i;
        //     break;
        // }
        else if(cnt[i]+k-chk[i]>n)
        {
            for(int j=i+1;j<=n+1;++j)
            {
                if(cnt[j]+k-chk[j]<=n)
                {
                    ans=j;
                    break;
                }
            }
            for(auto& it:cnt)
            {
                if(it+cnt[0]+k-chk[0]<=n)
                {
                    ans=0;
                    break;
                }
            }
        }
        // for(auto& it:cnt)cout<<it<<" ";cout<<endl;
        if(cnt[i]+k-chk[i]<=n || i==n+1)
        {
            ans=i;
            break;
        }
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