#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Inf=1e18;
void sol()
{
    int n,m,q;
    cin>>n>>m>>q;
    struct Distance
    {
        int x,y,z;
    };
    vector<Distance>roads(m+1);
    vector<vector<int>>dist(n+1,vector<int>(n+1,Inf));
    for(int i=1;i<=n;++i)dist[i][i]=0;
    for(int i=1;i<=m;++i)
    {
        cin>>roads[i].x>>roads[i].y>>roads[i].z;
        dist[roads[i].x][roads[i].y]=min(dist[roads[i].x][roads[i].y],roads[i].z);
        dist[roads[i].y][roads[i].x]=min(dist[roads[i].y][roads[i].x],roads[i].z);
    }
    struct Query
    {
        int one,two,three;
    };
    vector<Query>query(q);
    vector<bool>block(m+1,false);
    for(int i=0;i<q;++i)
    {
        int one;
        cin>>one;
        if(one==1)
        {
            int value;
            cin>>value;
            query[i]=Query{1,value,-1};
            block[value]=true;
        }
        else
        {
            int x,y;
            cin>>x>>y;
            query[i]=Query{2,x,y};
        }
    }
    for(int i=1;i<=m;++i)
    {
        if(block[i])
        {
            dist[roads[i].x][roads[i].y]=Inf;
            dist[roads[i].y][roads[i].x]=Inf;
        }
    }
    auto FloydWarShall=[&]()->void
    {
        for(int k=1;k<=n;++k)
        {
            for(int i=1;i<=n;++i)
            {
                if(dist[i][k]==Inf)continue;
                for(int j=1;j<=n;++j)
                {
                    if(dist[k][j]==Inf)continue;
                    if(dist[i][j]>dist[i][k]+dist[k][j])dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    };
    FloydWarShall();
    vector<string>DistCover;
    // for(int i=1;i<=n;++i)
    // {
    //     for(int j=1;j<=n;++j)cout<<dist[i][j]<<" \n"[j==n];
    // }
    for(int i=q-1;~i;--i)
    {
        if(query[i].one==2)
        {
            int x=query[i].two,y=query[i].three;
            if(dist[x][y]<Inf)
            {
                DistCover.push_back(to_string(dist[x][y]));
            }
            else
            {
                DistCover.push_back("-1");
            }
            // assert(DistCover.size()==q-i);
        }
        else
        {
            int value=query[i].two;
            int x=roads[value].x,y=roads[value].y,z=roads[value].z;
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    if(dist[i][x]<Inf && dist[y][j]<Inf)
                    {
                        auto& D=dist[i][j];
                        if(D>dist[i][x]+z+dist[y][j])D=dist[i][x]+z+dist[y][j];
                    }
                    if(dist[i][y]<Inf && dist[x][j]<Inf)
                    {
                        auto& D=dist[i][j];
                        if(D>dist[i][y]+z+dist[x][j])D=dist[i][y]+z+dist[x][j];
                    }
                }
            }
        }
    }
    // reverse(DistCover.begin(),DistCover.end());
    for(int i=DistCover.size()-1;~i;--i)
    {
        cout<<DistCover[i]<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}