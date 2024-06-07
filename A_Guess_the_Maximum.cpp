#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto& it:a)cin>>it;
    int maxi=1e9;
    for(int i=1;i<n;++i)
    {
        maxi=min(maxi,max(a[i-1],a[i]));
    }
    cout<<maxi-1<<endl;
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