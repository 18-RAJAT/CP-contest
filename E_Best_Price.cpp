#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n),b(n),p;
    for(auto &x:a)cin>>x;
    for(auto &x:b)cin>>x;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(auto& x:a)p.push_back(x);
    for(auto& x:b)p.push_back(x);
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());
    int ans=0;
    for(auto& it:p)
    {
        int LB=lower_bound(a.begin(),a.end(),it)-a.begin();
        int UB=lower_bound(b.begin(),b.end(),it)-b.begin();
        int cnt=LB-UB;
        if(cnt<=k)
        {
            int buy=n-UB,get=it*buy;
            if(ans<get)ans=get;
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