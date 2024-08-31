#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000005;
int n,Count_Zero,Count_One,Count_Two;
vector<int>Adj[N];
string s;
void sol()
{
    cin>>n;
    Count_Zero=Count_One=Count_Two=0;
    for(int i=1;i<=n;++i)
    {
        Adj[i].clear();
    }
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    function<void(int,int)>Dfs=[&](int u,int v)->void
    {
        int ans=0;
        for(int i=0;i<Adj[u].size();++i)
        {
            if(Adj[u][i]==v)continue;
            Dfs(Adj[u][i],u);
            ans++;
        }
        if(!ans)
        {
            if(s[u]=='0')Count_Zero++;
            else if(s[u]=='1')Count_One++;
            else Count_Two++;
        }
    };
    int ans=0,res=0;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='?')ans++;
    }
    Dfs(1,0);
    int diff=abs(Count_Zero-Count_One);
    if(s[1]=='?')
    {
        ans-=(1+Count_Two);
        res+=diff>=1?max(Count_Zero,Count_One)+Count_Two/2:max(Count_Zero,Count_One)+(ans&1?(Count_Two+1)/2:Count_Two/2);
    }
    else
    {
        if(s[1]=='0')res+=Count_One;
        else res+=Count_Zero;
        res+=(Count_Two+1)/2;
    }
    cout<<res<<endl;
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