#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto& it:a)cin>>it;
    vector<int>b(n-1);
    int ans=0;
    for(int i=2;i<n;++i)
    {
        if(__gcd(a[i],a[i-1])<__gcd(a[i-1],a[i-2]))ans=i-1;
    }
    function<int(int)>recur=[&](int p)->int
    {
        vector<int>ar;
        for(int i=0;i<n;++i)
        {
            if(i!=p)ar.push_back(a[i]);
        }
        for(int i=2;i<ar.size();++i)
        {
            if(__gcd(ar[i],ar[i-1])<__gcd(ar[i-1],ar[i-2]))return 0;
        }
        return 1;
    };
    int ok=0;
    ok|=recur(ans);
    ok|=recur(ans+1);
    ok|=recur(ans-1);
    ok|=recur(ans+2);
    ok|=recur(ans-2);
    cout<<((ok)?"YES":"NO")<<endl;
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