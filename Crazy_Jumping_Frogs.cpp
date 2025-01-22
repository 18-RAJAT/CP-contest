#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,ec=0,oc=0;
    cin>>n;
    vector<int>f(n);
    for(int i=0;i<n;++i)
    {
        cin>>f[i];
        (f[i]&1)?oc++:ec++;
    }
    cout<<max(ec,oc)<<endl;
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