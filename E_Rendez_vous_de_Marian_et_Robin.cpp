#include<bits/stdc++.h>
using namespace std;
#define int long long

/*
    Solve this problem using Dijkstra: O((E+V)logV) where (E<<V^2)
    Similarly Floyd-WarShall: O(V^3) where (E≈V^2)
*/
void sol()
{
    int n,m,h;
    cin>>n>>m>>h;
    vector<vector<int>>graph(n,vector<int>(n,1000000007));
    vector<int>Horse(n,0);
    int Vertex;
    for(int i=0;i<h;++i)
    {
        cin>>Vertex;
        Horse[Vertex-1]=1;
    }
    for(int i=0;i<m;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u-1][v-1]=graph[v-1][u-1]=w;
    }
    vector<vector<int>>DpDistance(n,vector<int>(n,1000000007));
    vector<int>Source(n,1000000007),Destination(n,1000000007);
    for(int i=0;i<n;++i)
    {
        DpDistance[i][i]=0;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(graph[i][j]!=1000000007)
            {
                DpDistance[i][j]=graph[i][j];
            }
        }
    }
    auto FloydWarShall=[&]()->void
    {
        for(int k=0;k<n;++k)
        {
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<n;++j)
                {
                    DpDistance[i][j]=min(DpDistance[i][j],DpDistance[i][k]+DpDistance[k][j]);
                }
            }
        }
    };
    FloydWarShall();
    int ans=DpDistance[0][n-1];
    for(int i=0;i<n;++i)
    {
        Source[i]=DpDistance[0][i];
        Destination[i]=DpDistance[n-1][i];
    }
    for(int i=0;i<n;++i)
    {
        if(Horse[i])
        {
            for(int j=0;j<n;++j)
            {
                Source[j]=min(DpDistance[0][i]+DpDistance[i][j]/2,Source[j]);
                Destination[j]=min(DpDistance[n-1][i]+DpDistance[i][j]/2,Destination[j]);
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        ans=min(ans,max(Source[i],Destination[i]));
    }
    if(50000005<=ans)
    {
        cout<<-1<<endl;
        return;
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