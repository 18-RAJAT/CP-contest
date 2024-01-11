#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=2e18+5;
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adjacent[n];
    for(int i=0;i<m;++i)
    {
        int source,destination,weight;
        cin>>source>>destination>>weight;
        source--;
        destination--;
        adjacent[source].push_back({destination,weight});
        adjacent[destination].push_back({source,weight});
    }
    vector<int>bike(n);
    for(int i=0;i<n;++i)
    {
        cin>>bike[i];
    }
    vector<vector<int>>path_distance(n,vector<int>(n,INF));
    path_distance[0][0]=0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
    pq.push({0,{0,0}});//{distance,{vertex,bike}}
    while(!pq.empty())
    {
        int connected_node=pq.top().second.first;
        int current_bike_available=pq.top().second.second;
        int cost_till_now=pq.top().first;
        pq.pop();
        for(auto& it:adjacent[connected_node])
        {
            if(path_distance[it.first][current_bike_available]>cost_till_now+it.second*bike[current_bike_available])
            {
                //if the cost to reach the node it.first with current_bike_available bikes is greater than the cost to reach the node connected_node with current_bike_available bikes + the cost to reach the node it.first with current_bike_available bikes
                path_distance[it.first][current_bike_available]=cost_till_now+it.second*bike[current_bike_available];
                
                //find the minimum cost to reach the node it.first with current_bike_available bikes
                pq.push({path_distance[it.first][current_bike_available],{it.first,it.first}});
                
                //find the minimum cost to reach the node it.first with current_bike_available bikes
                pq.push({path_distance[it.first][current_bike_available],{it.first,current_bike_available}});
            }
        }
    }
    int ans=INF;
    for(auto& it:path_distance[n-1])
    {
        ans=min<int>(ans,it);
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