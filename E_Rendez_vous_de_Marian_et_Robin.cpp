#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e17
vector<int>Dijkstra(int start,int h,vector<bool>& Horse,vector<vector<array<int,2>>>& adj,vector<int> DpDistance)
{
    priority_queue<array<int,2>,vector<array<int,2>>,function<bool(array<int,2>,array<int,2>)>>pq([&]
    (array<int,2>a,array<int,2>b)->bool
    {
        return a[1]>b[1]?true:false;
    });
    int n=adj.size()-1;
    vector<int>NdpDistance(n+1,INF);
    if(h)
    {
        for(int i=1;i<=n;++i)
        {
            if(Horse[i])
            {
                pq.push(array<int,2>{i,DpDistance[i]});
                NdpDistance[i]=DpDistance[i];
            }
        }
    }
    else
    {
        pq.push(array<int,2>{start,0});
        NdpDistance[start]=0;
    }
    while(!pq.empty())
    {
        array<int,2>top_element=pq.top();
        pq.pop();
        int Node=top_element[0],dir=top_element[1];
        if(NdpDistance[Node]<dir)continue;
        for(const array<int,2>&nbg:adj[Node])
        {
            int v=nbg[0],w=nbg[1];
            if(h)
            {
                if(NdpDistance[v]>NdpDistance[Node]+w/2)
                {
                    NdpDistance[v]=NdpDistance[Node]+w/2;
                    pq.push(array<int,2>{v,NdpDistance[v]});
                }
            }
            else
            {
                if(NdpDistance[v]>NdpDistance[Node]+w)
                {
                    NdpDistance[v]=NdpDistance[Node]+w;
                    pq.push(array<int,2>{v,NdpDistance[v]});
                }
            }
        }
    }
    return NdpDistance;
}
void sol()
{
    int n,m,h;
    cin>>n>>m>>h;
    vector<vector<array<int,2>>>adj(n+1);
    vector<bool>Horse(n+1);
    for(int i=0;i<h;++i)
    {
        int x;
        cin>>x;
        Horse[x]=true;
    }
    for(int i=0;i<m;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].emplace_back(array<int,2>{v,w});
        adj[v].emplace_back(array<int,2>{u,w});
    }
    vector<int>Distance_Init=Dijkstra(1,false,Horse,adj,vector<int>(n+1,INF));
    vector<int>Distance_Final=Dijkstra(n,false,Horse,adj,vector<int>(n+1,INF));
    vector<int>Horse_Init=Dijkstra(n,true,Horse,adj,Distance_Init);
    vector<int>Horse_Final=Dijkstra(1,true,Horse,adj,Distance_Final);

    int ans=min(Horse_Init[n],Distance_Init[n]);
    for(int i=1;i<n;++i)
    {
        ans=min(ans,max(min(Distance_Init[i],Horse_Init[i]),min(Distance_Final[i],Horse_Final[i])));
    }
    if(INF<=ans)ans=-1;
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