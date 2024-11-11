#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<vector<int>>a(3,vector<int>(n));
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>a[i][j];
            a[i][j]--;
        }
    }
    vector<set<pair<int,int>>>vp(3);
    for(int i=0;i<3;++i)
    {
        vp[i].insert({a[i][0],0});
    }
    vector<int>p(n,-1),q(n,-1);
    for(int i=1;i<n;++i)
    {
        for(int j=0;j<3;++j)
        {
            auto it=vp[j].upper_bound({a[j][i],i});
            if(it!=vp[j].end())
            {
                p[i]=it->second;
                q[i]=j;
            }
        }
        if(~p[i])
        {
            for(int j=0;j<3;++j)
            {
                vp[j].insert({a[j][i],i});
            }
        }
    }
    if(p[n-1]==-1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        vector<pair<int,int>>ans;
        for(int i=n-1;i>0;i=p[i])
        {
            ans.emplace_back(i,q[i]);
        }
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();++i)
        {
            cout<<("qkj"[ans[i].second])<<" "<<ans[i].first+1<<endl;
        }
    }
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