#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    map<array<int,2>,int>va;
    vector<array<int,2>>deg(n);
    for(int i=0;i<n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        deg[u][0]++,deg[u][1]=u;
        deg[v][0]++,deg[v][1]=v;
        va[{u,v}]++,va[{v,u}]++;
    }
    sort(deg.rbegin(),deg.rend());
    int ans=0;
    int mn=min<int>(n,50);
    for(int i=0;i<mn;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            int X=deg[i][1],Y=deg[j][1];
            if(va.find({X,Y})==va.end())ans=max(ans,deg[i][0]+deg[j][0]-1);
            else ans=max(ans,deg[i][0]+deg[j][0]-2);
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