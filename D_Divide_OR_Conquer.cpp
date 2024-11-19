#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    vector<pair<int,int>>prev;
    prev.push_back({a[0],1LL});
    for(int i=1;i<n;++i)
    {
        vector<pair<int,int>>temp;
        for(auto& it:prev)
        {
            int x=it.first,y=it.second;
            temp.push_back({x|a[i],y});
            if(a[i]>=x)temp.push_back({a[i],y});
        }
        sort(temp.begin(),temp.end());
        vector<pair<int,int>>merged;
        int cur=-1,cnt=0;
        for(auto& it:temp)
        {
            if(it.first!=cur)
            {
                if(cur!=-1)merged.push_back({cur,cnt});
                cur=it.first;
                cnt=it.second;
            }
            else cnt+=it.second;
        }
        if(cur!=-1)merged.push_back({cur,cnt});
        prev=merged;
    }
    int ans=0;
    for(auto& it:prev)ans=(ans+it.second)%MOD;
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}