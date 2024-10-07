#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e18+5;
void FloydWarShall(int n,vector<vector<int>>&DpTransition)
{
    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<=n;++i)
        {
            if(DpTransition[i][k]==N)continue;
            for(int j=1;j<=n;++j)
            {
                if(DpTransition[k][j]==N)continue;
                DpTransition[i][j]=min(DpTransition[i][j],max(DpTransition[i][k],DpTransition[k][j]));
            }
        }
    }
}
void init(int &n,int &m,int &p,vector<int>&dist1,vector<vector<int>>&dist2)
{
    cin>>n>>m>>p;
    dist1.resize(p);
    for(vector<int>:: iterator it=dist1.begin();it!=dist1.end();++it)
    {
        cin>>*it;
    }
    dist2.assign(n+1,vector<int>(n+1,N));

    for(int i=1;i<=n;++i)dist2[i][i]=0;
    for(int i=0;i<m;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dist2[u][v]=min(w,dist2[u][v]);
        dist2[v][u]=min(w,dist2[v][u]);
    }
}
vector<vector<int>>recur(int n,int p,vector<int>&dist1,vector<vector<int>>&dist2)
{
    vector<vector<int>>DpDistance(p,vector<int>(n+1,N));
    for(int i=0;i<p;++i)
    {
        for(int j=1;j<=n;++j)
        {
            DpDistance[i][j]=dist2[dist1[i]][j];
        }
    }
    // FloydWarShall(n,DpDistance);
    return DpDistance;
}
void sol()
{
    int n,m,p;
    vector<int>dist1;
    vector<vector<int>>dist2;
    init(n,m,p,dist1,dist2);
    FloydWarShall(n,dist2);
    vector<vector<int>>DpDistance=recur(n,p,dist1,dist2);
    vector<int>Ndp(p,N),connected_server(n+1,0),Latency;
    Latency.reserve(n);
    for(int k=1;k<=n;++k)
    {
        int temp_travel=N,travel=-1;
        for(int j=1;j<=n;++j)
        {
            if(connected_server[j])continue;
            int ways=0;
            for(int i=0;i<p;++i) ways+=min(Ndp[i],DpDistance[i][j]);
            if(ways<temp_travel)temp_travel=ways,travel=j;
        }
        connected_server[travel]=true;
        // vector<vector<int>>:: iterator it=DpDistance.begin();
        // for(;it!=DpDistance.end();++it)
        // {
        //     (*it)[travel]=N;
        // }
        for(int i=0;i<p;++i)
        {
            Ndp[i]=min(Ndp[i],DpDistance[i][travel]);
        }
        int sum=0;
        for(int i=0;i<p;++i)sum+=Ndp[i];
        Latency.push_back(sum);
        for(int i=0;i<p;++i)
        {
            DpDistance[i][travel]=N;
        }
    }
    //check once again for the latency (GO-THROUGH AGAIN)
    vector<int>Latency2(n,0);
    for(int i=0;i<n;++i)
    {
        if(i<Latency.size())Latency2[i]=Latency[i];
    }
    for(int i=0;i<n;++i)
    {
        if(i<Latency2.size())
        {
            cout<<Latency2[i]<<(i<n-1?' ':'\n');
        }
        else
        {
            cout<<0<<(i<n-1?' ':'\n');
        }
    }
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