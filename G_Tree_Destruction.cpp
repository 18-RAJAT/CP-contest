#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
vector<vector<int>>adj;
int T[MAXN];
ll ans;
struct Tree
{
    int u,p;
    bool ok;
    ll fm,sm;
};
ll recur(int root,int n)
{
    ans=LLONG_MIN;
    stack<Tree>stk;
    stk.push(Tree{root,-1,false,0,0});
    ll md[MAXN];
    memset(md,0,sizeof(ll)*(n+1));
    while(!stk.empty()) 
    {
        Tree cur=stk.top();stk.pop();
        if(!cur.ok)
        {
            stk.push(Tree{cur.u,cur.p,true,0,0});
            for(auto &v:adj[cur.u])
            {
                if(v!=cur.p)stk.push(Tree{v,cur.u,false,0,0});
            }
        }
        else
        {
            ll res=T[cur.u],f=LLONG_MIN,s=LLONG_MIN;
            for(auto &v:adj[cur.u])
            {
                if(v!=cur.p)
                {
                    if(md[v]>f) s=f,f=md[v];
                    else if(md[v]>s)s=md[v];
                }
            }
            if(f==LLONG_MIN && s==LLONG_MIN)f=0,s=0;
            md[cur.u]=res+(f>=1?f:0);
            // assert(f>=0 && s>=0);
            ll tmp=res;
            if(f>0) tmp=max(tmp,res+f);
            if(f>=1 && s>=1)tmp=max(tmp,res+f+s);
            ans=max(ans,tmp);
        }
    }
    // assert(ans!=LLONG_MIN);
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        adj.assign(n+1,vector<int>());
        for(int i=0;i<n-1;++i)
        {
            int u,v;cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=n;++i)T[i]=adj[i].size()-2;
        ll root=1;
        ll ms=recur(root,n),sm=LLONG_MIN;
        for(int i=1;i<=n;++i)sm=max(sm,(ll)T[i]);
        ms=max(ms,sm);
        ll ans=max(ms+2,(ll)1);
        cout<<ans<<endl;
    }
}