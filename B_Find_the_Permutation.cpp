#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<string>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    vector<vector<int>>g(n+1);
    for(int u=1;u<=n;++u)
    {
        for(int v=u+1;v<=n;++v)
        {
            if(a[u-1][v-1]=='1')g[u].push_back(v);
            else g[v].push_back(u);
        }
    }
    vector<int>d(n+1,0);
    for(int u=1;u<=n;++u)
    {
        for(auto& v:g[u])d[v]++;
    }
    queue<int>q;
    for(int u=1;u<=n;++u)if(d[u]==0)q.push(u);
    vector<int>p;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        p.push_back(u);
        for(auto& it:g[u])
        {
            d[it]--;
            if(d[it]==0)q.push(it);
        }
    }
    for(int i=0;i<p.size();++i)cout<<p[i]<<(i!=p.size()-1?" ":"\n");
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