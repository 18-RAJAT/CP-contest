#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(auto &it:a)cin>>it;
    a.push_back(0);
    sort(a.begin(),a.end());
    int ans=0,tmp=a[n];
    for(int i=n;~i;--i)
    {
        ans+=max(tmp-a[i-1],1LL);
        tmp=min(a[i-1],tmp-1LL);
    }
    cout<<1+accumulate(a.begin(),a.end(),0LL)-ans;
}
signed main()
{
    sol();
    return 0;
}