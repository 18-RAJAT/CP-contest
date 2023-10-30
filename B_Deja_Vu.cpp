#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    for(auto& it:a)
    {
        cin>>it;
    }
    vector<int>bits(31);
    vector<int>query(q);
    for(auto&it:query)
    {
        cin>>it;
        // for(int j=0;j<31;++j)
        // {
        //     if(query[i]&(1<<j))
        //     {
        //         bits[j]++;
        //     }
        // }
    }
    vector<int>vis(n);
    for(int i=30;i>=0;--i)
    {
        int nw=i,val=0,x=1LL<<i;
        for(auto x:query)
        {
            if(x<=nw)
            {
                nw=x-1;
                val+=(1<<(x-1));
            }
        }
        for(int i=0;i<n;++i)
        {
            if(vis[i])
            {
                continue;
            }
            if(a[i]%x==0)
            {
                vis[i]=true;
                a[i]+=val;
            }
        }
    }
    for(auto& it:a)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
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