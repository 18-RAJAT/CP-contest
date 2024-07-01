#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int Fact[16];
    memset(Fact,0,sizeof(Fact));
    Fact[0]=1;
    for(int i=1;i<16;++i)
    {
        Fact[i]=i*Fact[i-1];
    }
    int ans=1e18;
    for(int i=0;i<(1<<16);++i)
    {
        int current=0,a[65]={};
        for(int j=0;j<16;++j)
        {
            if(i&(1<<j))
            {
                current+=Fact[j];
                if(__builtin_popcountll(Fact[j])==1)a[__builtin_ctzll(Fact[j])]++;
            }
        }
        int ok=0,flag=1;
        for(int j=0;j<65;++j)if(a[j]>=2)ok=1;
        if(n<current || ok)continue;
        if(n-current==0)
        {
            ans=min(ans,(int)__builtin_popcountll(i));
            continue;
        }
        for(int j=0;j<65;++j)
        {
            if(n-current&(1<<j))flag=flag && (a[j]==0);
        }
        auto x=__builtin_popcountll(i),y=__builtin_popcountll(n-current);
        if(flag)ans=min(ans,(int)x+y);
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