#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    bool ok=true;
    for(int i=0;i<n;++i)
    {
        int gap=2*max(i,n-1-i);
        if(a[i]<=gap)
        {
            ok=false;
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