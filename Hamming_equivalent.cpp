#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(auto& it:a)cin>>it;
    b=a;
    sort(b.begin(),b.end());
    bool ok=1;
    for(int i=0;i<n && ok;++i)
    {
        if(__builtin_popcount(a[i])!=__builtin_popcount(b[i]))ok=0;
    }
    cout<<(ok?"Yes":"No")<<endl;
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