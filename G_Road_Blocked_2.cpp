#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>>adj(n+1);
    struct it
    {
        int track2,v,c;
    };
    vector<it> edges(m);
    for(int i=0;i<m;++i)
    {
        cin>>edges[i].track2>>edges[i].v>>edges[i].c;
        adj[edges[i].track2].emplace_back(edges[i].v,edges[i].c);
        adj[edges[i].v].emplace_back(edges[i].track2,edges[i].c);
    }
    vector<int>initial(n+1,1e18),count_init(n+1,0);
    initial[1]=0,count_init[1]=1;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>first_pq;
    first_pq.emplace(0,1);
    while(!first_pq.empty())
    {
        int track1=first_pq.top().first;
        int track2=first_pq.top().second;
        first_pq.pop();
        if(track1>initial[track2])continue;
        for(auto& it:adj[track2])
        {
            int x=it.first,y=it.second;
            if(initial[x]>track1+y)
            {
                initial[x]=track1+y;
                count_init[x]=count_init[track2];
                first_pq.emplace(initial[x],x);
            }
            else if(initial[x]==track1+y)
            {
                count_init[x]+=count_init[track2];
            }
        }
    }
    vector<int>final(n+1,1e18),count_final(n+1,0);
    final[n]=0,count_final[n]=1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> last_pq;
    last_pq.emplace(0,n);
    while(!last_pq.empty())
    {
        int track1=last_pq.top().first;
        int track2=last_pq.top().second;
        last_pq.pop();
        if(track1>final[track2])continue;
        for(auto& it:adj[track2])
        {
            int x=it.first,y=it.second;
            if(final[x]>track1+y)
            {
                final[x]=track1+y;
                count_final[x]=count_final[track2];
                last_pq.emplace(final[x],x);
            }
            else if(final[x]==track1+y)
            {
                count_final[x]+=count_final[track2];
            }
        }
    }
    int temp=count_init[n];
    for(int i=0;i<m;++i)
    {
        int track2=edges[i].track2;
        int v=edges[i].v,c=edges[i].c;
        bool flag1=(initial[track2]+c+final[v]==initial[n]),flag2=(initial[v]+c+final[track2]==initial[n]);
        if(!flag1 && !flag2)
        {
            cout<<"No"<<endl;
            continue;
        }
        int ans=0;
        if(flag1)
        {
            ans+=count_init[track2]*count_final[v];
        }
        if(flag2)
        {
            ans+=count_init[v]*count_final[track2];
        }
        cout<<(ans==temp?"Yes":"No")<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}