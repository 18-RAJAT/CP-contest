#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    multiset<array<int,2>>ms;
    for(int i=0;i<n;++i)
    {
        int n;
        cin>>n;
        ms.insert({n,i});
    }
    for(int i=0;i<k && ms.size()>=2;++i)
    {
        auto first=ms.begin();
        auto last=prev(ms.end());
        int sum=first->at(0)+last->at(0);
        int new_pos=last->at(1);
        ms.erase(last);
        ms.erase(first);
        ms.insert({sum,new_pos});
    }
    vector<int>ans(n,-1);
    for(const auto&it:ms)
    {
        ans[it[1]]=it[0];
    }
    for(int i=0;i<n;++i)
    {
        if(~ans[i])
        {
            cout<<ans[i]<<" ";
        }
    }
    cout<<endl;
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