#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    for(auto& it:a)cin>>it;
    vector<int>query(2*n+1);
    for(int i=0;i<2*n;++i)
    {
        query[i+1]=query[i]+a[i%n];
    }
    int temp=query[n];
    auto FullCycle=[&](int x)->int
    {
        return (x/n)*temp+query[(x%n)+(x/n)]-query[x/n];
    };
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<FullCycle(r)-FullCycle(l-1)<<endl;
    }
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