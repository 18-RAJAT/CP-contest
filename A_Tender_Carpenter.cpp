#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int ok=0;
    for(int i=0;i<n-1;++i)
    {
        int L=min(a[i],a[i+1]),R=max(a[i],a[i+1]);
        if(R<2LL*L)
        {
            ok=1;
            break;
        }
    }
    cout<<(ok?"YES":"NO")<<endl;
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