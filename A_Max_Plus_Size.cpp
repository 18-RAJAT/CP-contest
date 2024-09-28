#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int ans=0;
    for(int i=0;i<n;++i)
    {
        ans=max(ans,a[i]);
    }
    int ok=0;
    for(int i=0;i<n;++i)
    {
        if(a[i]==ans)
        {
            if(~i&1)ok=1;
        }
    }
    int res=ans+n/2;
    if(ok && n&1)res++;
    cout<<res<<endl;
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