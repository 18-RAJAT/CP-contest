#include<bits/stdc++.h>
using namespace std;

//Rajat joshi template
struct Edge
{
    int to,en,pos;
};
struct Robo
{
    vector<vector<Edge>>Adj;
    vector<int>Lvl,it;
    Robo(int n)
    {
        Adj.assign(n,{});
        Lvl.assign(n,-1);
        it.assign(n,0);
    }
    void AddEdges(int u,int v,int c)
    {
        Edge fwd{v,(int)Adj[v].size(),c};
        Edge en{u,(int)Adj[u].size(),0};
        Adj[u].push_back(fwd);
        Adj[v].push_back(en);
    }
    bool bfs(int s,int t)
    {
        fill(Lvl.begin(),Lvl.end(),-1);
        Lvl[s]=0;
        queue<int>q;
        q.push(s);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto& it:Adj[u])
            {
                if(Lvl[it.to]==-1 && it.pos>=1)
                {
                    Lvl[it.to]=Lvl[u]+1;
                    q.push(it.to);
                }
            }
        }
        return ~Lvl[t];
    }
    int goal(int u,int t,int f)
    {
        if(!f)return 0;
        if(u==t)return f;
        for(int& i=it[u];i<(int)Adj[u].size();++i)
        {
            auto& e=Adj[u][i];
            if(Lvl[e.to]!=Lvl[u]+1 || e.pos<=0)continue;
            int ret=goal(e.to,t,min(f,e.pos));
            if(ret)
            {
                e.pos-=ret;
                Adj[e.to][e.en].pos+=ret;
                return ret;
            }
        }
        return 0;
    }
    int flow(int s,int t)
    {
        int tot=0;
        while(bfs(s,t))
        {
            fill(it.begin(),it.end(),0);
            while(int ret=goal(s,t,INT_MAX))tot+=ret;
        }
        return tot;
    }
};
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<string>grid(n);
        for(int i=0;i<n;++i)cin>>grid[i];
        const int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        auto idx=[&](int r,int c){return r*m+c;};
        vector<int>init(n*m,-1),reach(n*m,-1);
        auto bfs=[&](int sr,int sc,vector<int>& dist)
        {
            fill(dist.begin(),dist.end(),-1);
            queue<int>q;
            dist[idx(sr,sc)]=0;
            q.push(idx(sr,sc));
            while(!q.empty())
            {
                int id=q.front(),r=id/m,c=id%m;
                q.pop();
                for(auto& d:dir)
                {
                    int rr=r+d[0],cc=c+d[1];
                    if(rr<0 || rr>=n || cc<0 || cc>=m || grid[rr][cc]=='#')continue;
                    int ret=idx(rr,cc);
                    if(dist[ret]==-1)
                    {
                        dist[ret]=dist[id]+1;
                        q.push(ret);
                    }
                }
            }
        };
        bfs(0,0,init);
        bfs(n-1,m-1,reach);
        int dist=init[idx(n-1,m-1)];
        if(dist==-1)
        {
            cout<<-1<<endl;
            continue;
        }
        vector<bool>In(n*m,false);
        for(int r=0;r<n;++r)
        {
            for(int c=0;c<m;++c)
            {
                if(init[idx(r,c)]+reach[idx(r,c)]==dist)In[idx(r,c)]=true;
            }
        }
        vector<int>Out(n*m,-1),Moves(n*m,-1);
        int Bct=0,Wct=0;
        for(int r=0;r<n;++r)
        {
            for(int c=0;c<m;++c)
            {
                if(!In[idx(r,c)])continue;
                ((r+c)%2==0)?Out[idx(r,c)]=Bct++:Moves[idx(r,c)]=Wct++;
            }
        }
        Robo Rb(Bct+Wct+2);
        int src=Bct+Wct,nxt=src+1;
        auto Cell=[&](int r,int c){return (r==0 && c==0) || (r==n-1 && c==m-1)?2:1;};
        for(int r=0;r<n;++r)
        {
            for(int c=0;c<m;++c)
            {
                if(!In[idx(r,c)])continue;
                int pos=Cell(r,c);
                if((r+c)%2==0)Rb.AddEdges(src,Out[idx(r,c)],pos);
                else Rb.AddEdges(Moves[idx(r,c)]+Bct,nxt,pos);
            }
        }
        for(int r=0;r<n;++r)
        {
            for(int c=0;c<m;++c)
            {
                if(!In[idx(r,c)] || (r+c)%2!=0)continue;
                int b=Out[idx(r,c)];
                for(auto& d:dir)
                {
                    int rr=r+d[0],cc=c+d[1];
                    if(rr<0 || rr>=n || cc<0 || cc>=m || !In[idx(rr,cc)])continue;
                    int w=Moves[idx(rr,cc)]+Bct;
                    Rb.AddEdges(b,w,1);
                }
            }
        }
        int flow=Rb.flow(src,nxt);
        if(flow>=2)
        {
            cout<<dist<<endl;
            continue;
        }
        vector<vector<int>>As(n*m);
        for(int r=0;r<n;++r)
        {
            for(int c=0;c<m;++c)
            {
                if(!In[idx(r,c)])continue;
                for(auto& d:dir)
                {
                    int rr=r+d[0],cc=c+d[1];
                    if(rr<0 || rr>=n || cc<0 || cc>=m || !In[idx(rr,cc)])continue;
                    As[idx(r,c)].push_back(idx(rr,cc));
                }
            }
        }
        vector<bool>visited(n*m,false);
        bool flag=false;
        function<void(int,int)>dfs=[&](int u,int par)
        {
            visited[u]=true;
            for(auto& v:As[u])
            {
                if(v==par)continue;
                if(visited[v])flag=true;
                else dfs(v,u);
            }
        };
        for(int i=0;i<n*m && !flag;++i)
        {
            if(In[i] && !visited[i])dfs(i,-1);
        }
        cout<<(flag?dist+2:-1)<<endl;
    }
    return 0;
}