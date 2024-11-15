#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    vector<int>dp;
    for(auto& it:a)
    {
        auto ub=upper_bound(dp.begin(),dp.end(),it);
        if(ub==dp.end())dp.push_back(it);
        else *ub=it;
    }
    cout<<n-dp.size()<<endl;
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