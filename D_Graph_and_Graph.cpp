#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,s1,s2;
    cin>>n>>s1>>s2;
    int m1;
    cin>>m1;
    vector<vector<int>>g1(n+1);
    for(int i=0;i<m1;++i)
    {
        int u,v;
        cin>>u>>v;
        g1[u].push_back(v);
        g1[v].push_back(u);
    }
    int m2;
    cin>>m2;
    vector<vector<int>>g2(n+1);
    for(int i=0;i<m2;++i)
    {
        int u,v;
        cin>>u>>v;
        g2[u].push_back(v);
        g2[v].push_back(u);
    }
    vector<int>in(n+1,0);
    unordered_set<int>s;
    for(int i=1;i<=n;++i)
    {
        s.clear();
        s.insert(g1[i].begin(),g1[i].end());
        for(int j=0;j<g2[i].size();++j)
        {
            if(s.count(g2[i][j]))in[i]++;
        }
    }
    vector<vector<int>>deg(n+1,vector<int>(n+1,LLONG_MAX/4));
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>q;
    deg[s1][s2]=0;
    q.push({0,s1,s2});
    int ans=-1;
    while(!q.empty())
    {
        int x=q.top()[0],y=q.top()[1],z=q.top()[2];
        q.pop();
        if(deg[y][z]<x)continue;
        if(y==z && in[y]>=1)
        {
            ans=x;
            deg[y][z]=LLONG_MAX/4;
            break;
        }
        for(auto& i:g1[y])
        {
            for(auto& j:g2[z])
            {
                int diff=abs(i-j)+x;
                if(diff<deg[i][j])
                {
                    deg[i][j]=diff;
                    assert(~deg[i][j] || i==j);
                    q.push({diff,i,j});
                }
            }
        }
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