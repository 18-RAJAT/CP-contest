#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=3e5+5;
vector<int>g[N],d[N];
int ans;
int recur(vector<int>& a,vector<int>& b)
{
    int tot=0,i=0,j=0,na=a.size(),nb=b.size();
    while(i<na && j<nb)
    {
        (a[i]<b[j])?tot+=a[i]*(nb-j),i++:(tot+=b[j]*(na-i),j++);
    }
    return 2*tot-na*nb;
}
void check(vector<int>& a,vector<int>& b)
{
    vector<int>tmp;
    tmp.reserve(a.size()+b.size());
    int i=0,j=0;
    while(i<a.size() && j<b.size())
    {
        if(a[i]<b[j])tmp.push_back(a[i++]);
        else tmp.push_back(b[j++]);
    }
    while(i<a.size())tmp.push_back(a[i++]);
    while(j<b.size())tmp.push_back(b[j++]);
    a=move(tmp);
}
//rajat joshi template
void dfs(int u,int p)
{
    d[u].clear();
    for(auto& it:g[u])
    {
        if(it==p)continue;
        dfs(it,u);
        for(auto& it:d[it])it++;
        if(!d[u].empty() && !d[it].empty())ans+=recur(d[u],d[it]);
        if(d[it].size()>d[u].size())swap(d[u],d[it]);
        check(d[u],d[it]);
    }
    auto LB=lower_bound(d[u].begin(),d[u].end(),0);
    d[u].insert(LB,0);
}

/*
last test->>
N5:
Cs=cs({0},{0,1,2})=3
N4:
Cs=cs({0,1,2,1},{0,1})=10
N2:
Cs=cs({0},{0})=1
Cs({0},{0,1,1,1,2,2})=15 ->>> 1+15=16

tot=3+10+16=29
*/

void sol()
{
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<0<<endl;
        return;
    }
    for(int i=1;i<=n;++i)g[i].clear(),d[i].clear();
    for(int i=0;i<n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans=0;
    dfs(1,-1);
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