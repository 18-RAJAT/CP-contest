#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long int n;
    cin>>n;

    long long int k,c;
    cin>>k>>c;

    vector<vector<int>>G(n+1);

    for(int i=1;i<n;++i)
    {
        int source,destination;
        cin>>source>>destination;
        G[source].push_back(destination);
        G[destination].push_back(source);
    }

    auto traversalOfPaths=[&](long long int source)->vector<long long int>
    {
        vector<long long int>distance(n+1,INT_MAX);

        distance[source]=0;
        queue<long long int>BFS;

        BFS.push(source);

        while(not BFS.empty())
        {
            int node=BFS.front();
            BFS.pop();

            for(auto& child:G[node])
            {
                if(distance[child]>distance[node]+1)
                {
                    distance[child]=distance[node]+1;
                    BFS.push(child);
                }
            }
        }
        return distance;
    };
    //s=1
    
    vector<long long int>ROOT=traversalOfPaths(1);
    long long int check=1;
    for(int i=1;i<=n;++i)
    {
        if(ROOT[check]<ROOT[i])
        {
            check=i;
            // cout<<ROOT[i]<<" ";
        }
        else
        {
            check=check;
        }
    }
    auto travelTime=traversalOfPaths(check);
    long long int maxProfit=0;
    for(int i=1;i<=n;++i)
    {
        long long int profit1=travelTime[i]*k-c*ROOT[i];
        long long int profit2=ROOT[i]*k-c*ROOT[i];

        maxProfit=max<long long int>(maxProfit,max<long long int>(profit1,profit2));
        // cout<<profit1<<" "<<profit2<<" ";
    }
    cout<<maxProfit<<"\n";
}

int main()
{
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        sol();
    }
    return 0;
}