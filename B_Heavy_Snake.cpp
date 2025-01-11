#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,d;
    cin>>n>>d;
    vector<pair<int,int>>vp(n);
    for(auto& it:vp)cin>>it.first>>it.second;
    for(int k=1;k<=d;++k)
    {
        int ans=0;
        for(auto& it:vp)
        {
            int F=it.first*(it.second+k);
            ans=max(ans,F);
        }
        cout<<ans<<endl;
    }
}
signed main()
{
    sol(); 
    return 0;
}