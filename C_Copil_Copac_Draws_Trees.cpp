#include<bits/stdc++.h>
using namespace std;

void sol()
{
    int n;
        cin>>n;
        // vector<vector<int>>adj(n);
        vector<pair<int,int>>adj[n];
        int init=-1;
        for(int i=0;i<n-1;++i)
        {
            int src,dest;
            cin>>src>>dest;
            src--;
            dest--;
            //check
            if(src==0 or dest==0)
            {
                if(init==-1)
                {
                    init=i;
                }
            }
            adj[src].push_back(make_pair(dest,i));
            adj[dest].push_back(make_pair(src,i));
            // sort(adj[src].begin(),adj[src].end());
        }
        vector<int>visited(n);
        queue<int>que;
        vector<int>dist(n),checkLevel(n);
        int current=1;
        que.push(0);
        dist[0]=1;
        checkLevel[0]=init;

        while(que.size())
        {
            int connectedNodes=que.front();
            que.pop();

            for(auto it:adj[connectedNodes])
            {
                if(visited[it.first]==0)
                {
                    if(checkLevel[connectedNodes]<=it.second)
                    {
                        que.push(it.first);
                        checkLevel[it.first]=it.second;
                        dist[it.first]=dist[connectedNodes];
                    }
                    else
                    {
                        // chk
                        que.push(it.first);
                        checkLevel[it.first]=it.second;
                        dist[it.first]=dist[connectedNodes]+1;
                    }
                    visited[it.first]=1;
                }
            }
        }
        // for(int i=0;i<n;++i)
        // {
        //     cout<<dist[i]<<" ";
        // }
        // cout<<"\n";
        cout<<*max_element(dist.begin(),dist.end())<<"\n";
}
int main()
{
    int t=1;
    cin>>t;
    while(t-->0)
    {
        sol();
    }
}