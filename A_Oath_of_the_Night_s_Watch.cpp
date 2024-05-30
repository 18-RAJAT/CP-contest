#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto&i:a)cin>>i;
    int ans=0;
    sort(a.begin(),a.end());
    for(int i=0;i<n;++i)if(a[0]<a[i] && a[i]<a.back())ans++;
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}