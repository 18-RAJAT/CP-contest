#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto&it:a)cin>>it;
    cout<<a.back()<<" ";
    for(int i=0;i<n-1;++i)cout<<a[i]<<" ";cout<<endl;
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