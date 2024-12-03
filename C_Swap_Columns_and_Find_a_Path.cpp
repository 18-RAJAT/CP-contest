#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a1(n),a2(n);
    for(auto&x:a1)cin>>x;
    for(auto&x:a2)cin>>x;
    int mx=0,mn=LLONG_MIN;
    for(int i=0;i<n;++i)
    {
        mx+=max(a1[i],a2[i]);
        mn=max(mn,min(a1[i],a2[i]));
    }
    cout<<mx+mn<<endl;
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