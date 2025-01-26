#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int res=0;
    for(int i=0;i<n;++i)res+=a[i];
    int ans=res;
    while(a.size()>=2)
    {
        vector<int>tmp;
        ans=max({ans,a[0]-a.back(),a.back()-a[0]});
        for(int i=0;i<a.size()-1;++i)tmp.push_back(a[i+1]-a[i]);
        a=move(tmp);
    }
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