#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a.begin(),a.end());
    int ans=0;
    for(int i=0;i<n;++i)
    {
        ans+=abs(a[i]-i-1);
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}