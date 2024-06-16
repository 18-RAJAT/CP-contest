#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto& it:a)cin>>it;
    int ans=a[n-1],maxi=0;
    // sort(a.begin(),a.end());
    for(int i=0;i<n-1;++i)
    {
        maxi=max(maxi,a [i]);
    }
    ans+=maxi;
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