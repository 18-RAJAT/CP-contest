#include<bits/stdc++.h>
using namespace std;
#define int long long
class DSU
{
    public:
    vector<int>parent;
    DSU(int n)
    {
        parent.resize(n);
        for(int i=0;i<n;++i)
        {
            parent[i]=i;
        }
    }
    int find_set(int x)
    {
        if(parent[x]==x)
        {
            return x;
        }
        return parent[x]=find_set(parent[x]);
    }
    void union_set(int u,int v)
    {
        parent[find_set(u)]=find_set(v);
    }
};
class recur
{
    public:
    recur(){}
    int solve(int n,int m,vector<pair<int,int>>&edges)
    {
        DSU dsu(n);
        set<int>seen;
        set<string>used;
        int last=-1,ans=0;
        for(int i=0;i<m;++i)
        {
            int u=edges[i].first;
            int v=edges[i].second;
            u--,v--;
            dsu.union_set(u,v);
        }
        for(int i=0;i<n;++i)
        {
            int root=dsu.find_set(i);//find the root of the current node
            int mx=max(root,last);
            int mn=min(root,last);

            bool check=root!=last?true:false;

            auto convert=[&](int x)->string
            {
                return to_string(x);
            };

            if(check && seen.count(root) && used.insert(convert(mn)+" "+convert(mx)).second)
            {
                ans++;
            }
            else if(check || seen.count(root)==0)
            {
                last--;
            }
            seen.insert(root);
            // cout<<seen.size()<<endl;
            last=root;
        }
        return ans;
    }
};

void sol()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>edges(m);
    for(int i=0;i<m;++i)
    {
        cin>>edges[i].first>>edges[i].second;
    }
    recur ANS;
    int ans=ANS.solve(n,m,edges);
    cout<<ans<<endl;
}

signed main()
{
    sol();   
    return 0;
}