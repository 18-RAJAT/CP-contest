#include<bits/stdc++.h>
using namespace std;
#define int long long

int find(int i,int n,vector<pair<int,int>>&vp)
{
    for(auto& it:vp)
    {
        if(i>=it.first && i<=it.second)
        {
            return 0;
        }
    }
    return 1;
}

void sol()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>vp(n);
    for(auto &it:vp)
    {
        cin>>it.first>>it.second;
    }
    vector<int>ans;
    for(int i=1;i<=m;i++)
    {
        if(find(i,n,vp))
        {
            ans.emplace_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(auto &it:ans)
    {
        cout<<it<<" ";
    }
}
signed main()
{
    sol();
    return 0;
}