#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;cin>>n;
    vector<int>a(n);
    for(auto& it:a)cin>>it;
    auto count=[&](int n){return 1LL*n*(n+1)/2;};
    int ans=count(n);
    for(int i=0;i<=10;++i)
    {
        vector<int>ar=a,b(n);
        unordered_map<int,int>br;
        for(int j=0;j<n;++j)
        {
            ar[j]=(ar[j]>i)?1:-1;
            if(j)ar[j]+=ar[j-1];
        }
        for(int j=0;j<n;++j)
        {
            if(a[j]==i)b[j]=1;
            if(j)b[j]+=b[j-1];
        }
        int res=n;
        for(int j=n-1;~j;--j)
        {
            if(a[j]==i)
            {
                for(int k=j;k<res;++k)br[ar[k]+n]++;
                res=j;
            }
            ans-=br[(j?ar[j-1]:0)+n];
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