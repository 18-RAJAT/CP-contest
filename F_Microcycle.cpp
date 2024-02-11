#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    set<pair<int,int>>path;
    vector<array<int,3>>edges(m);
    for(int i=0;i<m;++i)
    {
        int source,destination,weight;
        cin>>source>>destination>>weight;
        if(source>destination)
        {
            swap(source,destination);
        }
        edges[i]={source,destination,weight};
        path.insert(make_pair(source,destination));

        adj[source].push_back(destination);
        adj[destination].push_back(source);
    }
    vector<int>visited(n+1,0),par(n+1,-1),dist(n+1,0);
    int cycle=1;
    function<void(int,int)>bridge_finder=[&](int node,int parent)->void
    {
        visited[node]=1;
        par[node]=dist[node]=cycle++;

        for(auto& child:adj[node])
        {
            if(child!=parent)
            {
                if(visited[child])
                {
                    // dist[node]=min(dist[node],par[child]);
                    dist[node]=dist[child];
                }
                else
                {
                    bridge_finder(child,node);
                    // dist[node]=min(dist[node],dist[child]);
                    dist[node]=par[child];
                    if(dist[child]>par[node])
                    {
                        // cout<<"Bridge: \n";
                        // if(path.find(make_pair(node,child))!=path.end())
                        // {
                        //     cout<<node<<" "<<child<<endl;
                        // }
                        // else
                        // {
                        //     cout<<child<<" "<<node<<endl;
                        // }
                        int minimum_of_node_and_child=min(node,child);
                        int maximum_of_node_and_child=max(node,child);
                        path.erase(make_pair(minimum_of_node_and_child,maximum_of_node_and_child));
                    }
                }
            
            }
        }
    };
    for(auto nodes=1;nodes<=n;++nodes)
    {
        if(!visited[nodes])
        {
            bridge_finder(nodes,0);
        }
    }
        int source=-1,destination=-1,weight=1e18;
        for(int i=0;i<m;++i)
        {
            int one=edges[i][0];
            int two=edges[i][1];
            int three=edges[i][2];
            if(!path.count({one,two}) && three<weight)//check if the edge is a bridge or not and if it is a bridge then check if the weight of the edge is minimum or not
            {
                // source=one;
                // destination=two;
                // weight=three;
                continue;
            }
            if(three<weight)
            {
                source=one;
                destination=two;
                weight=three;
            }
        }
    vector<int>check;
    visited.assign(n+1,0);
    function<int(int)>path_finder=[&](int node)->int
    {
        if(visited[node])
        {
            return 0;
        }
        visited[node]=1;
        check.push_back(node);
        if(node==destination)
        {
            return 1;
        }
        for(auto& child:adj[node])
        {
            if(node==source && child==destination)
            {
                continue;
            }
            if(path_finder(child))
            {
                return 1;
            }
        }
        check.pop_back();
        return 0;
    };
    path_finder(source);
    cout<<weight<<" "<<check.size()<<endl;
    for(auto& find:check)
    {
        cout<<find<<" ";
    }
    cout<<endl;
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