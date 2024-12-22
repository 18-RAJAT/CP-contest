#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto &x:a)cin>>x;
    vector<int>b(n);
    for(auto &x:b)cin>>x;
    int ans=0;
    for(int i=0;i<n-1;++i)
    {
        int c=a[i]-b[i+1];
        if(c>0)ans+=c;
    }
    ans+=a[n-1];
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