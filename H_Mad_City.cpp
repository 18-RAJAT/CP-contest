#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
vector<int>graph[N];
int color[N],parent[N];
vector<vector<int>>cycle;
void sol()
{
    auto recur=[&](int n)->void
    {
        n++;
        cycle.clear();
        for(int i=0;i<n;++i)
        {
            graph[i].clear();
            color[i]=0;
            parent[i]=0;
        }
    };
    function<void(int,int,int&)>dfs=[&](int src,int dest,int check_cycle)->void
    {
        if(color[src]==2)
        {
            return;
        }
        if(color[src]==1)
        {
            vector<int>take;
            check_cycle+=1;
            int tmp=dest;
            take.emplace_back(tmp);

            while(tmp!=src)
            {
                tmp=parent[tmp];
                take.emplace_back(tmp);
            }
            cycle.emplace_back(take);
            return;
        }
        parent[src]=dest;
        color[src]=1;
        for(auto& it:graph[src])
        {
            if(it==parent[src])
            {
                continue;
            }
            dfs(it,src,check_cycle);
        }
        color[src]=2;
    };
    auto add=[&](int u,int v)->void
    {
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    };
    function<vector<int>(int,int)>bfs=[&](int source,int n)->vector<int>
    {
        vector<int>dist(n+1,INT_MAX);
        dist[source]=0;
        queue<pair<int,int>>q;
        q.push(make_pair(source,-1));
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto& it:graph[node])
            {
                if(it==parent)
                {
                    continue;
                }
                if(dist[it]>dist[node]+1)
                {
                    dist[it]=dist[node]+1;
                    q.push(make_pair(dist[it],it));
                }
            }
        }
        return dist;
    };
    int n,a,b;
    cin>>n>>a>>b;
    recur(n);
    for(int i=0;i<n-1;++i)
    {
        int u,v;
        cin>>u>>v;
        add(u,v);
    }
    int check_cycle=0;
    dfs(1,0,check_cycle);
    vector<int>path1=bfs(a,n);
    vector<int>path2=bfs(b,n);
    int done=0;
    for(auto& it:cycle)
    {
        for(auto& it2:it)
        {
            if(path1[it2]>path2[it2])
            {
                // done=max(done,path2[it2]);
                done=1;
            }
        }
    }
    cout<<((done)?"YES":"NO")<<endl;
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