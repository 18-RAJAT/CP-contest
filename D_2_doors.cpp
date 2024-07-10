#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<array<int,3>>a(q);
    vector<vector<array<int,2>>>b(n);
    for(auto& it:a)
    {
        cin>>it[0]>>it[1]>>it[2];
        it[0]--,it[1]--;
        if(it[1]<it[0])swap(it[0],it[1]);
        b[it[0]].push_back({it[1],it[2]});
    }
    vector<int>mask(n,(1LL<<31)-1);
    for(auto& it:a)
    {
        int x=it[0],y=it[1],z=it[2];
        mask[x]&=z,mask[y]&=z;
    }
    vector<int>ans(n,0);
    for(int i=0;i<n;++i)
    {
        auto& it=b[i];
        if(it.empty()){continue;}
        int res=0;
        for(auto& q:it)
        {
            int x=i,y=q[0],z=q[1];
            int ret=z&~mask[y];
            res|=ret;
        }
        ans[i]|=res;
        for(auto& itr:it)
        {
            int x=i,y=itr[0];
            int dor=(~ans[x])&(~ans[y])&itr[1];
            ans[y]|=dor;
        }
    }
    for(auto& it:ans)cout<<it<<" ";
}
signed main()
{
    sol();
    return 0;
}