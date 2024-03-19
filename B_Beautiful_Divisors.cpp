#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    auto power=[&](int a,int b)->int
    {
        int ans=1;
        for(int i=0;i<b;++i)
        {
            ans*=a;
        }
        return ans;
    };
    map<int,int>mp;
    int ans=1;
    for(int i=1;i<51;++i)
    {
        int x=(power(2,i)-1)*(power(2,i-1));
        mp[x]=1;
    }
    int res=1;
    for(int i=1;i*i<=n;++i)
    {
        if(n%i)
        {
            continue;
        }
        if(mp[i])
        {
            res=max(res,i);
        }
        if(mp[n/i])
        {
            res=max(res,n/i);
        }
    }
    cout<<res<<endl;
}
signed main()
{
    sol();
    return 0;
}